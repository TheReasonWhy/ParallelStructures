#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class result_pad_test : public QObject
{
    Q_OBJECT

public:
    result_pad_test();
    ~result_pad_test();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

result_pad_test::result_pad_test()
{

}

result_pad_test::~result_pad_test()
{

}

void result_pad_test::initTestCase()
{

}

void result_pad_test::cleanupTestCase()
{

}

void result_pad_test::test_case1()
{

}

QTEST_MAIN(result_pad_test)

#include "tst_result_pad_test.moc"
