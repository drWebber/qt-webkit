#ifndef HEADER_H
#define HEADER_H

#include "html.h"
#include "tag.h"



class Header : public Tag
{
public:
    Header() : Tag() { }
    Header(QString outerHtml) : Tag(outerHtml) { }

    static QList<Header> element(Html *html);

    // Tag interface
public:
    QString tagName() override;
    bool isSelfClosing() override { return false; }
};

#endif // HEADER_H
