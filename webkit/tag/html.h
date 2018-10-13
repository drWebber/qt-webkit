#ifndef HTML_H
#define HTML_H

#include "webkit/domain.h"
#include "tag.h"
#include "htmldom.h"

#include <qdebug.h>


class Html : public Tag
{
private:
    Domain domain;
    HtmlDom *htmlDom;

public:
    Html(QString outerHtml);
    ~Html() override;

    HtmlDom *getHtmlDom() const;

    QString getTitle();

    /* удаляет весь <script.+?/script> из outerHtml */
    void removeJsFromHtml();
    /* удаляет весь <style.+?/style> из outerHtml */
    void removeCssFromHtml();
    /* удаляет весь <!--.+?--> из outerHtml */
    void removeCodeComments();

    void setDomain(const Domain &domain);

    template<typename T>
    QList<T> childElements() {
        Tag *tag = new T();
        QString name = tag->name();
        bool selfClosing = tag->isSelfClosing();
        delete tag;

        return htmlDom->tagList<T>(name, selfClosing);
    }

    template<typename T>
    QList<T> childElementsByClass(const QString &className) {
        return htmlDom->elementsByClass<T>(className);
    }

    template<typename T>
    QList<T> childElementsByParameter(
            const QString &param, const QString &value) {
        return htmlDom->elementsByParameter<T>(param, value);
    }

    // Tag interface
public:
    QString name() override;
    bool isSelfClosing() override { return false; }
};

#endif // HTML_H
