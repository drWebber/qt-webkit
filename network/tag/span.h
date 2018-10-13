#ifndef SPAN_H
#define SPAN_H

#include "html.h"
#include "tag.h"



class Span : public Tag
{
public:
    Span() { }
    Span(QString outerHtml) : Tag(outerHtml) { }
    ~Span() override { }

    static QList<Span> element(Html *html);
    static QList<Span> elementByClass(Html *html, QString className);

    // Tag interface
public:
    QString tagName() override;
    bool isSelfClosing() override { return false; }
};

#endif // SPAN_H
