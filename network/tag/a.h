#ifndef A_H
#define A_H

#include "network/tag/html.h"
#include "tag.h"
#include <QtCore/qhash.h>
#include <qset.h>

class A : public Tag
{
private:
    QString host;
public:
    A() : Tag() { }
    A(QString outerHtml) : Tag(outerHtml) { }
    ~A() override { }
    void truncateAnchor();
    bool isExternal();
    bool isContactLink(bool excludeMailToRef);

    QString tagName() override;
    void setHost(const QString &host);

    static QSet<A> uniqueLinks(QList<A> &links, QString host,
                               bool truncateAnchors, bool excludeContactLinks);

    static QList<A> element(Html *html);
    static QList<A> elementByClass(Html *html, QString className);

    // Tag interface
public:
    bool isSelfClosing() override { return false; }
};


inline bool operator==(const A &obj1, const A &obj2)
{
    return obj1.hrefAttribute() == obj2.hrefAttribute();
}

inline uint qHash (const A &foo, uint seed = 0 )
{
    return ::qHash(foo.hrefAttribute(), seed);
}

#endif // A_H
