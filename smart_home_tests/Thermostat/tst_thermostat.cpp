#include <QtTest>
#include <QCoreApplication>
#include "thermostat.h"
// add necessary includes here

class tst_Thermostat : public QObject
{
    Q_OBJECT

public:
    tst_Thermostat();
    ~tst_Thermostat();
private:
    Thermostat ts;
private slots:
    void testID();
    void testIPaddress();
    void testcurrentState();
    void testlastMeasurement();
    void testlast5Measurements();
    void testsetpoint();
    void testtempChange();
};

tst_Thermostat::tst_Thermostat() : ts("HH")
{

}

tst_Thermostat::~tst_Thermostat()
{

}

void tst_Thermostat::testID()
{
    ts.setDeviceName("Thermostat");
    QCOMPARE(ts.getDeviceName(),"Thermostat");
}

void tst_Thermostat::testIPaddress()
{
    ts.setIPAddressController("Thermostat IP");
    QCOMPARE(ts.getIPAddressController(), "Thermostat IP");
}

void tst_Thermostat::testcurrentState()
{

}
void tst_Thermostat::testlastMeasurement()
{

}
void tst_Thermostat::testlast5Measurements()
{

}
void tst_Thermostat::testsetpoint()
{

}
void tst_Thermostat::testtempChange()
{

}

QTEST_MAIN(tst_Thermostat)

#include "tst_thermostat.moc"
