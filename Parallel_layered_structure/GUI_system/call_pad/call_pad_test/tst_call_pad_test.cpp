#include <QtTest>
#include <QCoreApplication>
// add necessary includes here

class call_pad_test : public QObject
{
    Q_OBJECT

public:
    call_pad_test();
    ~call_pad_test();

private slots:
    void test_case1();

};

call_pad_test::call_pad_test()
{

}

call_pad_test::~call_pad_test()
{

}

void call_pad_test::test_case1()
{

}

QTEST_APPLESS_MAIN(call_pad_test)

#include "tst_call_pad_test.moc"
