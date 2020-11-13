#include <QtTest>
#include "controller.h"
// add necessary includes here

class tst_controller : public QObject
{
    Q_OBJECT

public:
    tst_controller();
    ~tst_controller();
private:
    Controller c;
private slots:
    void testID();
    void testIPaddress();
    void testcurrentState();
    void testregisteredDevice();
    void testaddFilter();
    void testclearFilter();

};

tst_controller::tst_controller() : c("Ale")
{

}

tst_controller::~tst_controller()
{

}

void tst_controller::testID()
{
    c.setDeviceName("Controller");
    QCOMPARE(c.getDeviceName(), "Controller");
}
void tst_controller::testIPaddress()
{
    c.setIPAddressController("Controller IP");
    QCOMPARE(c.getIPAddressController(), "Controller IP");
}
void tst_controller::testcurrentState()
{

}
void tst_controller::testregisteredDevice()
{

}
void tst_controller::testaddFilter()
{

}
void tst_controller::testclearFilter()
{

}

QTEST_APPLESS_MAIN(tst_controller)

#include "tst_controller.moc"
