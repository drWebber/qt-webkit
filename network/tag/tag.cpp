#include "tag.h"


QString Tag::outerHtml() const
{
    return _outerHtml;
}

QString Tag::customAttribute(const QString &attr) const
{
    return getAttrValue(attr);
}

Tag::Tag(QString outerHtml)
{
    _outerHtml = outerHtml;
    href = getAttrValue("href");
}

QString Tag::hrefAttribute() const
{
    return href;
}

QStringList Tag::classAttribute() const
{
    QString raw = getAttrValue("class");
    return raw.split(' ');
}

QString Tag::altAttribute() const
{
    return getAttrValue("alt");
}

QString Tag::relAttribute() const
{
    return getAttrValue("rel");
}

QString Tag::titleAttribute() const
{
    return getAttrValue("title");
}

bool Tag::isEmpty()
{
    return _outerHtml.isEmpty();
}

QString Tag::innerText()
{
    QString str = RegExp::match("(?si)>(.+)</" + tagName() + ">",
                                _outerHtml, 1);
    RegExp::replace("<.+?>", str, "");
    return str;
}

QString Tag::innerHtml()
{
    return RegExp::match("(?si)>(.+)</" + tagName() + ">", _outerHtml, 1);
}

QString Tag::getAttrValue(const QString attr) const
{
    QString value;
    QString tag = RegExp::match("(.+?>)", _outerHtml, 1);
    if (tag.contains(attr + "=\"")) {
        value = RegExp::match(attr + "=\"([^\"]+)", tag, 1);
    } else {
        value = RegExp::match(attr + "=([^\"]+?)(\\s|/|>)", tag, 1);
    }
    return value;
}
