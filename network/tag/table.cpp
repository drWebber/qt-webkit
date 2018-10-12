#include "table.h"

QString Table::tagName()
{
    return "table";
}

QList<Table> Table::element(Html *html)
{
    HtmlDom *htmlDom = html->getHtmlDom();
    return htmlDom->tagList<Table>("img", false);
}
