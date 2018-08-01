#pragma once
#include <QObject>
#include <QTextDocument>

class Logger : public QObject
{
	Q_OBJECT
private:
	QTextDocument * _document;
public:
	Logger();
	~Logger();
	void init(QTextDocument * document);
	void log(QString text);
};

