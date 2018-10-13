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
    QString innerText() override;
    QString tagName() override;

    int cyrillicSymbolsCount();
    QStringList getPhoneNumbers();

    static Body element(Html *html);

    // Tag interface
public:
    bool isSelfClosing() override { return false; }
};

#endif // BODY_H
