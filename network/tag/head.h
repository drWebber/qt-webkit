#ifndef HEAD_H
#define HEAD_H

#include "html.h"
#include "tag.h"


class Head : public Tag
{
public:
    Head() : Tag() { }
    Head(QString outerHtml) : Tag(outerHtml) { }
public:
    QString innerText();
    QString tagName();

    static Head element(Html *html);
};

#endif // HEAD_H
