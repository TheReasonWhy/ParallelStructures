#include <QtTest>

// add necessary includes here

class handler_system_test : public QObject
{
    Q_OBJECT

public:
    handler_system_test();
    ~handler_system_test();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

handler_system_test::handler_system_test()
{

}

handler_system_test::~handler_system_test()
{

}

void handler_system_test::initTestCase()
{

}

void handler_system_test::cleanupTestCase()
{

}

void handler_system_test::test_case1()
{

}

QTEST_APPLESS_MAIN(handler_system_test)

#include "tst_handler_system_test.moc"
