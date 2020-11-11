#include <QtTest>

// add necessary includes here

class Controller : public QObject
{
    Q_OBJECT

public:
    Controller();
    ~Controller();

private slots:
    void testID();
    void testIPaddress();
    void testcurrentState();
    void testregisteredDevice();
    void testaddFilter();
    void testclearFilter();
};

Controller::Controller()
{

}
Controller::~Controller()
{

}

void Controller::testID()
{

}
void Controller::testIPaddress()
{

}
void Controller::testcurrentState()
{

}
void Controller::testregisteredDevice()
{

}
void Controller::testaddFilter()
{

}
void Controller::testclearFilter()
{

}

#include "tst_Controller.moc"
