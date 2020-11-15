#include <QtTest>
#include "measurementtemplate.h"
#include "abstractmeasurement.h"

// add necessary includes here

class MeasurementTest : public QObject
{
    Q_OBJECT

public:
    MeasurementTest();
    ~MeasurementTest();

private slots:

    void deviceNameTest();
    void unitOfMeasureTest();
    void isFilteredTest();
    void measurementDoubleTest();

};

MeasurementTest::MeasurementTest()
{

}

MeasurementTest::~MeasurementTest()
{

}

void MeasurementTest::deviceNameTest()
{

    MeasurementTemplate<int> test("LightSwitch","","");
    QCOMPARE(test.deviceName(),"LightSwitch");

}

void MeasurementTest::unitOfMeasureTest()
{

    MeasurementTemplate<int> test("LightSwitch","","C");
    QCOMPARE(test.unitofMeasure(),"C");

}

void MeasurementTest::isFilteredTest()
{
    MeasurementTemplate<int> test("LightSwitch","","C");
    test.setIsFiltered(true);
    QCOMPARE(test.isFiltered(),true);
}

void MeasurementTest::measurementDoubleTest()
{
    QVariant q{1.66};
    MeasurementTemplate<double> test("LightSwitch","Brightness","");
    test.setPrecision(10);
    test.setValue(1.6567847);

    QCOMPARE(test.value(),q);

}


QTEST_APPLESS_MAIN(MeasurementTest)

#include "tst_measurementtest.moc"
