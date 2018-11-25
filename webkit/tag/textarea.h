#ifndef TEXTAREA_H
#define TEXTAREA_H

#include "retrievable.h"
#include "tag.h"

class Textarea : public Tag, public Retrievable
{
public:
    Textarea() : Tag(), Retrievable ("") { }
    Textarea(QString outerHtml) : Tag(outerHtml), Retrievable (outerHtml) { }

    // Tag interface
public:
    QString name() override;
    bool isSelfClosing() override { return false; }
};

#endif // TEXTAREA_H
