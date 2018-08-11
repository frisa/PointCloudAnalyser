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

PCAViewer::PCAViewer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	_log.init(ui.tbLog->document());
	_log.log("Logger initialization -> OK");
	initPclVtk();
	connectActions();
}

void PCAViewer::saveContent()
{
	QImage frameBuffer;
	frameBuffer = ui.openGLWidget->grabFramebuffer();
	frameBuffer.save("e:\\fb.bmp");
}

void PCAViewer::ShowLogo()
{
	auto cylinderSource = vtkSmartPointer<vtkCylinderSource>::New();
	cylinderSource->SetCenter(0.0, 0.0, 0.0);
	cylinderSource->SetRadius(5.0);
	cylinderSource->SetHeight(7.0);
	cylinderSource->SetResolution(100);

	auto mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputConnection(cylinderSource->GetOutputPort());

	auto actor = vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);

	_renderer = vtkSmartPointer<vtkRenderer>::New();
	_renderer->AddActor(actor);
	_renderer->SetBackground(0.0, 1.0, 0.0);

	_window = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	_window->AddRenderer(_renderer);
	ui.openGLWidget->SetRenderWindow(_window.Get());
	_log.log("The defualt cilinder in VTK -> OK");
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
	seg.setDistanceThreshold(0.01);

	seg.setInputCloud(_pointCloud);
	seg.segment(*inliers, *coefficients);

	if (inliers->indices.size() == 0)
	{
		PCL_ERROR("Could not estimate a planar model for the given dataset.");
	}

	for (size_t i = 0; i < inliers->indices.size(); ++i)
	{
		pcl::PointXYZRGB point;
		point.x = _pointCloud->points[inliers->indices[i]].x;
		point.y = _pointCloud->points[inliers->indices[i]].y;
		point.z = _pointCloud->points[inliers->indices[i]].z;
		point.rgb = 0xff0000;
		_pointCloudRed->push_back(point);
	}
	_pointCloudRedId = "SampleConsensus";
	_pclVisualizer->addPointCloud<pcl::PointXYZRGB>(_pointCloudRed, _pointCloudRedId, 0);
	_pclVisualizer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, _pointCloudRedId);
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
	double g = 40.0 / 255.0;
	double b = 70.0 / 255.0;
	_pclVisualizer->setBackgroundColor(r, g, b);
	ui.openGLWidget->SetRenderWindow(_pclVisualizer->getRenderWindow());

	// Create Default Point Cloud
	//generatePcdFile();
	_pointCloud.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
	_pointCloudId = "defaultCloud";
	ret = _pclVisualizer->addPointCloud<pcl::PointXYZRGB>(_pointCloud, _pointCloudId, 0);
	_pclVisualizer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, _pointCloudId);
	//_pclVisualizer->setupInteractor(ui.openGLWidget->GetInteractor(), ui.openGLWidget->GetRenderWindow());
	//_pclVisualizer->getInteractorStyle()->setKeyboardModifier(pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
	ui.openGLWidget->show();
	ui.openGLWidget->update();

	_log.log("Initialize VTK and PCD -> OK");
}

void PCAViewer::browsePcdFile()
{
	QString dir = QFileDialog::getOpenFileName(this,tr("Open PCD File"), "",tr("PCD Files (*.pcd);;All Files (*)"));
	ui.tbFsdFilesDirectory->setText(dir);
}

void PCAViewer::loadPcdFile()
{
	QString filePath = ui.tbFsdFilesDirectory->toPlainText();
	std::string sFilePath = filePath.toLocal8Bit().constData();
	_log.log("Loading PCD file: " + filePath);
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr newCloud;
	newCloud.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
	_log.log("Loading PCD file it will take longer time");
	this->update();
	if (pcl::io::loadPCDFile<pcl::PointXYZRGB>(sFilePath, *newCloud) == -1)
	{
		_log.log("Couldn't read pcd file: " + filePath);
		this->update();
	}
	else
	{
		_log.log("Loaded PCD file: " + filePath);
		_log.log("cloud_width = " + QString::number(newCloud->width));
		_log.log("cloud_height = " + QString::number(newCloud->height));
		_log.log("cloud_size = " + QString::number(newCloud->size()));
		_log.log("cloud_points = " + QString::number(newCloud->points.size()));
		this->update();
	}
	if (!newCloud->empty())
	{
		if (_pclVisualizer->updatePointCloud(newCloud, sFilePath))
		{
			/* Just update the existing cloud */
		}
		else
		{
			_pointCloud = newCloud;
			_pclVisualizer->addPointCloud<pcl::PointXYZRGB>(_pointCloud, sFilePath, 0);
			_pclVisualizer->removePointCloud(_pointCloudId, 0);
			_pointCloudId = sFilePath;
		}
	}
	_pclVisualizer->resetCamera();
	ui.openGLWidget->update();
}

void PCAViewer::connectActions()
{
	connect(ui.actionLoad_PCD, &QAction::triggered, this, &PCAViewer::loadPcdFile);
	connect(ui.actionGenerate_PCD, &QAction::triggered, this, &PCAViewer::generatePcdFile);
	connect(ui.actionShowLogo, &QAction::triggered, this, &PCAViewer::ShowLogo);
	connect(ui.actionSaveImage, &QAction::triggered, this, &PCAViewer::saveContent);
	connect(ui.actionBrowsePCD, &QAction::triggered, this, &PCAViewer::browsePcdFile);

	connect(ui.actionSampleConsensus, &QAction::triggered, this, &PCAViewer::pclSampleConsensus);
	_log.log("The signal connection -> OK");
}

void PCAViewer::generatePcdFile()
{
	
	for (size_t i = 0; i < 1000; ++i)
	{
		pcl::PointXYZRGB point;
		point.x = 1024 * rand() / (RAND_MAX + 1.0f);
		point.y = 1024 * rand() / (RAND_MAX + 1.0f);
		point.z = 1024 * rand() / (RAND_MAX + 1.0f);
		point.rgb = 0x00ff00;
		_pointCloud->push_back(point);
	}
	_log.log("Default PCD generated -> OK");
	//pcl::io::savePCDFileASCII(ui.tbPcdFilePath->toPlainText().toStdString(), _pointCloud.get());
	//_log.log("Saved: " + QString::number(_pointCloud->points.size()));
}
