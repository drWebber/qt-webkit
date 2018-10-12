#ifndef TABLE_H
#define TABLE_H

#include "tag.h"
#include "html.h"


class Table : public Tag
{
public:
    Table() : Tag() { }
    Table(QString outerHtml) : Tag(outerHtml) { }
    ~Table() { }

    // Tag interface
public:
    QString tagName();

    static QList<Table> element(Html *html);
};

#endif // TABLE_H
