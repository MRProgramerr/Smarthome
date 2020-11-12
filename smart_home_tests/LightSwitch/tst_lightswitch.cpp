#include <QtTest>
#include "lightswitch.h"
// add necessary includes here
#include <QString>
#include <iostream>I

class tst_LightSwitch : public QObject
{
    Q_OBJECT

public:
    tst_LightSwitch();
    ~tst_LightSwitch();

    LightSwitch ls;
private slots:
   void testID();
   void testIPaddress();
   void testcurrentState();
   void testbrighten();
   void testdim();
   void testturnOn();
   void testturnOff();



   // Using a macro to ensure the QVERIFY2 has the correct location in the source file
   // Otherwise these tests are not very useful.
   #define equal(expected, actual, failMessage) \
     ++_assertionCount; \
     if (not (expected == actual)) ++_failureCount; \
     QVERIFY2(expected == actual, failMessage);


};


tst_LightSwitch::tst_LightSwitch() : ls("k")
{

}

tst_LightSwitch::~tst_LightSwitch()
{

}

void tst_LightSwitch::testID()
{

}

void tst_LightSwitch::testIPaddress()
{

}

void tst_LightSwitch::testcurrentState()
{

}
void tst_LightSwitch::testbrighten()
{

}
void tst_LightSwitch::testdim()
{

}
void tst_LightSwitch::testturnOn()
{
    ls.turnOff();
    ls.turnOn();
    QCOMPARE(ls.getIsOn(),true);


}
void tst_LightSwitch::testturnOff()
{

}





QTEST_MAIN(tst_LightSwitch)

#include "tst_lightswitch.moc"
