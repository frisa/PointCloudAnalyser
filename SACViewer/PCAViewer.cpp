#include "PCAViewer.h"
#include "vtkRenderer.h"
#include "vtkGenericOpenGLRenderWindow.h"
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
	PclPersistor pclPers(&_log);
	pclPers.loadPcdToCloud(ui.tbPcdFilePath->toPlainText());
	_log.log("Load PCD -> OK");
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

	auto renderer = vtkSmartPointer<vtkRenderer>::New();
	renderer->AddActor(actor);

	_window = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	_window->AddRenderer(renderer);
	ui.openGLWidget->SetRenderWindow(_window.Get());
	_log.log("The initialization of VTK -> OK");
}

void PCAViewer::connectActions()
{
	connect(ui.actionLoad_PCD, &QAction::triggered, this, &PCAViewer::loadPcdFile);
	_log.log("The signal connection -> OK");
}
