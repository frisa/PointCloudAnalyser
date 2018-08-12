#include <QFileDialog>

#include "PCAViewer.h"
#include "vtkRenderer.h"
#include "vtkSphereSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkCylinderSource.h"

#include "boost\smart_ptr\shared_ptr.hpp"
#include "boost\smart_ptr\make_shared_object.hpp"

#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/sample_consensus/sac_model_plane.h>
#include <pcl/sample_consensus/sac_model_line.h>
#include <pcl/sample_consensus/ransac.h>

PCAViewer::PCAViewer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	_log.init(ui.tbLog->document());
	_log.log("Logger initialization -> OK");
	initPclVtk();
	connectActions();
}

void PCAViewer::fileBmpExport()
{
	QString qFilePath = QFileDialog::getSaveFileName(this, tr("Save Cloud To Image"), "", tr("BMP Files (*.bmp);;All Files (*)"));
	QImage frameBuffer;
	frameBuffer = ui.openGLWidget->grabFramebuffer();
	frameBuffer.save(qFilePath);
}

void PCAViewer::pclSACPlaneModel()
{
	_pointCloudRed.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
	std::vector<int> inliers;
	pcl::SampleConsensusModelPlane<pcl::PointXYZRGB>::Ptr model_p(new pcl::SampleConsensusModelPlane<pcl::PointXYZRGB>(_pointCloud));
	model_p->setRadiusLimits(1,10);
	pcl::RandomSampleConsensus<pcl::PointXYZRGB> ransac(model_p);
	ransac.setDistanceThreshold(0.01);
	ransac.computeModel();
	ransac.getInliers(inliers);
	for (size_t i = 0; i < inliers.size(); ++i)
	{
		pcl::PointXYZRGB point;
		point.x = _pointCloud->points[inliers[i]].x;
		point.y = _pointCloud->points[inliers[i]].y;
		point.z = _pointCloud->points[inliers[i]].z;
		uint8_t r(255), g(15), b(15);
		uint32_t rgb = (static_cast<uint32_t>(r) << 16 | static_cast<uint32_t>(g) << 8 | static_cast<uint32_t>(b));
		point.rgb = *reinterpret_cast<float*>(&rgb);
		_pointCloudRed->push_back(point);
	}
	_pclVisualizer->addPointCloud<pcl::PointXYZRGB>(_pointCloudRed, _pointCloudRedId);
	//pcdUpdateRedCloud();


	//_pclVisualizer->addArrow<pcl::PointXYZRGB, pcl::PointXYZRGB>(_pointCloud->points[0], _pointCloud->points[1], 1., 0., 0.);
	//pcl::ModelCoefficients plane_coeff;
	//plane_coeff.values.resize(4);    // We need 4 values x, y, z, w
	//plane_coeff.values[0] = 0.;
	//plane_coeff.values[1] = 0.;
	//plane_coeff.values[2] = 1.;
	//plane_coeff.values[3] = 1.;
	//_pclVisualizer->addPlane(plane_coeff);
}

void PCAViewer::pclSampleConsensus()
{
	_pointCloudRed.reset(new pcl::PointCloud<pcl::PointXYZRGB>);

	pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);
	pcl::PointIndices::Ptr inliers(new pcl::PointIndices);

	// Create the segmentation object
	pcl::SACSegmentation<pcl::PointXYZRGB> seg;
	// Optional
	seg.setOptimizeCoefficients(true);
	// Mandatory
	seg.setModelType(pcl::SACMODEL_PLANE);
	seg.setMethodType(pcl::SAC_RANSAC);
	//seg.setDistanceThreshold(0.1);

	seg.setInputCloud(_pointCloud);
	seg.segment(*inliers, *coefficients);

	for (size_t i = 0; i < inliers->indices.size(); ++i)
	{
		pcl::PointXYZRGB point;
		point.x = _pointCloud->points[inliers->indices[i]].x;
		point.y = _pointCloud->points[inliers->indices[i]].y;
		point.z = _pointCloud->points[inliers->indices[i]].z;
		point.r = 255;
		point.g = 0;
		point.b = 0;
		_pointCloudRed->push_back(point);
	}
	_pclVisualizer->addPointCloud<pcl::PointXYZRGB>(_pointCloudRed, _pointCloudRedId, 0);
	_pclVisualizer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 4, _pointCloudRedId);
}

