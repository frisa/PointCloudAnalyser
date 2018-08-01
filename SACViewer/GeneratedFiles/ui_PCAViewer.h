/********************************************************************************
** Form generated from reading UI file 'PCAViewer.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCAVIEWER_H
#define UI_PCAVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "QVTKOpenGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_PCAViewerClass
{
public:
    QAction *actionLoad_PCD;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTextEdit *tbPcdFilePath;
    QPushButton *btnLoadPcd;
    QVTKOpenGLWidget *openGLWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PCAViewerClass)
    {
        if (PCAViewerClass->objectName().isEmpty())
            PCAViewerClass->setObjectName(QStringLiteral("PCAViewerClass"));
        PCAViewerClass->resize(646, 515);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/E:/icons/if_cloud_1805075.ico"), QSize(), QIcon::Normal, QIcon::Off);
        PCAViewerClass->setWindowIcon(icon);
        actionLoad_PCD = new QAction(PCAViewerClass);
        actionLoad_PCD->setObjectName(QStringLiteral("actionLoad_PCD"));
        centralWidget = new QWidget(PCAViewerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tbPcdFilePath = new QTextEdit(centralWidget);
        tbPcdFilePath->setObjectName(QStringLiteral("tbPcdFilePath"));
        tbPcdFilePath->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(tbPcdFilePath, 0, 0, 1, 1);

        btnLoadPcd = new QPushButton(centralWidget);
        btnLoadPcd->setObjectName(QStringLiteral("btnLoadPcd"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icons/E:/icons/if_3d_objects_102518.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnLoadPcd->setIcon(icon1);

        gridLayout->addWidget(btnLoadPcd, 0, 1, 1, 1);

        openGLWidget = new QVTKOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));

        gridLayout->addWidget(openGLWidget, 1, 0, 1, 2);

        PCAViewerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PCAViewerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 646, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        PCAViewerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PCAViewerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PCAViewerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PCAViewerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PCAViewerClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoad_PCD);

        retranslateUi(PCAViewerClass);
        QObject::connect(btnLoadPcd, SIGNAL(clicked()), actionLoad_PCD, SLOT(trigger()));

        QMetaObject::connectSlotsByName(PCAViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *PCAViewerClass)
    {
        PCAViewerClass->setWindowTitle(QApplication::translate("PCAViewerClass", "Point Cloud Analyser", nullptr));
        actionLoad_PCD->setText(QApplication::translate("PCAViewerClass", "Load PCD", nullptr));
        tbPcdFilePath->setHtml(QApplication::translate("PCAViewerClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">c:\\_git\\PointCloudAnalyser\\PcdData\\test_pcd_file.pcd</p></body></html>", nullptr));
        tbPcdFilePath->setPlaceholderText(QApplication::translate("PCAViewerClass", "** place the path to the *.pcd file here, than press Load PCD **", nullptr));
        btnLoadPcd->setText(QApplication::translate("PCAViewerClass", "Load PCD", nullptr));
        menuFile->setTitle(QApplication::translate("PCAViewerClass", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PCAViewerClass: public Ui_PCAViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCAVIEWER_H
