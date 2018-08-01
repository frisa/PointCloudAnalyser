#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PCAViewer.h"
#include "vtkGenericOpenGLRenderWindow.h"
#include "vtkSmartPointer.h"
#include "Logger.h"
#include  <pcl/visualization/pcl_visualizer.h>

class PCAViewer : public QMainWindow
{
	Q_OBJECT

public:
	PCAViewer(QWidget *parent = Q_NULLPTR);

private:
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> _window;
	vtkSmartPointer<vtkRenderer> _renderer;
	pcl::visualization::PCLVisualizer* _pclVisualizer;
	Logger _log;

	Ui::PCAViewerClass ui;
	void setupVtk();
	void connectActions();

public slots:
	void loadPcdFile();
	void generatePcdFile();
};
