#ifndef FILEREADER_H
#define FILEREADER_H

#include <qstring.h>
#include <qfile.h>
#include <qtextstream.h>



class FileReader
{
private:
    QFile *file;
    QTextStream *in;

public:
    FileReader(QString fileName);
    ~FileReader();

    QString read();
};

#endif // FILEREADER_H
