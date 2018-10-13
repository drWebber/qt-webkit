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

    // Tag interface
public:
    QString name() override;
    bool isSelfClosing() override { return true; }
};

#endif // IMG_H
