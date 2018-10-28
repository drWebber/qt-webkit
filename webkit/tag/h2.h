#ifndef H2_H
#define H2_H

#include "html.h"
#include "retrievable.h"
#include "tag.h"


class H2 : public Tag, public Retrievable
{
public:
    H2() : Tag(), Retrievable ("") { }
    H2(QString outerHtml) : Tag(outerHtml), Retrievable (outerHtml) { }

    // Tag interface
public:
    QString name() override;
    bool isSelfClosing() override { return false; }
};

#endif // H2_H
