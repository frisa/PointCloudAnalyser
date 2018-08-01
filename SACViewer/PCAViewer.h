#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PCAViewer.h"
#include "vtkGenericOpenGLRenderWindow.h"
#include "vtkSmartPointer.h"

class PCAViewer : public QMainWindow
{
	Q_OBJECT

public:
	PCAViewer(QWidget *parent = Q_NULLPTR);

private:
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> _window;
	Ui::PCAViewerClass ui;
	void setupVtk();
	void connectActions();

public slots:
	void loadPcdFile();
};
