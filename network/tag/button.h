#ifndef BUTTON_H
#define BUTTON_H

#include "html.h"
#include "tag.h"



class Button : public Tag
{
public:
    Button() : Tag() { }
    Button(QString outerHtml) : Tag(outerHtml) { }

    static QList<Button> element(Html *html);

    // Tag interface
public:
    QString tagName() override;
    bool isSelfClosing() override { return false; }
};

#endif // BUTTON_H
