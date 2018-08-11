#include "PCAViewer.h"
#include "vtkRenderer.h"
#include "vtkSphereSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkCylinderSource.h"
#include "PclPersistor.h"

#include "boost\smart_ptr\shared_ptr.hpp"
#include "boost\smart_ptr\make_shared_object.hpp"

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
	ret = _pclVisualizer->addPointCloud<pcl::PointXYZRGBA>(_pointCloud, "cloud");
	_pclVisualizer->setupInteractor(ui.openGLWidget->GetInteractor(), ui.openGLWidget->GetRenderWindow());
	_pclVisualizer->getInteractorStyle()->setKeyboardModifier(pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
	ui.openGLWidget->show();
	ui.openGLWidget->update();

	//PclPersistor pclPers(&_log);
	//pclPers.loadPcdToCloud(ui.tbPcdFilePath->toPlainText(), _pointCloud);
	_log.log("Load PCD -> OK");
}

void PCAViewer::loadPcdFile()
{
	generatePcdFile();
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
	_log.log("The signal connection -> OK");
}

void PCAViewer::generatePcdFile()
{
	unsigned int red;
	unsigned int green;
	unsigned int blue;

	// The default color
	red = rand() % 255;
	green = rand() % 255;
	blue = rand() % 255;

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
