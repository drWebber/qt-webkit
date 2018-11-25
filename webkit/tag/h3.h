#ifndef H3_H
#define H3_H

#include "retrievable.h"
#include "tag.h"


class H3 : public Tag, public Retrievable
{
public:
    H3() : Tag(), Retrievable ("") { }
    H3(QString outerHtml) : Tag(outerHtml), Retrievable (outerHtml) { }

    // Tag interface
public:
    QString name() override;
    bool isSelfClosing() override { return false; }
};

#endif // H3_H
