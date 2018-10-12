#include "body.h"


QString Body::tagName()
{
    return "body";
}

QString Body::innerText()
{
    QString text = _outerHtml;
    RegExp::replace("(?si)<script.+?/script>", text, "");
    RegExp::replace("(?si)</?p>|<p\\s.+?>", text, "\r\n");
    RegExp::replace("<br/?>|<br\\s.+?>", text, "\r\n");
    RegExp::replace("(?si)</?li>|<li\\s.+?>", text, "\r\n");
    RegExp::replace("(?si)</?h\\d>|<h\\d\\s.+?>", text, "\r\n");
    RegExp::replace("(?si)<.+?>", text, "");
    return text;
}

int Body::cyrillicSymbolsCount()
{
    return RegExp::matchesCount("[А-я]", innerText());
}

QStringList Body::getPhoneNumbers()
{
    QStringList phones;
    QStringList patt;

    patt << "\\d{1,3}-\\d{2,5}-\\d{2,3}-\\d{2}-\\d{2}"
         << "\\d{1,3} \\d{2,5} \\d{2,3} \\d{2} \\d{2}"
         << "\\d{1,3} ?\\(\\d{2,5}\\) \\d{2,3} \\d{2} \\d{2}"
         << "\\d{1,3} ?\\(\\d{2,5}\\) \\d{2,3}-\\d{2}-\\d{2}"
         << "\\d{1,3} ?\\(\\d{2,5}\\) \\d{3}-\\d{3}";

    QString inner = innerText();
    foreach (QString pattern, patt) {
        if (inner.contains(QRegularExpression(pattern))) {
            phones << RegExp::matches(pattern, inner, 0);
        }
    }

    return phones;
}

Body Body::element(Html *html)
{
    HtmlDom *htmlDom = html->getHtmlDom();
    QList<Body> body = htmlDom->tagList<Body>("body", false);
    return body.isEmpty() ? Body() : body.first();
}
