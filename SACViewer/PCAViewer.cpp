#include "PCAViewer.h"
#include "vtkRenderer.h"
#include "vtkSphereSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkCylinderSource.h"
#include "PclPersistor.h"

PCAViewer::PCAViewer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	_log.init(ui.tbLog->document());
	_log.log("Logger initialization -> OK");
	setupVtk();
	connectActions();
}

void PCAViewer::loadPcdFile()
{
	_renderer = vtkSmartPointer<vtkRenderer>::New();
	_window = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	_window->AddRenderer(_renderer);
	_pclVisualizer.reset(new pcl::visualization::PCLVisualizer(_renderer, _window, "viewer", false));
	ui.openGLWidget->SetRenderWindow(_pclVisualizer->getRenderWindow());
	ui.openGLWidget->update();

	
	//ui.openGLWidget->SetRenderWindow(_pclVisualizer->getRenderWindow());
	//_pclVisualizer->setupInteractor(ui.openGLWidget->GetInteractor(), ui.openGLWidget->GetRenderWindow());
	//_pclVisualizer->addPointCloud(_pointCloud, "cloud");
	//_pclVisualizer->resetCamera();
	//ui.openGLWidget->update();

	//PclPersistor pclPers(&_log);

	//pclPers.loadPcdToCloud(ui.tbPcdFilePath->toPlainText(), cloud);
	//_log.log("Load PCD -> OK");

	//_pclVisualizer = new pcl::visualization::PCLVisualizer("view", false);
	//ui.openGLWidget->SetRenderWindow(_pclVisualizer->getRenderWindow());
	//ui.openGLWidget->show();
	//ui.openGLWidget->update();

	//if (!cloud->empty())
	//{
	//	if (!_pclVisualizer->updatePointCloud<pcl::PointXYZ>(cloud, "cloud0")) {
	//		//_pclVisualizer->addPointCloud<pcl::PointXYZ>(cloud, "cloud0");
	//	}
	//	else {
	//		//_pclVisualizer->updatePointCloud<pcl::PointXYZ>(cloud, "cloud0");
	//	}
	//	ui.openGLWidget->update();
	//}
	//else {
	//	std::cerr << "There is nothing to add to the visualizer!" << std::endl;
	//}


}

void PCAViewer::setupVtk()
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
	_renderer->SetBackground(0.27, 0.27, 0.27);
	_renderer->SetBackground2(0.44, 0.44, 0.44);

	_window = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	_window->AddRenderer(_renderer);
	ui.openGLWidget->SetRenderWindow(_window.Get());
	_log.log("The initialization of VTK -> OK");
}

void PCAViewer::connectActions()
{
	connect(ui.actionLoad_PCD, &QAction::triggered, this, &PCAViewer::loadPcdFile);
	connect(ui.actionGenerate_PCD, &QAction::triggered, this, &PCAViewer::generatePcdFile);
	_log.log("The signal connection -> OK");
}

void PCAViewer::generatePcdFile()
{
	unsigned int red;
	unsigned int green;
	unsigned int blue;

	// The default color
	red = 128;
	green = 128;
	blue = 128;

	_pointCloud.reset(new pcl::PointCloud<pcl::PointXYZRGBA>);
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

	//for (size_t i = 0; i < _pointCloud->points.size(); ++i)
	//{
	//	_log.log("[" + QString::number(_pointCloud->points[i].x) + "," + QString::number(_pointCloud->points[i].y) + "," + QString::number(_pointCloud->points[i].z) + "]");
	//}
}
