#ifndef H6_H
#define H6_H

#include "html.h"
#include "retrievable.h"
#include "tag.h"


class H6 : public Tag, public Retrievable
{
public:
    H6() : Tag(), Retrievable ("") { }
    H6(QString outerHtml) : Tag(outerHtml), Retrievable (outerHtml) { }

    // Tag interface
public:
    QString name() override;
    bool isSelfClosing() override { return false; }
};

#endif // H6_H
