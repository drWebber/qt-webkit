#ifndef LI_H
#define LI_H

#include "html.h"
#include "tag.h"


class Li : public Tag
{
public:
    Li() { }
    Li(QString outerHtml) : Tag(outerHtml) { }
    ~Li() { }

    // Tag interface
public:
    QString tagName() override;

    static QList<Li> element(Html *html);
    static QList<Li> elementByClass(Html *html, QString className);
};

#endif // LI_H
