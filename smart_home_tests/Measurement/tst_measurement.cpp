#include <QtTest>
#include "measurementtemplate.h"
// add necessary includes here

class tst_Measurement : public QObject
{
    Q_OBJECT

public:
    tst_Measurement();
    ~tst_Measurement();
private:
    MeasurementTemplate mt;
private slots:
    void testmeasurementType();
    void testdeviceName();
    void testtempConversion();
    void testminvalConversion();
    void testmaxvalConversion();
    void testexactvalConversion();
    void testtimeStamp();
    void testvalue();
    void testrawMeasurement();
    void testFilters();

};



tst_Measurement::tst_Measurement()
{

}

tst_Measurement::~tst_Measurement()
{

}

void tst_Measurement::testmeasurementType()
{

}
void tst_Measurement::testdeviceName()
{

}
void tst_Measurement::testtempConversion()
{

}
void tst_Measurement::testminvalConversion()
{

}
void tst_Measurement::testmaxvalConversion()
{

}
void tst_Measurement::testexactvalConversion()
{

}
void tst_Measurement::testtimeStamp()
{

}
void tst_Measurement::testvalue()
{

}
void tst_Measurement::testrawMeasurement()
{

}
void tst_Measurement::testFilters()
{

}

QTEST_APPLESS_MAIN(tst_Measurement)

#include "tst_measurement.moc"
