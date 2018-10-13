#ifndef DIV_H
#define DIV_H

#include "html.h"
#include "retrievable.h"
#include "tag.h"


class Div : public Tag, public Retrievable
{
public:
    Div() : Tag(), Retrievable ("") { }
    Div(QString outerHtml) : Tag(outerHtml), Retrievable (outerHtml) { }
    ~Div() override { }

    // Tag interface
public:
    QString name() override;
    bool isSelfClosing() override;
};

#endif // DIV_H
