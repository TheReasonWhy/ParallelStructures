#include <QtTest>
#include<work_system.hpp>
// add necessary includes here

class level_system_test : public QObject
{
    Q_OBJECT

public:
    level_system_test();
    ~level_system_test();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

level_system_test::level_system_test()
{

}

level_system_test::~level_system_test()
{

}

void level_system_test::initTestCase()
{

}

void level_system_test::cleanupTestCase()
{

}

void level_system_test::test_case1()
{

    Work_system<4,30,370,100> WS (1,"intervals.txt","layered_data.txt","connections.txt");
    unsigned sum1 = WS.get_sum_recursive(0,0,0);

    WS.try_push_element(0,0);
    unsigned sum2 = WS.process(0);
    qDebug()<< "sum1 "<<sum1 << endl;
    qDebug()<< "sum2 "<<sum2 << endl;
    QCOMPARE(sum1,sum2);
    WS.call_move(68,158);
    sum1 = WS.get_sum_recursive(0,0,0);
    WS.try_push_element(0,0);
    sum2 = WS.process(0);
    qDebug()<< "sum1 "<<sum1 << endl;
    qDebug()<< "sum2 "<<sum2 << endl;
    QCOMPARE(sum1,sum2);
    WS.try_push_move(2,68,168);
    sum2 = WS.process(0);
    WS.try_push_element(0,0);
    sum2 = WS.process(0);
    sum1 = WS.get_sum_recursive(0,0,0);
    qDebug()<< "sum1 "<<sum1 << endl;
    qDebug()<< "sum2 "<<sum2 << endl;
    QCOMPARE(sum1,sum2);
}

QTEST_APPLESS_MAIN(level_system_test)

#include "tst_level_system_test.moc"
