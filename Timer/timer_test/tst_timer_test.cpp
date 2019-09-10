#include <QtTest>
#include"timer.h"
// add necessary includes here

class timer_test : public QObject
{
    Q_OBJECT

public:
    timer_test();
    ~timer_test();

private slots:
    void test_case1();

};

timer_test::timer_test()
{

}

timer_test::~timer_test()
{

}

void timer_test::test_case1()
{

    Timer T;
    T.reset();
    T.start();
    qDebug()<<"Waiting"<<endl;
    T.finish();
    qDebug()<<T.get_value()<<endl;
    T.reset();
    T.start();
    qDebug()<<"Waiting"<<endl;
    T.finish();
    qDebug()<<T.get_value()<<endl;
    //QCOMPARE(T.get_value(),T.get_value());
/**/

}

QTEST_APPLESS_MAIN(timer_test)

#include "tst_timer_test.moc"
