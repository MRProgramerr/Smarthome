#include <QtTest>

// add necessary includes here

class lightswitch : public QObject
{
    Q_OBJECT

public:
    lightswitch();
    ~lightswitch();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

lightswitch::lightswitch()
{

}

lightswitch::~lightswitch()
{

}

void lightswitch::initTestCase()
{

}

void lightswitch::cleanupTestCase()
{

}

void lightswitch::test_case1()
{

}

QTEST_APPLESS_MAIN(lightswitch)

#include "tst_lightswitch.moc"
