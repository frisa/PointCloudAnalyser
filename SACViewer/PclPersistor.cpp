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

bool PclPersistor::loadPcdToCloud(QString pcdFilePath, pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
{
	_logger->log("Loading PCD file: " + pcdFilePath);
	if (pcl::io::loadPCDFile<pcl::PointXYZ>(pcdFilePath.toStdString(), *cloud) == -1)
	{
		_logger->log("Couldn't read pcd file: " + pcdFilePath);
		return false;
	}
	else
	{
		_logger->log("Loaded PCD file: " + pcdFilePath);
		_logger->log("cloud_width = " + QString::number(cloud->width));
		_logger->log("cloud_height = " + QString::number(cloud->height));
		_logger->log("cloud_size = " + QString::number(cloud->size()));
		_logger->log("cloud_points = " + QString::number(cloud->points.size()));

		for (size_t i = 0; i < cloud->points.size(); ++i)
		{
			_logger->log("[" + QString::number(cloud->points[i].x) + "," + QString::number(cloud->points[i].y) + "," + QString::number(cloud->points[i].z) + "]");
		}
		return true;
	}
}