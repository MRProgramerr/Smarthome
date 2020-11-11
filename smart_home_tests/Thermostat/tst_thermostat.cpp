#include <QtTest>

// add necessary includes here

class thermostat : public QObject
{
    Q_OBJECT

public:
    thermostat();
    ~thermostat();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

thermostat::thermostat()
{

}

thermostat::~thermostat()
{

}

void thermostat::initTestCase()
{

}

void thermostat::cleanupTestCase()
{

}

void thermostat::test_case1()
{

}

QTEST_APPLESS_MAIN(thermostat)

#include "tst_thermostat.moc"
