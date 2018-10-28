#include "htmldom.h"

HtmlDom::HtmlDom(const QString &rawHtml)
{
    this->rawHtml = rawHtml;
    rawHtmlSize = rawHtml.size();

    QString buf;
    bool tagFound = false;
    int pos;

    for (int i = 0; i < rawHtmlSize; ++i) {
        if (tagFound) {
            if (rawHtml.at(i) == '>' || rawHtml.at(i) == ' ') {
                // buf.toLower() позволяет далее находить теги с малой и большой
                // буквы <tag> && <TAG>
                dom.insert(pos, buf.toLower());
                buf.clear();
                tagFound = false;
            } else {
                buf.append(rawHtml.at(i));
            }
        }
        // самозакрывающийся тег
        if (rawHtml.at(i) == '>' && rawHtml.at(i-1) == '/') {
            dom.insert(i, "/>");
        }
        if (rawHtml.at(i) == '<') {
            pos = i;
            tagFound = true;
        }
    }
}

QList<int> HtmlDom::tagStartPositions(const QString &tagName)
{
    QList<int> positions;
    QMultiMap<int, QString>::iterator it;
    for (it = dom.begin(); it != dom.end(); ++it) {
        if (it.value() == tagName) {
            positions << it.key();
        }
    }
    return positions;
}
