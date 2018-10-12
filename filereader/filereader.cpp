#include "filereader.h"

FileReader::FileReader(QString fileName)
{    
    file = new QFile(fileName);
    file->open(QIODevice::ReadWrite);
    in = new QTextStream(file);
    in->setCodec("UTF-8");
}

FileReader::~FileReader()
{
    file->close();
    in->flush();
}

QString FileReader::read()
{
    return QString::fromLocal8Bit(in->readAll().toLocal8Bit());
}
