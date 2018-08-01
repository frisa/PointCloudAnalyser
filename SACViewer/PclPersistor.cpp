#include "PclPersistor.h"
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>


PclPersistor::PclPersistor()
{
}

PclPersistor::PclPersistor(Logger * logger)
{
	_logger = logger;
}


PclPersistor::~PclPersistor()
{
}

bool PclPersistor::loadPcdToCloud(QString pcdFilePath)
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
	_logger->log("Loading PCD file: " + pcdFilePath);
	if (pcl::io::loadPCDFile<pcl::PointXYZ>(pcdFilePath.toStdString(), *cloud) == -1)
	{
		_logger->log("Couldn't read pcd file: " + pcdFilePath);
		return false;
	}
	else
	{
		_logger->log("Loaded PCD file: " + pcdFilePath);
		return true;
	}
}