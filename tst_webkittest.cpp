#include <QtTest>

#include <filereader/filereader.h>

#include <network/tag/a.h>
#include <network/tag/div.h>
#include <network/tag/html.h>

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
    QList<A> links = A::elementByClass(html, "testLink");
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

    QCOMPARE(A::elementByClass(html, "link_theme_normal").size(), 1);
    QCOMPARE(A::elementByClass(html, "daria-goto-anchor").size(), 1);

}

void WebKitTest::testTagDiv()
{
    QList<Div> divs = Div::elemenstByClass(html, "serp-item");

    for (auto i = 0; i < divs.size(); i++) {
        QVERIFY(divs[i].classAttribute().contains("serp-item"));
        QCOMPARE(divs[i].customAttribute("data-cid"), QString::number(i));
    }

    QCOMPARE(divs.size(), 9);
}

QTEST_APPLESS_MAIN(WebKitTest)

#include "tst_webkittest.moc"
