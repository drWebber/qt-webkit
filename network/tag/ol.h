#ifndef OL_H
#define OL_H

#include "retrievable.h"
#include "tag.h"


class Ol : public Tag, public Retrievable
{
public:
    Ol() : Tag(), Retrievable ("") { }
    Ol(QString outerHtml) : Tag(outerHtml), Retrievable (outerHtml) { }
    ~Ol() override { }

    // Tag interface
public:
    QString name() override;
    bool isSelfClosing() override;
};

#endif // OL_H
