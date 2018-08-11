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
    QAction *actionGenerate_PCD;
    QAction *actionShowLogo;
    QAction *actionSaveImage;
    QAction *actionBrowsePCD;
    QAction *actionSampleConsensus;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *btnBmp;
    QPushButton *btnPCDFile;
    QPushButton *btnGeneratePcd;
    QLabel *label;
    QPushButton *btnLoadPcd;
    QTextEdit *tbFsdFilesDirectory;
    QPlainTextEdit *tbLog;
    QVTKOpenGLWidget *openGLWidget;
    QPushButton *btnLogo;
    QPushButton *pbSampleConsensus;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PCAViewerClass)
    {
        if (PCAViewerClass->objectName().isEmpty())
            PCAViewerClass->setObjectName(QStringLiteral("PCAViewerClass"));
        PCAViewerClass->resize(1045, 881);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/E:/icons/if_cloud_1805075.ico"), QSize(), QIcon::Normal, QIcon::Off);
        PCAViewerClass->setWindowIcon(icon);
        PCAViewerClass->setLayoutDirection(Qt::LeftToRight);
        actionLoad_PCD = new QAction(PCAViewerClass);
        actionLoad_PCD->setObjectName(QStringLiteral("actionLoad_PCD"));
        actionGenerate_PCD = new QAction(PCAViewerClass);
        actionGenerate_PCD->setObjectName(QStringLiteral("actionGenerate_PCD"));
        actionShowLogo = new QAction(PCAViewerClass);
        actionShowLogo->setObjectName(QStringLiteral("actionShowLogo"));
        actionShowLogo->setIcon(icon);
        actionSaveImage = new QAction(PCAViewerClass);
        actionSaveImage->setObjectName(QStringLiteral("actionSaveImage"));
        actionBrowsePCD = new QAction(PCAViewerClass);
        actionBrowsePCD->setObjectName(QStringLiteral("actionBrowsePCD"));
        actionSampleConsensus = new QAction(PCAViewerClass);
        actionSampleConsensus->setObjectName(QStringLiteral("actionSampleConsensus"));
        centralWidget = new QWidget(PCAViewerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btnBmp = new QPushButton(centralWidget);
        btnBmp->setObjectName(QStringLiteral("btnBmp"));
        btnBmp->setMaximumSize(QSize(200, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icons/E:/icons/if_bmp_7062.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnBmp->setIcon(icon1);

        gridLayout->addWidget(btnBmp, 5, 0, 1, 1);

        btnPCDFile = new QPushButton(centralWidget);
        btnPCDFile->setObjectName(QStringLiteral("btnPCDFile"));
        btnPCDFile->setMaximumSize(QSize(200, 23));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icons/E:/icons/if_Open_1493293.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnPCDFile->setIcon(icon2);

        gridLayout->addWidget(btnPCDFile, 0, 0, 1, 1);

        btnGeneratePcd = new QPushButton(centralWidget);
        btnGeneratePcd->setObjectName(QStringLiteral("btnGeneratePcd"));
        btnGeneratePcd->setMaximumSize(QSize(200, 23));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Icons/E:/icons/if_Dice_128401.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnGeneratePcd->setIcon(icon3);

        gridLayout->addWidget(btnGeneratePcd, 4, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 23));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        btnLoadPcd = new QPushButton(centralWidget);
        btnLoadPcd->setObjectName(QStringLiteral("btnLoadPcd"));
        btnLoadPcd->setMaximumSize(QSize(200, 23));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Icons/E:/icons/if_3d_objects_102518.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnLoadPcd->setIcon(icon4);

        gridLayout->addWidget(btnLoadPcd, 3, 0, 1, 1);

        tbFsdFilesDirectory = new QTextEdit(centralWidget);
        tbFsdFilesDirectory->setObjectName(QStringLiteral("tbFsdFilesDirectory"));
        tbFsdFilesDirectory->setMaximumSize(QSize(16777215, 23));

        gridLayout->addWidget(tbFsdFilesDirectory, 0, 3, 1, 1);

        tbLog = new QPlainTextEdit(centralWidget);
        tbLog->setObjectName(QStringLiteral("tbLog"));
        tbLog->setMaximumSize(QSize(220, 16777215));

        gridLayout->addWidget(tbLog, 3, 1, 6, 1);

        openGLWidget = new QVTKOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy);
        openGLWidget->setMinimumSize(QSize(0, 0));
        openGLWidget->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(openGLWidget, 3, 3, 6, 1);

        btnLogo = new QPushButton(centralWidget);
        btnLogo->setObjectName(QStringLiteral("btnLogo"));
        btnLogo->setMaximumSize(QSize(200, 23));
        btnLogo->setIcon(icon);

        gridLayout->addWidget(btnLogo, 6, 0, 1, 1);

        pbSampleConsensus = new QPushButton(centralWidget);
        pbSampleConsensus->setObjectName(QStringLiteral("pbSampleConsensus"));
        pbSampleConsensus->setMinimumSize(QSize(0, 0));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Images/E:/Images/sample_consensus_planes_cylinders.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSampleConsensus->setIcon(icon5);

        gridLayout->addWidget(pbSampleConsensus, 7, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        PCAViewerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PCAViewerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1045, 21));
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
        menuFile->addAction(actionGenerate_PCD);

        retranslateUi(PCAViewerClass);
        QObject::connect(btnLoadPcd, SIGNAL(clicked()), actionLoad_PCD, SLOT(trigger()));
        QObject::connect(btnGeneratePcd, SIGNAL(clicked()), actionGenerate_PCD, SLOT(trigger()));
        QObject::connect(btnLogo, SIGNAL(clicked()), actionShowLogo, SLOT(trigger()));
        QObject::connect(btnBmp, SIGNAL(clicked()), actionSaveImage, SLOT(trigger()));
        QObject::connect(btnPCDFile, SIGNAL(clicked()), actionBrowsePCD, SLOT(trigger()));
        QObject::connect(pbSampleConsensus, SIGNAL(clicked()), actionSampleConsensus, SLOT(trigger()));

        QMetaObject::connectSlotsByName(PCAViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *PCAViewerClass)
    {
        PCAViewerClass->setWindowTitle(QApplication::translate("PCAViewerClass", "Point Cloud Analyser", nullptr));
        actionLoad_PCD->setText(QApplication::translate("PCAViewerClass", "Load PCD", nullptr));
        actionGenerate_PCD->setText(QApplication::translate("PCAViewerClass", "Generate PCD", nullptr));
        actionShowLogo->setText(QApplication::translate("PCAViewerClass", "ShowLogo", nullptr));
        actionSaveImage->setText(QApplication::translate("PCAViewerClass", "SaveImage", nullptr));
        actionBrowsePCD->setText(QApplication::translate("PCAViewerClass", "BrowsePCD", nullptr));
        actionSampleConsensus->setText(QApplication::translate("PCAViewerClass", "SampleConsensus", nullptr));
        btnBmp->setText(QApplication::translate("PCAViewerClass", "Save Image", nullptr));
        btnPCDFile->setText(QApplication::translate("PCAViewerClass", "Browse PCD File", nullptr));
        btnGeneratePcd->setText(QApplication::translate("PCAViewerClass", "Generate PCD", nullptr));
        label->setText(QApplication::translate("PCAViewerClass", "PCD File Path:", nullptr));
        btnLoadPcd->setText(QApplication::translate("PCAViewerClass", "Load PCD", nullptr));
        tbFsdFilesDirectory->setHtml(QApplication::translate("PCAViewerClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">c:\\_git\\PointCloudAnalyser\\PcdData\\filtered_scan.pcd</p></body></html>", nullptr));
        tbFsdFilesDirectory->setPlaceholderText(QApplication::translate("PCAViewerClass", "** place the path to the *.pcd file here, than press Load PCD **", nullptr));
        btnLogo->setText(QApplication::translate("PCAViewerClass", "Show Logo", nullptr));
        pbSampleConsensus->setText(QApplication::translate("PCAViewerClass", "Sample Consensus", nullptr));
        menuFile->setTitle(QApplication::translate("PCAViewerClass", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PCAViewerClass: public Ui_PCAViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCAVIEWER_H
