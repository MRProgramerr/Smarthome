#include <QtTest>
#include "lightswitch.h"
// add necessary includes here

/**
 * @brief The LightSwitch testing class
 * The unit testing class for testing
 * the lightswitch smart home device
 */

class lightswitch : public QObject
{
    Q_OBJECT

public:
    lightswitch();
    ~lightswitch();
private:
    LightSwitch ls;
private slots:
    void initTestCase();
    void cleanupTestCase();
    void testturnOn();
    void testturnOff();
    void testID();
    void testIPaddress();
    void testcurrentState();
    void testbrighten();
    void testdim();

};

/**
 * @brief The lightSwitch constructors
 * The constructors created for the light
 * switch testing class
 */

lightswitch::lightswitch() : ls("test")
{

}

lightswitch::~lightswitch()
{

}

/**
 * @brief initTestCase
 * The initial test case to test
 * the working of qt testing
 */

void lightswitch::initTestCase()
{

}

/**
 * @brief initTestCase
 * The final test case to test
 * the working of qt testing
 */
void lightswitch::cleanupTestCase()
{

}

/**
 * @brief testturnOn
 * The test to check whether
 * the turnOn function works
 */
void lightswitch::testturnOn()
{

    ls.turnOff();
        ls.turnOn();
        QCOMPARE(ls.getIsOn(),true);

}

/**
 * @brief testturnOn
 * The test to check whether
 * the turnOff function works
 */
void lightswitch::testturnOff()
{

    ls.turnOn();
    ls.turnOff();
    QCOMPARE(ls.getIsOn(),false);

}

/**
 * @brief testID
 * The test to check whether
 * the DeviceName function works
 */
void lightswitch::testID()
{
    ls.setDeviceName("Light Switch");
    QCOMPARE(ls.getDeviceName(),"Light Switch");
}

/**
 * @brief testIPaddress
 * The test to check whether
 * the IP AddressController function
 * works
 */
void lightswitch::testIPaddress()
{
    ls.setIPAddressController("LS IP");
    QCOMPARE(ls.getIPAddressController(), "LS IP");
}

/**
 * @brief testcurrentState
 * The test to check whether
 * the currentState function works
 */
void lightswitch::testcurrentState()
{

}

/**
 * @brief testbrighten
 * The test to check whether
 * the brighten function works
 */
void lightswitch::testbrighten()
{
    ls.setBrightnessLevel(20);
      ls.brighten();
      QCOMPARE(ls.getBrightnessLevel(),40);
}

/**
 * @brief testdim
 * The test to check whether
 * the dim function works
 */
void lightswitch::testdim()
{
    ls.setBrightnessLevel(100);
        ls.dim();
        QCOMPARE(ls.getBrightnessLevel(),80);
}

QTEST_APPLESS_MAIN(lightswitch)

#include "tst_lightswitch.moc"
