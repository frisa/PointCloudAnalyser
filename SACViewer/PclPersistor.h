#pragma once
#include <QObject>
#include "Logger.h"
#include <pcl/point_types.h>
#include <pcl/common/projection_matrix.h>

class PclPersistor : public QObject
{
	Q_OBJECT
private:
	Logger * _logger;
public:
	PclPersistor();
	PclPersistor(Logger* logger);
	~PclPersistor();

public slots:
	bool loadPcdToCloud(QString pcdFilePath, pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud);
};

