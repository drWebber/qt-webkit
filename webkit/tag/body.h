#ifndef BODY_H
#define BODY_H

#include "html.h"
#include "retrievable.h"
#include "tag.h"
#include <qdebug.h>


class Body : public Tag, public Retrievable
{
public:
    Body() : Tag(), Retrievable ("") { }
    Body(QString outerHtml) : Tag(outerHtml), Retrievable (outerHtml) { }
public:
    QString innerText();
    QString name() override;

    int cyrillicSymbolsCount();
    QStringList getPhoneNumbers();

    // Tag interface
public:
    bool isSelfClosing() override { return false; }
};

#endif // BODY_H
