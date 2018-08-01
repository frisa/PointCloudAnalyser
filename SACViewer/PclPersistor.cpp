#include "PclPersistor.h"
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>


PclPersistor::PclPersistor()
{
}


PclPersistor::~PclPersistor()
{
}

bool PclPersistor::loadPcdToCloud(QString pcdFilePath)
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

	if (pcl::io::loadPCDFile<pcl::PointXYZ>(pcdFilePath.toStdString(), *cloud) == -1)
	{
		PCL_ERROR("Couldn't read pcd file");
		return false;
	}
	else
	{
		return true;
	}
}