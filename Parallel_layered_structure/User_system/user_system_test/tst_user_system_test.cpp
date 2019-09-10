#include <QtTest>

// add necessary includes here

class user_system_test : public QObject
{
    Q_OBJECT

public:
    user_system_test();
    ~user_system_test();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

user_system_test::user_system_test()
{

}

user_system_test::~user_system_test()
{

}

void user_system_test::initTestCase()
{

}

void user_system_test::cleanupTestCase()
{

}

void user_system_test::test_case1()
{

}

QTEST_APPLESS_MAIN(user_system_test)

#include "tst_user_system_test.moc"
