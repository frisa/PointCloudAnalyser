#pragma once
#include <QObject>

class PclPersistor : public QObject
{
	Q_OBJECT
public:
	PclPersistor();
	~PclPersistor();

public slots:
	bool loadPcdToCloud(QString pcdFilePath);
};

