#include <QtTest>

// add necessary includes here

class measurement : public QObject
{
    Q_OBJECT

public:
    measurement();
    ~measurement();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

measurement::measurement()
{

}

measurement::~measurement()
{

}

void measurement::initTestCase()
{

}

void measurement::cleanupTestCase()
{

}

void measurement::test_case1()
{

}

QTEST_APPLESS_MAIN(measurement)

#include "tst_measurement.moc"
