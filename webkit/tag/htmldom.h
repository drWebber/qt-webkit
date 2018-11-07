#ifndef HTMLDOM_H
#define HTMLDOM_H

#include "tag.h"

#include <QMap>


class HtmlDom
{
private:
    QMap<int, QString> dom;
    QString rawHtml;
    int rawHtmlSize;    

    QList<int> tagStartPositions(const QString &tagName);
    QPair<int, int> findTagPosition(
            const int startPos, const QString &tag, bool selfClosing);

public:
    HtmlDom(const QString &rawHtml);
    ~HtmlDom() { }

    template<typename T>
    QList<T> tagList(const QString &tag, bool selfClosing) {
        QList<T> result;
        foreach (int startPos, tagStartPositions(tag)) {
            QPair<int, int> position =
                    findTagPosition(startPos, tag, selfClosing);
            if (position.second != -1) {
                result << T(rawHtml.mid(position.first,
                                        (position.second - position.first)));
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

    template<typename T>
    QList<T> elementsByClass(const QString &className) {
        Tag *tag = new T();
        QString name = tag->name();
        bool selfClosing = tag->isSelfClosing();
        delete tag;

        return tagListByAttribute<T>("class", className,
                                     name, selfClosing);
    }

    template<typename T>
    QList<T> elementsByParameter(const QString &param, const QString &value) {
        // Example: <div param="value">text</div>
        Tag *tag = new T();
        QString name = tag->name();
        bool selfClosing = tag->isSelfClosing();
        delete tag;

        return tagListByAttribute<T>(param, value,
                                     name, selfClosing);
    }
};

#endif // HTMLDOM_H
