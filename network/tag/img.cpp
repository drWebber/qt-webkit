#include "img.h"


QString Img::tagName()
{
    return "img";
}

QList<Img> Img::element(Html *html)
{
    HtmlDom *htmlDom = html->getHtmlDom();
    return htmlDom->tagList<Img>("img", true);
}
