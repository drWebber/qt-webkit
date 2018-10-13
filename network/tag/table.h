#ifndef TABLE_H
#define TABLE_H

#include "tag.h"
#include "html.h"


class Table : public Tag
{
public:
    Table() : Tag() { }
    Table(QString outerHtml) : Tag(outerHtml) { }
    ~Table() override { }

    static QList<Table> element(Html *html);

    // Tag interface
public:
    QString tagName() override;
    bool isSelfClosing() override { return false; }
};

#endif // TABLE_H