void PCAViewer::initPclVtk()
{
	bool ret{ true };

	// Setup Rendered
	_renderer = vtkSmartPointer<vtkRenderer>::New();
	_renderer->SetBackground(0.0, 0.0, 0.0);

	// Setup Window
	_window = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	_window->AddRenderer(_renderer);

	// Setup PCL visualizer
	_pclVisualizer.reset(new pcl::visualization::PCLVisualizer(_renderer, _window, "viewer", false));
	_pclVisualizer->resetCamera();
	double r = 0.0;
	double g = 30.0 / 255.0;
	double b = 50.0 / 255.0;
	_pclVisualizer->setBackgroundColor(r, g, b);
	ui.openGLWidget->SetRenderWindow(_pclVisualizer->getRenderWindow());

	// Create Default Point Cloud
	pcdGenDefCloudCube();

	_pclVisualizer->setupInteractor(ui.openGLWidget->GetInteractor(), ui.openGLWidget->GetRenderWindow());
	_pclVisualizer->getInteractorStyle()->setKeyboardModifier(pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
	ui.openGLWidget->show();
	ui.openGLWidget->update();

	_log.log("Initialized VTK and PCD -> OK");
}

void PCAViewer::fileBrowse()
{
	QString dir = QFileDialog::getOpenFileName(this,tr("Open PCD File"), "",tr("PCD Files (*.pcd);;All Files (*)"));
	ui.tbFsdFilesDirectory->setText(dir);
}

void PCAViewer::fileSave()
{
	QString qFilePath = QFileDialog::getSaveFileName(this, tr("Save PCD File"), "", tr("PCD Files (*.pcd);;All Files (*)"));
	std::string filePath(qFilePath.toLocal8Bit().constData());
	pcl::io::savePCDFileASCII(filePath, *_pointCloud);
	_log.log("Saved to: " + qFilePath);
}

void PCAViewer::fileLoad()
{
	QString filePath = ui.tbFsdFilesDirectory->toPlainText();
	std::string sFilePath = filePath.toLocal8Bit().constData();
	_pointCloud.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
	if (pcl::io::loadPCDFile<pcl::PointXYZRGB>(sFilePath, *_pointCloud) == -1)
	{
		_log.log("Couldn't read pcd file: " + filePath);
	}
	else
	{
		_log.log("Loaded PCD file: " + filePath);
	}
	if (!_pointCloud->empty())
	{
		if (_pclVisualizer->updatePointCloud(_pointCloud, sFilePath))
		{
			/* Just update the existing cloud */
		}
		else
		{
			_pclVisualizer->removePointCloud(_pointCloudId, 0);
			_pclVisualizer->addPointCloud<pcl::PointXYZRGB>(_pointCloud, sFilePath, 0);
			_pointCloudId = sFilePath;
		}
	}
	_pclVisualizer->resetCamera();
	ui.openGLWidget->update();
}

void PCAViewer::connectActions()
{
	/* File Operations */
	connect(ui.actionFileBrowse, &QAction::triggered, this, &PCAViewer::fileBrowse);
	connect(ui.actionFileLoad, &QAction::triggered, this, &PCAViewer::fileLoad);
	connect(ui.actionFileSave, &QAction::triggered, this, &PCAViewer::fileSave);
	connect(ui.actionSaveImage, &QAction::triggered, this, &PCAViewer::fileBmpExport);
	connect(ui.actionGenerateCloud, &QAction::triggered, this, &PCAViewer::pcdGenDefCloudCube);

	/* PCL Operations */
	connect(ui.actionPclSampleConsensus, &QAction::triggered, this, &PCAViewer::pclSampleConsensus);
	connect(ui.actionSACPlaneModel, &QAction::triggered, this, &PCAViewer::pclSACPlaneModel);
	_log.log("The signal connection -> OK");
}

void PCAViewer::pcdGenDefCloudCube()
{
	// Work Point Cloud
	_pointCloud.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
	pcl::PointXYZRGB point;

	for (size_t i = 0; i < 1500; ++i)
	{
		point.x = rand() % 20;
		point.y = rand() % 20;
		point.z = rand() % 10;
		point.r = 0;
		point.g = 255;
		point.b = 255;
		_pointCloud->push_back(point);
	}
	_pclVisualizer->addPointCloud<pcl::PointXYZRGB>(_pointCloud, _pointCloudId, 0);
	_pclVisualizer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, _pointCloudId);

	// Red Point Cloud
	_pointCloudRed.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
	pcl::PointXYZRGB pointRed;
	pointRed.x = 0.0;
	pointRed.y = 0.0;
	pointRed.z = 0.0;
	uint8_t r(255), g(15), b(15);
	uint32_t rgb = (static_cast<uint32_t>(r) << 16 |static_cast<uint32_t>(g) << 8 | static_cast<uint32_t>(b));
	pointRed.rgb = *reinterpret_cast<float*>(&rgb);
	_pointCloudRed->points.push_back(pointRed);

	_pclVisualizer->addPointCloud<pcl::PointXYZRGB>(_pointCloudRed, _pointCloudRedId);
	_pclVisualizer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 5, _pointCloudRedId);
	_pclVisualizer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 0xff0000, _pointCloudRedId);
	_pclVisualizer->initCameraParameters();
	_pclVisualizer->resetCamera();
	_pclVisualizer->addCoordinateSystem(15);

	//_pointCloudRed.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
	//point.x = 0;
	//point.y = 0;
	//point.z = 0;
	//point.r = 255;
	//point.g = 0;
	//point.b = 0;
	//_pointCloudRed->push_back(point);
	//if (_pclVisualizer->updatePointCloud(_pointCloudRed, _pointCloudRedId))
	//{
	//	_pclVisualizer->resetCamera();
	//	ui.openGLWidget->update();
	//}
}

void PCAViewer::pcdUpdateRedCloud()
{
	if (!_pointCloudRed->empty())
	{
		if (_pclVisualizer->updatePointCloud(_pointCloudRed, _pointCloudRedId))
		{
			_pclVisualizer->resetCamera();
			ui.openGLWidget->update();
		}
	}
}
