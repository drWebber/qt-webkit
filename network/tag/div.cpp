#include "div.h"

#include "network/tag/htmldom.h"

QString Div::tagName()
{
    return "div";
}

QList<Div> Div::elemenstByClass(Html *html, QString className)
{
    HtmlDom *dom = html->getHtmlDom();
    return dom->tagListByAttribute<Div>("class", className, "div", false);
}
