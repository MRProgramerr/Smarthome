#include <QtTest>
#include "measurementtemplate.h"
// add necessary includes here

class measurement : public QObject
{
    Q_OBJECT

public:
    measurement();
    ~measurement();

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

measurement::measurement()
{

}

measurement::~measurement()
{

}

void measurement::testmeasurementType()
{

}
void measurement::testtempConversion()
{

}
void measurement::testdeviceName()
{

}
void measurement::testrawMeasurement()
{

}
void measurement::testvalue()
{

}
void measurement::testFilters()
{

}
void measurement::testtimeStamp()
{

}
void measurement::testmaxvalConversion()
{

}
void measurement::testminvalConversion()
{

}
void measurement::testexactvalConversion()
{

}
QTEST_APPLESS_MAIN(measurement)

#include "tst_measurement.moc"
