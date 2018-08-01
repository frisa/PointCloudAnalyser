#pragma once
#include <QObject>
#include "Logger.h"

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
	bool loadPcdToCloud(QString pcdFilePath);
};

