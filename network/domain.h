#ifndef DOMAIN_H
#define DOMAIN_H

#include <QDate>
#include <QUrl>
#include <qlist.h>

#include "util/regexp.h"

class Domain
{
private:
    int id = 0;
    QUrl url;
public:
    int getId() const;
    void setId(int value);

    QUrl getUrl() const;
    void setUrl(QString value);

    QString getHost();
};

#endif // DOMAIN_H
