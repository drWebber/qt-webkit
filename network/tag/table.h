#ifndef TABLE_H
#define TABLE_H

#include "tag.h"
#include "html.h"
#include "retrievable.h"


class Table : public Tag, public Retrievable
{
public:
    Table() : Tag(), Retrievable ("") { }
    Table(QString outerHtml) : Tag(outerHtml), Retrievable (outerHtml) { }
    ~Table() override { }

    // Tag interface
public:
    QString name() override;
    bool isSelfClosing() override;
};

#endif // TABLE_H
