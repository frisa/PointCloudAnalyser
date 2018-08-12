#pragma once

#include <string>
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
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr _pointCloud;
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr _pointCloudRed;
	std::string _pointCloudId{ "default" };
	std::string _pointCloudRedId{"red"};

	Logger _log;
	Ui::PCAViewerClass ui;
	void connectActions();
	void initPclVtk();

public slots:
	// Point Cloud Operations
	void pcdGenDefCloudCube();
	void pcdUpdateRedCloud();

	// File Operations
	void fileLoad();
	void fileSave();
	void fileBrowse();
	void fileBmpExport();

	void pclSampleConsensus();
	void pclSACPlaneModel();
};
