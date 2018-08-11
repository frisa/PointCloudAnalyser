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

void PCAViewer::initPclVtk()
{
	bool ret{ true };

	// Setup Rendered
	_renderer = vtkSmartPointer<vtkRenderer>::New();
	_renderer->SetBackground(0.0, 0.0, 1.0);

	// Setup Window
	_window = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	_window->AddRenderer(_renderer);

	// Setup PCL visualizer
	_pclVisualizer.reset(new pcl::visualization::PCLVisualizer(_renderer, _window, "viewer", false));
	_pclVisualizer->resetCamera();
	_pclVisualizer->setBackgroundColor(0.0, 0.0, 0.0);
	ui.openGLWidget->SetRenderWindow(_pclVisualizer->getRenderWindow());
	ui.openGLWidget->update();

	// Create Default Point Cloud
	generatePcdFile();
	ret = _pclVisualizer->addPointCloud<pcl::PointXYZRGB>(_pointCloud, "cloud");
	_pclVisualizer->setupInteractor(ui.openGLWidget->GetInteractor(), ui.openGLWidget->GetRenderWindow());
	_pclVisualizer->getInteractorStyle()->setKeyboardModifier(pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
	ui.openGLWidget->show();
	ui.openGLWidget->update();

	_log.log("Load PCD -> OK");
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
	_pointCloud.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
	if (pcl::io::loadPCDFile<pcl::PointXYZRGB>(sFilePath, *_pointCloud) == -1)
	{
		_log.log("Couldn't read pcd file: " + filePath);
	}
	else
	{
		_log.log("Loaded PCD file: " + filePath);
		_log.log("cloud_width = " + QString::number(_pointCloud->width));
		_log.log("cloud_height = " + QString::number(_pointCloud->height));
		_log.log("cloud_size = " + QString::number(_pointCloud->size()));
		_log.log("cloud_points = " + QString::number(_pointCloud->points.size()));

		for (size_t i = 0; i < _pointCloud->points.size(); ++i)
		{
			_log.log("[" + QString::number(_pointCloud->points[i].x) + "," + QString::number(_pointCloud->points[i].y) + "," + QString::number(_pointCloud->points[i].z) + "]");
		}
	}

	if (_pclVisualizer->updatePointCloud(_pointCloud, "cloud"))
	{
		ui.openGLWidget->update();
	}
}

void PCAViewer::connectActions()
{
	connect(ui.actionLoad_PCD, &QAction::triggered, this, &PCAViewer::loadPcdFile);
	connect(ui.actionGenerate_PCD, &QAction::triggered, this, &PCAViewer::generatePcdFile);
	connect(ui.actionShowLogo, &QAction::triggered, this, &PCAViewer::ShowLogo);
	connect(ui.actionSaveImage, &QAction::triggered, this, &PCAViewer::saveContent);
	connect(ui.actionBrowsePCD, &QAction::triggered, this, &PCAViewer::browsePcdFile);
	_log.log("The signal connection -> OK");
}

void PCAViewer::generatePcdFile()
{
	unsigned int red;
	unsigned int green;
	unsigned int blue;

	// The default color
	red = 255;
	green = 120;
	blue = 120;

	_pointCloud.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
	_pointCloud->points.resize(200);
	for (size_t i = 0; i < _pointCloud->points.size(); ++i)
	{
		_pointCloud->points[i].x = 1024 * rand() / (RAND_MAX + 1.0f);
		_pointCloud->points[i].y = 1024 * rand() / (RAND_MAX + 1.0f);
		_pointCloud->points[i].z = 1024 * rand() / (RAND_MAX + 1.0f);

		_pointCloud->points[i].r = red;
		_pointCloud->points[i].g = green;
		_pointCloud->points[i].b = blue;
	}

	//pcl::io::savePCDFileASCII(ui.tbPcdFilePath->toPlainText().toStdString(), _pointCloud.get());
	_log.log("Saved: " + QString::number(_pointCloud->points.size()));

	for (size_t i = 0; i < _pointCloud->points.size(); ++i)
	{
		_log.log("[" + QString::number(_pointCloud->points[i].x) + "," + QString::number(_pointCloud->points[i].y) + "," + QString::number(_pointCloud->points[i].z) + "]");
	}
}
