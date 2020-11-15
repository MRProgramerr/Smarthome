#include <QtTest>
#include "thermostatproxy.h"
#include "thermostat.h"

// add necessary includes here

class testthermostatproxy : public QObject
{
    Q_OBJECT

public:
    testthermostatproxy();
    ~testthermostatproxy();
    void cleanupTestCase();
    void testUpdateFrequency();
    void testunitofMeasure();
    void testStartingTemperature();
    void testlastMeasurement();
    void teststorelastMeasurementsAndLastFiveMeaurements();
    void testsetpoint();
    void testcurrentState();
    void testwarmer();
    void testcooler();
    void testrandomDouble();
    void testupdate();

private slots:
    void test_case1();

};

testthermostatproxy::testthermostatproxy()
{

}

testthermostatproxy::~testthermostatproxy()
{

}

void testthermostatproxy::test_case1()
{

}

void testthermostatproxy::cleanupTestCase()
{

}

void testthermostatproxy::testUpdateFrequency()
{
    QString name = "Test";
    ThermostatProxy lp(name);
    lp.setUpdateFrequency(20.0);
    QCOMPARE(lp.getUpdateFrequency(),20.0);
}


void testthermostatproxy::testunitofMeasure()
{
    QString name = "Test";
    ThermostatProxy lp(name);
    lp.setUnitofMeasure("F");
    QCOMPARE(lp.unitofMeasure(),"F");
}

void testthermostatproxy::testStartingTemperature()
{
    QString name = "Test";
    ThermostatProxy lp(name);
    lp.setStartingTemperature(20.00);
    QCOMPARE(lp.getStartingTemperature(),20.0);
}

void testthermostatproxy::testlastMeasurement()
{
    QString name = "Test";
    ThermostatProxy lp(name);
    std::string UoM = "F";
    double last = 20.0;
    MeasurementTemplate<double> *mt;
    mt = new MeasurementTemplate<double>(name.toStdString(),"last Measurement",UoM);
    mt->setValue(last);
    lp.setlastMeasurement(20.0);
    lp.setUnitofMeasure("F");
    QCOMPARE(lp.lastMeasurement(),mt);
}

void testthermostatproxy::teststorelastMeasurementsAndLastFiveMeaurements()
{
    QString name = "Test";
    ThermostatProxy lp(name);
    std::string UoM = "F";
    MeasurementTemplate<std::vector<double>> *mt1;
    mt1 = new MeasurementTemplate<std::vector<double>>(name.toStdString(),"last 5 Measurements ",UoM);
    std::vector<double> last5values;
    last5values.push_back(10.0);
    last5values.push_back(20.0);
    last5values.push_back(30.0);
    last5values.push_back(40.0);
    last5values.push_back(50.0);
    mt1->setValue(last5values);

    lp.storelastMeasurements(10.0);
    lp.storelastMeasurements(20.0);
    lp.storelastMeasurements(30.0);
    lp.storelastMeasurements(40.0);
    lp.storelastMeasurements(50.0);

    QCOMPARE(lp.last5Measurement(),mt1);

}

void testthermostatproxy::testsetpoint()
{
    QString name = "Test";
    ThermostatProxy lp(name);
    std::string UoM = "F";
    MeasurementTemplate<double> *mt;
    mt = new MeasurementTemplate<double>(name.toStdString(),"temperature setpoint",UoM);
    mt->setValue(20.0);
    lp.setUnitofMeasure("F");
    lp.setthesetpoint(20.0);

    QCOMPARE(lp.setpoint(),mt);

}

void testthermostatproxy::testcurrentState()
{
    QString name = "Test";
    ThermostatProxy lp(name);
    std::string state = "COOLING";
    MeasurementTemplate<double> *mt;
    mt = new MeasurementTemplate<double>(name.toStdString(),"Current State",state);
    mt->setValue(19.0);
    lp.setthesetpoint(19.0);
    lp.setcurrentstate("COOLING");

    QCOMPARE(lp.currentState(),mt);

}

void testthermostatproxy::testwarmer()
{
    QString name = "Test";
    ThermostatProxy lp(name);
    lp.setthesetpoint(20.0);
    lp.warmer(20.0);
    QCOMPARE(lp.setpoint(), 40.0);
    // if setpoint is zero do nothing
    lp.setthesetpoint(0.0);
    lp.warmer(20.0);
     QCOMPARE(lp.setpoint(), 0.0);

}

void testthermostatproxy::testcooler()
{
    QString name = "Test";
    ThermostatProxy lp(name);
    lp.setthesetpoint(20.0);
    lp.cooler(20.0);
    QCOMPARE(lp.setpoint(), 0.0);
    lp.cooler(20.0);
    QCOMPARE(lp.setpoint(), 0.0);

}

void testthermostatproxy::testrandomDouble()
{
    QString name = "Test";
    ThermostatProxy lp(name);
    lp.setthesetpoint(10.0);
    bool withinrange = false;
    if(lp.randomDouble() >= 10.5 || lp.randomDouble() <= 9.5)
    {
        withinrange = true;
    }
    QCOMPARE(withinrange, true);

}

void testthermostatproxy::testupdate()
{
    QString name = "Test";
    ThermostatProxy lp(name);
    lp.setlastMeasurement(10);
    lp.setthesetpoint(10.5);
    lp.update();
    QCOMPARE(lp.currentState(), "STABLE");
    lp.setlastMeasurement(9.5);
    lp.update();
    QCOMPARE(lp.currentState(), "HEATING");
    lp.setlastMeasurement(11.5);
    lp.update();
    QCOMPARE(lp.currentState(), "COOLING");

}

QTEST_APPLESS_MAIN(testthermostatproxy)

#include "tst_testthermostatproxy.moc"
