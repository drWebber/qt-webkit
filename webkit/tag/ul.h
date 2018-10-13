#ifndef UL_H
#define UL_H

#include "retrievable.h"
#include "tag.h"



class Ul : public Tag, public Retrievable
{
public:
    Ul() : Tag(), Retrievable ("") { }
    Ul(QString outerHtml) : Tag(outerHtml), Retrievable (outerHtml) { }
    ~Ul() override { }

    // Tag interface
public:
    QString name() override;
    bool isSelfClosing() override;
};

#endif // UL_H
