#ifndef H4_H
#define H4_H

#include "html.h"
#include "retrievable.h"
#include "tag.h"


class H4 : public Tag, public Retrievable
{
public:
    H4() : Tag(), Retrievable ("") { }
    H4(QString outerHtml) : Tag(outerHtml), Retrievable (outerHtml) { }

    // Tag interface
public:
    QString name() override;
    bool isSelfClosing() override { return false; }
};

#endif // H4_H
