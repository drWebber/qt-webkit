#include "span.h"


QString Span::tagName()
{
    return "span";
}

QList<Span> Span::element(Html *html)
{
    HtmlDom *htmlDom = html->getHtmlDom();
    return htmlDom->tagList<Span>("span", false);
}

QList<Span> Span::elementByClass(Html *html, QString className)
{
    HtmlDom *dom = html->getHtmlDom();
    return dom->tagListByAttribute<Span>("class", className, "span", false);
}
