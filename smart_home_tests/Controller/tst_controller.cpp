#include <QtTest>
#include "controller.h"
// add necessary includes here

class controller : public QObject
{
    Q_OBJECT
private:
    Controller sc;
public:
    controller();
    ~controller();

private slots:
    void testID();
        void testIPaddress();
        void testcurrentState();
        void testregisteredDevice();
        void testaddFilter();
        void testclearFilter();

};

controller::controller() : sc("test5")
{


}

controller::~controller()
{

}

void controller::testID()
{
    sc.setDeviceName("Smart Home Controller");
    QCOMPARE(sc.getDeviceName(), "Smart Home Controller");
}

void controller::testIPaddress()
{
    sc.setIPAddressController("SHC IP");
    QCOMPARE(sc.getIPAddressController(), "SHC IP");
}

void controller::testcurrentState()
{

}

void controller::testregisteredDevice()
{

}

void controller::testaddFilter()
{

}

void controller::testclearFilter()
{

}


QTEST_APPLESS_MAIN(controller)

#include "tst_controller.moc"
