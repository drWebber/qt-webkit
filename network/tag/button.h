#ifndef BUTTON_H
#define BUTTON_H

#include "html.h"
#include "tag.h"



class Button : public Tag
{
public:
    Button() : Tag() { }
    Button(QString outerHtml) : Tag(outerHtml) { }

    QString tagName();

    static QList<Button> element(Html *html);
};

#endif // BUTTON_H
