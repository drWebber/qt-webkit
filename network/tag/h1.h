#ifndef H1_H
#define H1_H

#include "html.h"
#include "retrievable.h"
#include "tag.h"


class H1 : public Tag, public Retrievable
{
public:
    H1() : Tag(), Retrievable ("") { }
    H1(QString outerHtml) : Tag(outerHtml), Retrievable (outerHtml) { }

    // Tag interface
public:
    QString name() override;
    bool isSelfClosing() override { return false; }
};

#endif // H1_H
