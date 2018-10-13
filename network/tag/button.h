#ifndef BUTTON_H
#define BUTTON_H

#include "html.h"
#include "retrievable.h"
#include "tag.h"


class Button : public Tag, public Retrievable
{
public:
    Button() : Tag(), Retrievable ("") { }
    Button(QString outerHtml) : Tag(outerHtml), Retrievable (outerHtml) { }

    // Tag interface
public:
    QString name() override;
    bool isSelfClosing() override { return false; }
};

#endif // BUTTON_H
