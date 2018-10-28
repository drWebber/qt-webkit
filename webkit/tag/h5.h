#ifndef H5_H
#define H5_H

#include "html.h"
#include "retrievable.h"
#include "tag.h"


class H5 : public Tag, public Retrievable
{
public:
    H5() : Tag(), Retrievable ("") { }
    H5(QString outerHtml) : Tag(outerHtml), Retrievable (outerHtml) { }

    // Tag interface
public:
    QString name() override;
    bool isSelfClosing() override { return false; }
};

#endif // H5_H
