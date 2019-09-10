#include <QtTest>

// add necessary includes here

class thread_system_test : public QObject
{
    Q_OBJECT

public:
    thread_system_test();
    ~thread_system_test();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

thread_system_test::thread_system_test()
{

}

thread_system_test::~thread_system_test()
{

}

void thread_system_test::initTestCase()
{

}

void thread_system_test::cleanupTestCase()
{

}

void thread_system_test::test_case1()
{

}

QTEST_APPLESS_MAIN(thread_system_test)

#include "tst_thread_system_test.moc"
