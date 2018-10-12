#ifndef DIV_H
#define DIV_H

#include "html.h"
#include "tag.h"


class Div : public Tag
{
public:
    Div() : Tag() { }
    Div(QString outerHtml) : Tag(outerHtml) { }
    ~Div() override { }

    // Tag interface
public:
    QString tagName() override;

    static QList<Div> elemenstByClass(Html *html, QString className);
};

#endif // DIV_H
