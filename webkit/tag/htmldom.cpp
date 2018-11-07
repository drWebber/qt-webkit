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
    QMap<int, QString>::iterator it;
    for (it = dom.begin(); it != dom.end(); ++it) {
        if (it.value() == tagName) {
            positions << it.key();
        }
    }
    return positions;
}

QPair<int, int> HtmlDom::findTagPosition(
        const int startPos, const QString &tag, bool selfClosing)
{
    QPair<int, int> position(startPos, -1);

    QString value = "";
    QString closure = '/' + tag;

    QMap<int, QString>::iterator it = dom.find(startPos);
    QMap<int, QString>::iterator itEnd = dom.end();

    int balance = 0; // баланс между откр/закр тегами
    while (it != itEnd) {
        value = it.value();
        if (selfClosing) {
            if (value == "/>") {
                position.second = it.key() + 1;
                break;
            }
        } else {
            if (value == closure) {
                --balance;
                if (balance == 0) {
                    int tagApndx = tag.count() + 3; //"<" + "/" + tag + ">"
                    position.second = it.key() + tagApndx;
                    break;
                }
            } else if (value == tag) {
                ++balance;
            }
        }
        ++it;
    }
    return position;
}
