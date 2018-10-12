#include "header.h"

QString Header::tagName()
{
    return "h\\d";
}

QList<Header> Header::element(Html *html)
{
    QList<Header> result;
    HtmlDom *htmlDom = html->getHtmlDom();
    result << htmlDom->tagList<Header>("h1", false);
    result << htmlDom->tagList<Header>("h2", false);
    result << htmlDom->tagList<Header>("h3", false);
    result << htmlDom->tagList<Header>("h4", false);
    result << htmlDom->tagList<Header>("h5", false);
    result << htmlDom->tagList<Header>("h6", false);
    return result;
}
