#ifndef H1_H
#define H1_H

#include "html.h"
#include "tag.h"


class H1 : public Tag
{
public:
    H1() : Tag() { }
    H1(QString outerHtml) : Tag(outerHtml) { }


    static H1 element(Html *html);

    // Tag interface
public:
    QString tagName() override;
    bool isSelfClosing() override { return false; }
};

#endif // H1_H
