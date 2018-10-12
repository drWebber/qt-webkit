#include "head.h"

QString Head::tagName()
{
    return "head";
}

QString Head::innerText()
{
    return "";
}

Head Head::element(Html *html)
{
    HtmlDom *htmlDom = html->getHtmlDom();
    QList<Head> head = htmlDom->tagList<Head>("head", false);
    return head.isEmpty() ? Head() : head.first();
}
