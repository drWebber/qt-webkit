#ifndef RETRIEVABLE_H
#define RETRIEVABLE_H

#include "html.h"

#include <qlist.h>



class Retrievable
{
private:
    QString _outerHtml;
public:
    Retrievable(const QString &outerHtml);

    template<typename T>
    QList<T> childElements() {
        return Html(_outerHtml).elements<T>();
    }

    template<typename T>
    QList<T> childElementsByClass(const QString &className) {
        return Html(_outerHtml).childElementsByClass<T>(className);
    }

    template<typename T>
    QList<T> childElementsByParameter(const QString &param,
                                      const QString &value) {
        return Html(_outerHtml).childElementsByParameter<T>(param, value);
    }
};

#endif // RETRIEVABLE_H
