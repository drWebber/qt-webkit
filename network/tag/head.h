#ifndef HEAD_H
#define HEAD_H

#include "html.h"
#include "retrievable.h"
#include "tag.h"


class Head : public Tag, public Retrievable
{
public:
    Head() : Tag(), Retrievable ("") { }
    Head(QString outerHtml) : Tag(outerHtml), Retrievable (outerHtml) { }
public:
    QString innerText();

    // Tag interface
public:
    QString name() override;
    bool isSelfClosing() override { return false; }
};

#endif // HEAD_H
