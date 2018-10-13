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
    QString innerText() override;

    static Head element(Html *html);

    // Tag interface
public:
    QString tagName() override;
    bool isSelfClosing() override { return false; }
};

#endif // HEAD_H
