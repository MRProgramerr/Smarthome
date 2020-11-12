#include <QtTest>

// add necessary includes here

class Measurement : public QObject
{
    Q_OBJECT

public:
    Measurement();
    ~Measurement();

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

// Using a macro to ensure the QVERIFY2 has the correct location in the source file
// Otherwise these tests are not very useful.
#define equal(expected, actual, failMessage) \
  ++_assertionCount; \
  if (not (expected == actual)) ++_failureCount; \
  QVERIFY2(expected == actual, failMessage);


Measurement::Measurement()
{

}

Measurement::~Measurement()
{

}

void Measurement::testmeasurementType()
{

}
void Measurement::testdeviceName()
{

}
void Measurement::testtempConversion()
{

}
void Measurement::testminvalConversion()
{

}
void Measurement::testmaxvalConversion()
{

}
void Measurement::testexactvalConversion()
{

}
void Measurement::testtimeStamp()
{

}
void Measurement::testvalue()
{

}
void Measurement::testrawMeasurement()
{

}
void Measurement::testFilters()
{

}

QTEST_APPLESS_MAIN(Measurement)

//#include "tst_measurement.moc"
