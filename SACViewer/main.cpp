#include "PCAViewer.h"
#include <QtWidgets/QApplication>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include "QVTKOpenGLWidget.h"
#include <QSurfaceFormat>

#include "vtkAutoInit.h" 
VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2
VTK_MODULE_INIT(vtkInteractionStyle);

int main(int argc, char *argv[])
{
	QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());
	QApplication a(argc, argv);
	PCAViewer w;
	w.show();
	return a.exec();
}
