#ifndef SPAN_H
#define SPAN_H

#include "html.h"
#include "retrievable.h"
#include "tag.h"



class Span : public Tag, public Retrievable
{
public:
    Span() : Tag(), Retrievable ("") { }
    Span(QString outerHtml) : Tag(outerHtml), Retrievable (outerHtml) { }
    ~Span() override { }

    // Tag interface
public:
    QString name() override;
    bool isSelfClosing() override { return false; }
};

#endif // SPAN_H
