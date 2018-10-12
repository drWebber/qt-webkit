#ifndef TAG_H
#define TAG_H

#include "qstring.h"
#include "util/regexp.h"

#include <qdebug.h>

class Tag
{
private:
    QString getAttrValue(const QString attr) const;
protected:
    QString _outerHtml;
    QString href;
public:
    Tag() { }
    Tag(QString outerHtml);
    virtual ~Tag() { }

    /* вся разметка, вместе с самим тегом */
    QString outerHtml() const;

    QString customAttribute(const QString &attr) const;
    QString hrefAttribute() const;
    QStringList classAttribute() const;
    QString altAttribute() const;
    QString relAttribute() const;
    QString titleAttribute() const;
    bool isEmpty();
    /* видимый текст внутри тега (с удалением разметки) */
    virtual QString innerText();
    /* разметка внутри тега */
    virtual QString innerHtml();

    virtual QString tagName() = 0;

//    template<typename T>
//    QList<T> elemenstByClass(const QString &className, bool selfClosing) {
//        return HtmlDom(_outerHtml)
//                .tagListByAttribute<T>("class", className, "div", selfClosing);
//    }
};

#endif // TAG_H
