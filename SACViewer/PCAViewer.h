#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PCAViewer.h"
#include <vtkGenericOpenGLRenderWindow.h>
#include "vtkSmartPointer.h"
#include "Logger.h"

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/visualization/pcl_visualizer.h>

class PCAViewer : public QMainWindow
{
	Q_OBJECT

public:
	PCAViewer(QWidget *parent = Q_NULLPTR);

private:
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> _window;
	vtkSmartPointer<vtkRenderer> _renderer;

	boost::shared_ptr<pcl::visualization::PCLVisualizer> _pclVisualizer;
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr _pointCloud;

	Logger _log;

	Ui::PCAViewerClass ui;
	void connectActions();

public slots:
	void saveContent();
	void ShowLogo();
	void initPclVtk();
	void generatePcdFile();
	void loadPcdFile();
};
