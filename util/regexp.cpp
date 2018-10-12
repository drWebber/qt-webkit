#include "regexp.h"


QString RegExp::replace(QString pattern, QString &source, QString after)
{
    QRegularExpression rx(pattern);
    return source.replace(rx, after);
}

QString RegExp::match(QString pattern, QString str, int subexpressionNth)
{
    QRegularExpression rx(pattern);
    QString result;
    auto it = rx.globalMatch(str);
    if (it.hasNext()) {
        result = it.next().captured(subexpressionNth);
    }
    return result;
}

QStringList RegExp::matches(QString pattern, QString str,
                              int subexpressionNth)
{
    QRegularExpression rx(pattern);
    QStringList list;
    auto it = rx.globalMatch(str);
    while(it.hasNext()) {
        auto match = it.next();
        list << match.captured(subexpressionNth);
    }
    return list;
}

int RegExp::matchesCount(QString pattern, QString str)
{
    int count = 0;
    QRegularExpression rx(pattern);
    auto it = rx.globalMatch(str);
    while(it.hasNext()) {
        it.next();
        count++;
    }
    return count;
}
