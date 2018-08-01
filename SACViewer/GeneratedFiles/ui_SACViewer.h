/********************************************************************************
** Form generated from reading UI file 'SACViewer.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SACVIEWER_H
#define UI_SACVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "QVTKOpenGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_SACViewerClass
{
public:
    QWidget *centralWidget;
    QVTKOpenGLWidget *openGLWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SACViewerClass)
    {
        if (SACViewerClass->objectName().isEmpty())
            SACViewerClass->setObjectName(QStringLiteral("SACViewerClass"));
        SACViewerClass->resize(600, 400);
        centralWidget = new QWidget(SACViewerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openGLWidget = new QVTKOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(10, 10, 511, 311));
        SACViewerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SACViewerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        SACViewerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SACViewerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SACViewerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SACViewerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SACViewerClass->setStatusBar(statusBar);

        retranslateUi(SACViewerClass);

        QMetaObject::connectSlotsByName(SACViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *SACViewerClass)
    {
        SACViewerClass->setWindowTitle(QApplication::translate("SACViewerClass", "SACViewer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SACViewerClass: public Ui_SACViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SACVIEWER_H
