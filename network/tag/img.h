#ifndef IMG_H
#define IMG_H

#include "html.h"
#include "tag.h"



class Img : public Tag
{
public:
    Img() : Tag() { }
    Img(QString outerHtml) : Tag(outerHtml) { }
    ~Img() { }

    // Tag interface
public:
    QString tagName();

    static QList<Img> element(Html *html);
};

#endif // IMG_H
