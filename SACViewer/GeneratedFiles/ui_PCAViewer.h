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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "QVTKOpenGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_PCAViewerClass
{
public:
    QAction *actionFileLoad;
    QAction *actionGenerateCloud;
    QAction *actionSaveImage;
    QAction *actionFileBrowse;
    QAction *actionPclSampleConsensus;
    QAction *actionFileSave;
    QAction *actionSACPlaneModel;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *btnCloudGenerate;
    QLabel *label;
    QPushButton *btnFileLoad;
    QPushButton *btnFileBrowse;
    QPushButton *btnFileBmp;
    QPlainTextEdit *tbLog;
    QVTKOpenGLWidget *openGLWidget;
    QTextEdit *tbFsdFilesDirectory;
    QPushButton *btnFileSave;
    QPushButton *pbSampleConsensus;
    QSpacerItem *verticalSpacer;
    QPushButton *btnSACPlaneModel;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PCAViewerClass)
    {
        if (PCAViewerClass->objectName().isEmpty())
            PCAViewerClass->setObjectName(QStringLiteral("PCAViewerClass"));
        PCAViewerClass->resize(1099, 678);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/E:/icons/if_cloud_1805075.ico"), QSize(), QIcon::Normal, QIcon::Off);
        PCAViewerClass->setWindowIcon(icon);
        PCAViewerClass->setLayoutDirection(Qt::LeftToRight);
        actionFileLoad = new QAction(PCAViewerClass);
        actionFileLoad->setObjectName(QStringLiteral("actionFileLoad"));
        actionGenerateCloud = new QAction(PCAViewerClass);
        actionGenerateCloud->setObjectName(QStringLiteral("actionGenerateCloud"));
        actionSaveImage = new QAction(PCAViewerClass);
        actionSaveImage->setObjectName(QStringLiteral("actionSaveImage"));
        actionFileBrowse = new QAction(PCAViewerClass);
        actionFileBrowse->setObjectName(QStringLiteral("actionFileBrowse"));
        actionPclSampleConsensus = new QAction(PCAViewerClass);
        actionPclSampleConsensus->setObjectName(QStringLiteral("actionPclSampleConsensus"));
        actionFileSave = new QAction(PCAViewerClass);
        actionFileSave->setObjectName(QStringLiteral("actionFileSave"));
        actionSACPlaneModel = new QAction(PCAViewerClass);
        actionSACPlaneModel->setObjectName(QStringLiteral("actionSACPlaneModel"));
        centralWidget = new QWidget(PCAViewerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btnCloudGenerate = new QPushButton(centralWidget);
        btnCloudGenerate->setObjectName(QStringLiteral("btnCloudGenerate"));
        btnCloudGenerate->setMaximumSize(QSize(200, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icons/E:/icons/if_Dice_128401.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnCloudGenerate->setIcon(icon1);

        gridLayout->addWidget(btnCloudGenerate, 5, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 23));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        btnFileLoad = new QPushButton(centralWidget);
        btnFileLoad->setObjectName(QStringLiteral("btnFileLoad"));
        btnFileLoad->setMaximumSize(QSize(200, 23));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icons/E:/icons/if_sync_1891404.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnFileLoad->setIcon(icon2);

        gridLayout->addWidget(btnFileLoad, 3, 0, 1, 1);

        btnFileBrowse = new QPushButton(centralWidget);
        btnFileBrowse->setObjectName(QStringLiteral("btnFileBrowse"));
        btnFileBrowse->setMaximumSize(QSize(200, 23));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Icons/E:/icons/if_Open_1493293.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnFileBrowse->setIcon(icon3);

        gridLayout->addWidget(btnFileBrowse, 0, 0, 1, 1);

        btnFileBmp = new QPushButton(centralWidget);
        btnFileBmp->setObjectName(QStringLiteral("btnFileBmp"));
        btnFileBmp->setMaximumSize(QSize(200, 23));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Icons/E:/icons/if_bmp_7062.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnFileBmp->setIcon(icon4);

        gridLayout->addWidget(btnFileBmp, 6, 0, 1, 1);

        tbLog = new QPlainTextEdit(centralWidget);
        tbLog->setObjectName(QStringLiteral("tbLog"));
        tbLog->setMaximumSize(QSize(220, 16777215));

        gridLayout->addWidget(tbLog, 3, 1, 9, 1);

        openGLWidget = new QVTKOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy);
        openGLWidget->setMinimumSize(QSize(0, 0));
        openGLWidget->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(openGLWidget, 3, 3, 9, 1);

        tbFsdFilesDirectory = new QTextEdit(centralWidget);
        tbFsdFilesDirectory->setObjectName(QStringLiteral("tbFsdFilesDirectory"));
        tbFsdFilesDirectory->setMaximumSize(QSize(16777215, 23));

        gridLayout->addWidget(tbFsdFilesDirectory, 0, 3, 1, 1);

        btnFileSave = new QPushButton(centralWidget);
        btnFileSave->setObjectName(QStringLiteral("btnFileSave"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Icons/E:/icons/if_floppy_285657.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnFileSave->setIcon(icon5);

        gridLayout->addWidget(btnFileSave, 4, 0, 1, 1);

        pbSampleConsensus = new QPushButton(centralWidget);
        pbSampleConsensus->setObjectName(QStringLiteral("pbSampleConsensus"));
        pbSampleConsensus->setMinimumSize(QSize(0, 0));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Images/E:/Images/sample_consensus_planes_cylinders.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSampleConsensus->setIcon(icon6);

        gridLayout->addWidget(pbSampleConsensus, 9, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 0, 1, 1);

        btnSACPlaneModel = new QPushButton(centralWidget);
        btnSACPlaneModel->setObjectName(QStringLiteral("btnSACPlaneModel"));
        btnSACPlaneModel->setIcon(icon6);

        gridLayout->addWidget(btnSACPlaneModel, 8, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        PCAViewerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PCAViewerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1099, 21));
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
        menuFile->addAction(actionFileLoad);
        menuFile->addAction(actionGenerateCloud);

        retranslateUi(PCAViewerClass);
        QObject::connect(btnFileLoad, SIGNAL(clicked()), actionFileLoad, SLOT(trigger()));
        QObject::connect(btnCloudGenerate, SIGNAL(clicked()), actionGenerateCloud, SLOT(trigger()));
        QObject::connect(btnFileBmp, SIGNAL(clicked()), actionSaveImage, SLOT(trigger()));
        QObject::connect(btnFileBrowse, SIGNAL(clicked()), actionFileBrowse, SLOT(trigger()));
        QObject::connect(pbSampleConsensus, SIGNAL(clicked()), actionPclSampleConsensus, SLOT(trigger()));
        QObject::connect(btnFileSave, SIGNAL(clicked()), actionFileSave, SLOT(trigger()));
        QObject::connect(btnSACPlaneModel, SIGNAL(clicked()), actionSACPlaneModel, SLOT(trigger()));

        QMetaObject::connectSlotsByName(PCAViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *PCAViewerClass)
    {
        PCAViewerClass->setWindowTitle(QApplication::translate("PCAViewerClass", "Point Cloud Analyser", nullptr));
        actionFileLoad->setText(QApplication::translate("PCAViewerClass", "FileLoad", nullptr));
        actionGenerateCloud->setText(QApplication::translate("PCAViewerClass", "GenerateCloud", nullptr));
        actionSaveImage->setText(QApplication::translate("PCAViewerClass", "SaveImage", nullptr));
        actionFileBrowse->setText(QApplication::translate("PCAViewerClass", "FileBrowse", nullptr));
        actionPclSampleConsensus->setText(QApplication::translate("PCAViewerClass", "PclSampleConsensus", nullptr));
        actionFileSave->setText(QApplication::translate("PCAViewerClass", "FileSave", nullptr));
        actionSACPlaneModel->setText(QApplication::translate("PCAViewerClass", "SACPlaneModel", nullptr));
        btnCloudGenerate->setText(QApplication::translate("PCAViewerClass", "Generate Cloud", nullptr));
        label->setText(QApplication::translate("PCAViewerClass", "PCD File Path:", nullptr));
        btnFileLoad->setText(QApplication::translate("PCAViewerClass", "Load Cloud", nullptr));
        btnFileBrowse->setText(QApplication::translate("PCAViewerClass", "Browse Cloud File (*.pcd)", nullptr));
        btnFileBmp->setText(QApplication::translate("PCAViewerClass", "Save as Image", nullptr));
        tbFsdFilesDirectory->setHtml(QApplication::translate("PCAViewerClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">c:\\_git\\PointCloudAnalyser\\PcdData\\filtered_scan.pcd</p></body></html>", nullptr));
        tbFsdFilesDirectory->setPlaceholderText(QApplication::translate("PCAViewerClass", "** place the path to the *.pcd file here, than press Load PCD **", nullptr));
        btnFileSave->setText(QApplication::translate("PCAViewerClass", "Save Cloud", nullptr));
        pbSampleConsensus->setText(QApplication::translate("PCAViewerClass", "Sample Consensus", nullptr));
        btnSACPlaneModel->setText(QApplication::translate("PCAViewerClass", "SAC Plane Model", nullptr));
        menuFile->setTitle(QApplication::translate("PCAViewerClass", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PCAViewerClass: public Ui_PCAViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCAVIEWER_H
