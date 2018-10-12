#include "li.h"


QString Li::tagName()
{
    return "li";
}

QList<Li> Li::element(Html *html)
{
    HtmlDom *htmlDom = html->getHtmlDom();
    return htmlDom->tagList<Li>("li", false);
}

QList<Li> Li::elementByClass(Html *html, QString className)
{
    HtmlDom *dom = html->getHtmlDom();
    return dom->tagListByAttribute<Li>("class", className, "li", false);
}
