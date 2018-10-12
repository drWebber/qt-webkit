#ifndef HEADER_H
#define HEADER_H

#include "html.h"
#include "tag.h"



class Header : public Tag
{
public:
    Header() : Tag() { }
    Header(QString outerHtml) : Tag(outerHtml) { }

    // Tag interface
public:
    QString tagName();

    static QList<Header> element(Html *html);
};

#endif // HEADER_H
