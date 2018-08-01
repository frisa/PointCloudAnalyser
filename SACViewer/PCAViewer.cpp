#include "PCAViewer.h"
#include "vtkRenderer.h"
#include "vtkGenericOpenGLRenderWindow.h"
#include "vtkSphereSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkCylinderSource.h"
#include "PclPersistor.h"

#include <pcl/point_types.h>
#include <pcl/common/projection_matrix.h>
#include <pcl/io/pcd_io.h>

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
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

	pclPers.loadPcdToCloud(ui.tbPcdFilePath->toPlainText(), cloud);
	_log.log("Load PCD -> OK");

	_pclVisualizer = new pcl::visualization::PCLVisualizer("view", false);
	ui.openGLWidget->SetRenderWindow(_pclVisualizer->getRenderWindow());
	ui.openGLWidget->show();
	ui.openGLWidget->update();

	if (!cloud->empty())
	{
		if (!_pclVisualizer->updatePointCloud<pcl::PointXYZ>(cloud, "cloud0")) {
			//_pclVisualizer->addPointCloud<pcl::PointXYZ>(cloud, "cloud0");
		}
		else {
			//_pclVisualizer->updatePointCloud<pcl::PointXYZ>(cloud, "cloud0");
		}
		ui.openGLWidget->update();
	}
	else {
		std::cerr << "There is nothing to add to the visualizer!" << std::endl;
	}


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

	_window = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	_window->AddRenderer(_renderer);
	ui.openGLWidget->SetRenderWindow(_window.Get());
	_log.log("The initialization of VTK -> OK");
}

void PCAViewer::connectActions()
{
	connect(ui.actionLoad_PCD, &QAction::triggered, this, &PCAViewer::loadPcdFile);
	connect(ui.actionGenerate_PCD, &QAction::triggered, this, &PCAViewer::loadPcdFile);
	_log.log("The signal connection -> OK");
}

void PCAViewer::generatePcdFile()
{
	pcl::PointCloud<pcl::PointXYZ> cloud;

	cloud.width = 5;
	cloud.height = 1;
	cloud.is_dense = false;
	cloud.points.resize(cloud.width * cloud.height);

	for (size_t i = 0; i < cloud.points.size(); ++i)
	{
		cloud.points[i].x = 1024 * rand() / (RAND_MAX + 1.0f);
		cloud.points[i].y = 1024 * rand() / (RAND_MAX + 1.0f);
		cloud.points[i].z = 1024 * rand() / (RAND_MAX + 1.0f);
	}

	pcl::io::savePCDFileASCII(ui.tbPcdFilePath->toPlainText().toStdString(), cloud);
	_log.log("Saved: " + QString::number(cloud.points.size()));

	for (size_t i = 0; i < cloud.points.size(); ++i)
	{
		_log.log("[" + QString::number(cloud.points[i].x) + "," + QString::number(cloud.points[i].y) + "," + QString::number(cloud.points[i].z) + "]");
	}
}
