#ifndef HTML_H
#define HTML_H

#include "network/domain.h"
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
    ~Html();

    HtmlDom *getHtmlDom() const;

    // Tag interface
public:
    QString tagName();
    QString getTitle();

    /* удаляет весь <script.+?/script> из outerHtml */
    void removeJsFromHtml();
    /* удаляет весь <style.+?/style> из outerHtml */
    void removeCssFromHtml();
    /* удаляет весь <!--.+?--> из outerHtml */
    void removeComments();

    void setDomain(const Domain &domain);
};

#endif // HTML_H
