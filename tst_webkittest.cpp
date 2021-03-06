#include <QtTest>

#include <filereader/filereader.h>

#include <webkit/tag/a.h>
#include <webkit/tag/div.h>
#include <webkit/tag/h1.h>
#include <webkit/tag/h2.h>
#include <webkit/tag/h3.h>
#include <webkit/tag/h4.h>
#include <webkit/tag/h5.h>
#include <webkit/tag/h6.h>
#include <webkit/tag/html.h>
#include <webkit/tag/li.h>
#include <webkit/tag/ol.h>
#include <webkit/tag/ul.h>

// add necessary includes here

class WebKitTest : public QObject
{
    Q_OBJECT
private:
    Html *html;
public:
    WebKitTest();
    ~WebKitTest();

private slots:
    void testTagA();
    void testTagDiv();
    void testTagUl();
    void testTagOl();
    void testHeaders();
    void testArticle();

};

WebKitTest::WebKitTest()
{
    html = new Html(FileReader("html.html").read());
}

WebKitTest::~WebKitTest()
{
    delete html;
}

void WebKitTest::testTagA()
{
    QList<A> links = html->childElementsByClass<A>("testLink");
    QCOMPARE(links.size(), 5);

    A link = links.first();

    QCOMPARE(link.titleAttribute(), "");
    QCOMPARE(link.hrefAttribute(), "http://yandex.by/clck/jsredir?bu=");
    QCOMPARE(link.outerHtml(), "<a class=\"testLink link link_theme_normal organic__url link_cropped_no i-bem link_js_inited\" data-bem=\"{&quot;link&quot;:{}}\" accesskey=\"2\" tabindex=2 data-beacon=\"\" data-log-node=\"8xnu\" rel=noopener target=\"_blank\" href=\"http://yandex.by/clck/jsredir?bu=\" data-counter=\"http://yandex.by/clck/jsredir\"><div class=\"favicon favicon_page_0\"><div class=\"favicon__icon\" data-rcid=\"81\" style=\"background-position:0 0px;\"></div></div><div class=\"organic__url-text\"><b class=\"needsclick\">Htmlbook</b>.ru — HTML, CSS, веб-дизайн</div></a>");
    QCOMPARE(link.innerHtml(), "<div class=\"favicon favicon_page_0\"><div class=\"favicon__icon\" data-rcid=\"81\" style=\"background-position:0 0px;\"></div></div><div class=\"organic__url-text\"><b class=\"needsclick\">Htmlbook</b>.ru — HTML, CSS, веб-дизайн</div>");
    QStringList strList0 =
            QStringList() << "testLink" << "link" << "link_theme_normal"
                          << "organic__url" << "link_cropped_no" << "i-bem"
                          << "link_js_inited";
    QCOMPARE(link.classAttribute(), strList0);
    QCOMPARE(link.relAttribute(), "noopener");
    QCOMPARE(link.customAttribute("tabindex"), "2");
    QCOMPARE(link.customAttribute("accesskey"), "2");
    QCOMPARE(link.customAttribute("data-log-node"), "8xnu");

    QCOMPARE(html->childElementsByClass<A>("link_theme_normal").size(), 1);
    QCOMPARE(html->childElementsByClass<A>("daria-goto-anchor").size(), 1);

}

void WebKitTest::testTagDiv()
{
    QList<Div> divs = html->childElementsByClass<Div>("serp-item");

    for (auto i = 0; i < divs.size(); i++) {
        QVERIFY(divs[i].classAttribute().contains("serp-item"));
        QCOMPARE(divs[i].customAttribute("data-cid"), QString::number(i));
    }

    QCOMPARE(divs.size(), 9);
    QCOMPARE(divs.first().childElementsByClass<Div>("serp-item__text").first().innerText(),
             "Триллер, криминал, детектив. Режиссер: Хенрик Георгссон, Румле Хаммерих, Шарлотта Зилинг и др. В ролях: София Хелин, Ким Бодния, Туре Линдхардт и др. На самой середине Эресуннского моста, связывающего Швецию с Данией, происходит краткое отключение эл...");
}

void WebKitTest::testTagUl()
{
    QList<Ul> ulList = html->childElements<Ul>();
    QCOMPARE(ulList.size(), 1);

    QList<Li> liList = ulList.first().childElements<Li>();
    QCOMPARE(liList.first().innerText(), "one");
}

void WebKitTest::testTagOl()
{
    QList<Ol> olList = html->childElementsByParameter<Ol>("trash", "list_two");
    QCOMPARE(olList.size(), 1);

    QList<Li> liList = olList.first().childElements<Li>();
    QCOMPARE(liList.last().innerText(), "j");

}

void WebKitTest::testHeaders()
{
    QList<H1> h1List = html->childElements<H1>();
    QCOMPARE(1, h1List.size());

    QList<H2> h2List = html->childElements<H2>();
    QCOMPARE(3, h2List.size());

    QList<H3> h3List = html->childElements<H3>();
    QCOMPARE(3, h3List.size());

    QList<H4> h4List = html->childElements<H4>();
    QCOMPARE(1, h4List.size());

//    QList<H5> h5List = html->childElements<H5>();
//    QCOMPARE(2, h5List.size());

//    QList<H6> h6List = html->childElements<H6>();
    //    QCOMPARE(2, h6List.size());
}

void WebKitTest::testArticle()
{
    Div article = html->article<Div>();
    QCOMPARE(3, article.childElements<H3>().size());
    QCOMPARE(1, article.childElements<H1>().size());
}

QTEST_APPLESS_MAIN(WebKitTest)

#include "tst_webkittest.moc"
