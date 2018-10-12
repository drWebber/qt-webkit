#ifndef BODY_H
#define BODY_H

#include "html.h"
#include "tag.h"
#include <qdebug.h>

class Body : public Tag
{
public:
    Body() : Tag() { }
    Body(QString outerHtml) : Tag(outerHtml) { }
public:
    QString innerText();
    QString tagName();

    int cyrillicSymbolsCount();
    QStringList getPhoneNumbers();

    static Body element(Html *html);
};

#endif // BODY_H
