#ifndef H1_H
#define H1_H

#include "html.h"
#include "tag.h"


class H1 : public Tag
{
public:
    H1() : Tag() { }
    H1(QString outerHtml) : Tag(outerHtml) { }

    // Tag interface
public:
    QString tagName();

    static H1 element(Html *html);
};

#endif // H1_H
