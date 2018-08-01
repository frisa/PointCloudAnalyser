#include "Logger.h"



Logger::Logger()
{
}


Logger::~Logger()
{
}

void Logger::init(QTextDocument * document)
{
	_document = document;
}

void Logger::log(QString text)
{
	_document->setPlainText( _document->toPlainText() + text + "\n");
}
