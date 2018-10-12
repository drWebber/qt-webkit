#ifndef REGEXP_H
#define REGEXP_H

#include <qregularexpression.h>
#include <qstringlist.h>

class RegExp
{
public:
    static QString replace(QString pattern, QString &source, QString after);
    static QString match(QString pattern, QString str,
                                 int subexpressionNth);
    static QStringList matches(QString pattern, QString str,
                                 int subexpressionNth);
    static int matchesCount(QString pattern, QString str);
};

#endif // REGEXP_H
