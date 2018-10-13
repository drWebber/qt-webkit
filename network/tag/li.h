#ifndef LI_H
#define LI_H

#include "html.h"
#include "tag.h"


class Li : public Tag
{
public:
    Li() { }
    Li(QString outerHtml) : Tag(outerHtml) { }
    ~Li() override { }

    static QList<Li> element(Html *html);
    static QList<Li> elementByClass(Html *html, QString className);

    // Tag interface
public:
    QString tagName() override;
    bool isSelfClosing() override { return false; }
};

#endif // LI_H
