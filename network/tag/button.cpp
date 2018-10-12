#include "button.h"


QString Button::tagName()
{
    return "button";
}

QList<Button> Button::element(Html *html)
{
    HtmlDom *htmlDom = html->getHtmlDom();
    return htmlDom->tagList<Button>("button", false);
}
