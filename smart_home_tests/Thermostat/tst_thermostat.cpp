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
        void testcurrentState();
        void testlastMeasurement();
        void testlast5Measurements();
        void testUpdateFreq();
        void testsetpoint();
        void testwarmer();
        void testcooler();



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

void thermostat::testcurrentState()
{

}

void thermostat::testlastMeasurement()
{

}

void thermostat::testlast5Measurements()
{

}

void thermostat::testUpdateFreq()
{
    ts.setUpdateFrequency(3.0);
    QCOMPARE(ts.getUpdateFrequency(),3.0);
}

void thermostat::testsetpoint()
{
    QString name = "Test";
        std::string UoM = "F";
        MeasurementTemplate<double> *mt;
        mt = new MeasurementTemplate<double>(name.toStdString(),"temperature setpoint",UoM);
        mt->setValue(20.0);
        ts.setUnitofMeasure("F");
        ts.setthesetpoint(20.0);

        QCOMPARE(ts.setpoint(),mt);

}

void thermostat::testwarmer()
{
    ts.setthesetpoint(20.0);
        ts.warmer(20.0);
        QCOMPARE(ts.setpoint()->value(), 40.0);


}

void thermostat::testcooler()
{
       ts.setthesetpoint(20.0);
       ts.cooler(20.0);
       QCOMPARE(ts.setpoint()->value(), 0.0);
       ts.cooler(20.0);
       QCOMPARE(ts.setpoint()->value(), 0.0);

}



QTEST_APPLESS_MAIN(thermostat)

#include "tst_thermostat.moc"
