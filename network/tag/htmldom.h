#ifndef HTMLDOM_H
#define HTMLDOM_H

#include "tag.h"

#include <QMultiMap>



class HtmlDom
{
private:
    QMultiMap<int, QString> dom;
    QString rawHtml;
    int rawHtmlSize;

public:
    HtmlDom(QString rawHtml);
    ~HtmlDom() { }

    template<typename T>
    QList<T> tagList(const QString &tag, bool selfClosing) {
        QList<T> result;
        QString closingTag = '/' + tag;
        int startPos, endPos;
        int balance = 0; // баланс между откр/закр тегами
        int tagApndx = tag.count() + 3; //"<" + "/" + tag + ">"
        QString val;
        QMultiMap<int, QString>::iterator it;
        QMultiMap<int, QString>::iterator itEnd = dom.end();

        foreach (startPos, tagStartPositions(tag)) {
            it = dom.find(startPos, tag);
            balance = 0;
            while (it != itEnd) {
                val = it.value();
                if (selfClosing) {
                    if (val == "/>") {
                        endPos = it.key() + 1;
                        result << T(rawHtml.mid(startPos, (endPos - startPos)));
                        break;
                    }
                } else {
                    if (val == closingTag) {
                        --balance;
                        if (balance == 0) {
                            endPos = it.key() + tagApndx;
                            result << T(rawHtml.mid(startPos, (endPos - startPos)));
                            break;
                        }
                    } else if (val == tag) {
                        ++balance;
                    }
                }
                ++it;
            }
        }
        return result;
    }

    template<typename T>
    QList<T> tagListByAttribute(const QString &attr, const QString &val,
                                const QString &tag, bool selfClosing) {
        QList<T> result;
        QString tmpAttr, tmpValue;
        bool attrFound = false;
        bool correctAttr = true; // attr="value" => true; attr=value = > false
        QChar tmpCh;

        int begin = tag.size() + 1; // 1 на символ '<' в начале тега
        foreach (T tmp, tagList<T>(tag, selfClosing)) {
            Tag *t = &tmp;
            QString tmpTag = t->outerHtml();
            for (int i = begin; i < tmpTag.size(); ++i) {
                tmpCh = tmpTag.at(i);
                if (tmpCh == '>' && correctAttr) {
                    correctAttr = true;
                    attrFound = false;
                    break;
                }
                if (attrFound) {
                    if (tmpCh == '"' || tmpCh == ' ' || tmpCh == '/'
                            || (tmpCh == '>' && !correctAttr)) {

                        /* значение аттрибута должно быть в tmpVal */
                        // qDebug() << tmpValue;
                        if (tmpValue == val) {
                            result << T(tmpTag);
                            attrFound = false;
                            break;
                        }
                        tmpValue.clear();
                        if (!correctAttr || tmpCh == '>') {
                            correctAttr = true;
                            attrFound = false;
                            break;
                        }
                    } else {
                        tmpValue.append(tmpCh);
                    }
                } else {
                    if (tmpCh == ' ') {
                        tmpAttr.clear();
                    } else {
                        if (tmpCh != "=") {
                            tmpAttr.append(tmpCh);
                        } else {
                            /* в buf должно быть имя атрибута */
                            if (tmpAttr == attr) {
                                tmpAttr.clear();
                                attrFound = true;
                                if (tmpTag.at(i+1) == '"') {
                                    // если имеем дело с attr="val" -
                                    // обходим кавычку, но если attr=val -
                                    // забираем сл. символ сразу
                                    ++i;
                                } else {
                                    correctAttr = false;
                                }
                            } else {
                                tmpAttr.clear();
                                attrFound = false;
                            }
                        }
                    }
                }
            }
            tmpAttr.clear();
            tmpValue.clear();
        }
        return result;
    }

    QList<int> tagStartPositions(const QString &tagName);
};

#endif // HTMLDOM_H
