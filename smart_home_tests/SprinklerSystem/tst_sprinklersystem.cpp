#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class tst_sprinklersystem : public QObject
{
    Q_OBJECT

public:
    tst_sprinklersystem();
    ~tst_sprinklersystem();

private slots:
    void testID();
    void testIPaddress();
    void testcurrentState();
    void testturnOn();
    void testturnOff();
    void testschedule();
    void testwaterUsage();
};


// Using a macro to ensure the QVERIFY2 has the correct location in the source file
// Otherwise these tests are not very useful.
#define equal(expected, actual, failMessage) \
  ++_assertionCount; \
  if (not (expected == actual)) ++_failureCount; \
  QVERIFY2(expected == actual, failMessage);


tst_sprinklersystem::tst_sprinklersystem()
{

}

tst_sprinklersystem::~tst_sprinklersystem()
{

}
void tst_sprinklersystem::testID()
{

}
void tst_sprinklersystem::testIPaddress()
{

}
void tst_sprinklersystem::testcurrentState()
{

}
void tst_sprinklersystem::testturnOn()
{

}
void tst_sprinklersystem::testturnOff()
{

}
void tst_sprinklersystem::testschedule()
{

}
void tst_sprinklersystem::testwaterUsage()
{

}



QTEST_MAIN(tst_sprinklersystem)

#include "tst_sprinklersystem.moc"
