#ifndef IMG_H
#define IMG_H

#include "html.h"
#include "tag.h"



class Img : public Tag
{
public:
    Img() : Tag() { }
    Img(QString outerHtml) : Tag(outerHtml) { }
    ~Img() override { }

    static QList<Img> element(Html *html);

    // Tag interface
public:
    QString tagName() override;
    bool isSelfClosing() override { return true; }
};

#endif // IMG_H
