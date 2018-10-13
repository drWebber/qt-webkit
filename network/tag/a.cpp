#include "a.h"


void A::setHost(const QString &host)
{
    this->host = host;
}

void A::truncateAnchor()
{
    QString anchor = RegExp::match("(?si)(#.+)", hrefAttribute(), 1);
    if (!anchor.isEmpty()) {
        href = href.replace(anchor, "");
    } else {
        if (href.contains("#")) {
            href = href.replace("#", "");
        }
        if (href.contains("javascript:")) {
            href = "";
        }
    }
    if (isContactLink(false)) {
        href = "";
    }
}

bool A::isExternal()
{
    QString left4 = href.left(4);

    QString left2 = left4.left(2);
    /* если ссыль начинается с http - проверяем на содержание хоста */
    if (left4.contains("http")) {
        if (!href.contains(host)) {
            return true;
        }
    }
    /* если начинается с "//" - это внешняя ссылка */
    if (left2.contains("//")) {
        return true;
    }
    return false;
}

bool A::isContactLink(bool excludeMailToRef)
{
    if (!href.isEmpty()) {
        QStringList refs = QStringList()  << "callto:" << "tel:"
                                          << "wtai:" << "sms:" << "fax:"
                                          << "skype:";
        if (!excludeMailToRef) {
            refs << "mailto:";
        }
        foreach (auto ref, refs) {
            if (href.contains(ref)) {
                return true;
            }
        }
    }
    return false;
}

QSet<A> A::uniqueLinks(QList<A> &links, QString host,
                       bool truncateAnchors, bool excludeContactLinks)
{
    QSet<A> set;
    foreach (A raw, links) {
        if (truncateAnchors) {
            raw.truncateAnchor();
        }
        if (!raw.hrefAttribute().isEmpty()) {
            if (!host.isEmpty()) {
                raw.setHost(host);
                if (!raw.isExternal()) {
                    if (excludeContactLinks) {
                        if (!raw.isContactLink(false)) {
                            set.insert(raw);
                        }
                    } else {
                        set.insert(raw);
                    }
                }
            } else {
                set.insert(raw);
            }
        }
    }
    return set;
}

QString A::name()
{
    return "a";
}
