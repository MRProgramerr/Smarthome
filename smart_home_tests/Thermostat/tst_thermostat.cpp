#include <QtTest>
#include "thermostat.h"
// add necessary includes here

class thermostat : public QObject
{
    Q_OBJECT

public:
    thermostat();
    ~thermostat();
private:
    Thermostat ts;
private slots:
    void initTestCase();
    void cleanupTestCase();
    void testID();
    void testIPaddress();


    void testUpdateFreq();




};

thermostat::thermostat() : ts("test2")
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

void thermostat::testID()
{
    ts.setDeviceName("Thermostat");
    QCOMPARE(ts.getDeviceName(), "Thermostat");
}

void thermostat::testIPaddress()
{
    ts.setIPAddressController("TS IP");
    QCOMPARE(ts.getIPAddressController(), "TS IP");
}



void thermostat::testUpdateFreq()
{
    ts.setUpdateFrequency(3.0);
    QCOMPARE(ts.getUpdateFrequency(),3.0);
}







QTEST_APPLESS_MAIN(thermostat)

#include "tst_thermostat.moc"
