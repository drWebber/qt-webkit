#include "html.h"


Html::Html(QString outerHtml) : Tag(outerHtml)
{
    htmlDom = new HtmlDom(outerHtml);
}

void Html::setDomain(const Domain &domain)
{
    this->domain = domain;
}

HtmlDom *Html::getHtmlDom() const
{
    return htmlDom;
}

Html::~Html()
{
    delete htmlDom;
}

QString Html::name()
{
    return "html";
}

QString Html::getTitle()
{
    return RegExp::match("(?si)<title>(.+?)</title>", _outerHtml, 1);
}

void Html::removeJsFromHtml()
{
    RegExp::replace("(?si)<script.+?/script>", _outerHtml, "");
}

void Html::removeCssFromHtml()
{
    RegExp::replace("(?si)<style.+?/style>", _outerHtml, "");
}

void Html::removeCodeComments()
{
    RegExp::replace("(?si)<!--.+?-->", _outerHtml, "");
}
