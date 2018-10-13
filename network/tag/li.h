#ifndef LI_H
#define LI_H

#include "html.h"
#include "retrievable.h"
#include "tag.h"


class Li : public Tag, public Retrievable
{
public:
    Li() : Tag(), Retrievable ("") { }
    Li(QString outerHtml) : Tag(outerHtml), Retrievable (outerHtml) { }
    ~Li() override { }

    // Tag interface
public:
    QString name() override;
    bool isSelfClosing() override;
};

#endif // LI_H
