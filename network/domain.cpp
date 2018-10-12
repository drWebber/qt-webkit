#include "domain.h"


QString Domain::getHost()
{
    return RegExp::match("(?:https?://(?:www.)?)?(.+?)/?$", url.toString(), 1);
}

QUrl Domain::getUrl() const
{
    return url;
}

void Domain::setUrl(QString value)
{
    if (!value.contains("http")) {
        value.prepend("http://");
    }
    url = QUrl(value);
}

int Domain::getId() const
{
    return id;
}

void Domain::setId(int value)
{
    id = value;
}
