#include "h1.h"

QString H1::tagName()
{
    return "h1";
}

H1 H1::element(Html *html)
{
    HtmlDom *htmlDom = html->getHtmlDom();
    QList<H1> h1 = htmlDom->tagList<H1>("h1", false);
    return h1.isEmpty() ? H1() : h1.first();
}
