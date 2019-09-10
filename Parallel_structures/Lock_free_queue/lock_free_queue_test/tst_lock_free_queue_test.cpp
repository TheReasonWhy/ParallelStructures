#include <QtTest>
#include<lock_free_queue.hpp>
#include<victim.h>
#include<lock_free_queue_unique_lock.hpp>
// add necessary includes here

class lock_free_queue_test : public QObject
{
    Q_OBJECT

public:
    lock_free_queue_test();
    ~lock_free_queue_test();

private slots:
    void LFQ_test_data();
    void LFQ_test();
    void LFQ_Unique_lock_test_data();
    void LFQ_Unique_lock_test();

};

lock_free_queue_test::lock_free_queue_test()
{

}

lock_free_queue_test::~lock_free_queue_test()
{

}

void lock_free_queue_test::LFQ_test_data()
{
    qDebug()<<"... lock_free_queue_test_data ..."<<endl;

    QTest::addColumn<unsigned>("input1");
    QTest::addColumn<unsigned>("input2");
    QTest::addColumn<unsigned>("input3");
    QTest::addColumn<unsigned>("input4");
    QTest::addColumn<unsigned>("input5");
    QTest::addColumn<unsigned>("input6");
    QTest::addColumn<unsigned>("input7");
    QTest::addColumn<unsigned>("expected1");
    QTest::addColumn<unsigned>("expected2");
    QTest::addColumn<unsigned>("expected3");
    QTest::addColumn<unsigned>("expected4");
    QTest::addColumn<unsigned>("expected5");
    QTest::addColumn<unsigned>("expected6");
    QTest::addColumn<unsigned>("expected7");
    QTest::newRow("data_1") << 1U << 2U << 3U << 4U << 5U << 6U << 7U << 1U << 2U << 3U << 4U << 5U << 6U << 7U;
}

void lock_free_queue_test::LFQ_test()
{
    qDebug()<<"... lock_free_queue_class_test..."<<endl;

        lock_free_queue<victim<>> PS;

    QFETCH( unsigned, input1 );
    QFETCH( unsigned, expected1);
    QFETCH( unsigned, input2 );
    QFETCH( unsigned, expected2);
    QFETCH( unsigned, input3 );
    QFETCH( unsigned, expected3);
    QFETCH( unsigned, input4 );
    QFETCH( unsigned, expected4);
    QFETCH( unsigned, input5 );
    QFETCH( unsigned, expected5);
    QFETCH( unsigned, input6 );
    QFETCH( unsigned, expected6);
    QFETCH( unsigned, input7 );
    QFETCH( unsigned, expected7);


    victim<> V1(input1);
    victim<> V2(input2);
    victim<> V3(input3);
    victim<> V4(input4);
    victim<> V5(input5);
    victim<> V6(input6);
    victim<> V7(input7);

    victim<> res;
    //QCOMPARE(PS.try_pop(res),false);

    PS.push(std::move(V1));
    QCOMPARE(PS.try_pop(res),true);
    QCOMPARE(res.get_value(),expected1);
    PS.push(std::move(V2));
    PS.push(std::move(V3));
    PS.push(std::move(V4));
    PS.push(std::move(V5));
    PS.push(std::move(V6));
    PS.push(std::move(V7));



    QCOMPARE(PS.pop().get()->get_value(),expected2);
    QCOMPARE(PS.pop().get()->get_value(),expected3);
    QCOMPARE(PS.pop().get()->get_value(),expected4);
    QCOMPARE(PS.pop().get()->get_value(),expected5);
    QCOMPARE(PS.pop().get()->get_value(),expected6);
    QCOMPARE(PS.pop().get()->get_value(),expected7);



    QCOMPARE(PS.is_empty(),true);


/**/
    qDebug()<<"... lock_free_queue_class_test ends..."<<endl;
}



void lock_free_queue_test::LFQ_Unique_lock_test_data()
{
    qDebug()<<"... LFQ_Unique_lock_test_data ..."<<endl;

    QTest::addColumn<unsigned>("input1");
    QTest::addColumn<unsigned>("input2");
    QTest::addColumn<unsigned>("input3");
    QTest::addColumn<unsigned>("input4");
    QTest::addColumn<unsigned>("input5");
    QTest::addColumn<unsigned>("input6");
    QTest::addColumn<unsigned>("input7");
    QTest::addColumn<unsigned>("expected1");
    QTest::addColumn<unsigned>("expected2");
    QTest::addColumn<unsigned>("expected3");
    QTest::addColumn<unsigned>("expected4");
    QTest::addColumn<unsigned>("expected5");
    QTest::addColumn<unsigned>("expected6");
    QTest::addColumn<unsigned>("expected7");
    QTest::newRow("data_1") << 1U << 2U << 3U << 4U << 5U << 6U << 7U << 1U << 2U << 3U << 4U << 5U << 6U << 7U;
}

void lock_free_queue_test::LFQ_Unique_lock_test()
{
    qDebug()<<"... LFQ_Unique_lock_test..."<<endl;

        lock_free_queue_unique_lock<victim<>> PS;

    QFETCH( unsigned, input1 );
    QFETCH( unsigned, expected1);
    QFETCH( unsigned, input2 );
    QFETCH( unsigned, expected2);
    QFETCH( unsigned, input3 );
    QFETCH( unsigned, expected3);
    QFETCH( unsigned, input4 );
    QFETCH( unsigned, expected4);
    QFETCH( unsigned, input5 );
    QFETCH( unsigned, expected5);
    QFETCH( unsigned, input6 );
    QFETCH( unsigned, expected6);
    QFETCH( unsigned, input7 );
    QFETCH( unsigned, expected7);


    victim<> V1(input1);
    victim<> V2(input2);
    victim<> V3(input3);
    victim<> V4(input4);
    victim<> V5(input5);
    victim<> V6(input6);
    victim<> V7(input7);

    victim<> res1;
    victim<> res2;
    victim<> res3;
    victim<> res4;
    victim<> res5;
    victim<> res6;
    victim<> res7;
    //QCOMPARE(PS.try_pop(res),false);

    PS.push(std::move(V1));
    QCOMPARE(PS.try_pop(res1),true);
    QCOMPARE(res1.get_value(),expected1);
    PS.push(std::move(V2));

    PS.push(std::move(V3));
    PS.push(std::move(V4));
    PS.push(std::move(V5));
    PS.push(std::move(V6));
    PS.push(std::move(V7));

    QCOMPARE(PS.try_pop(res2),true);
    QCOMPARE(res2.get_value(),expected7);
    QCOMPARE(PS.try_pop(res3),true);
    QCOMPARE(res3.get_value(),expected6);
    QCOMPARE(PS.try_pop(res4),true);
    QCOMPARE(res4.get_value(),expected5);
    QCOMPARE(PS.try_pop(res5),true);
    QCOMPARE(res5.get_value(),expected4);
    QCOMPARE(PS.try_pop(res6),true);
    QCOMPARE(res6.get_value(),expected3);
    QCOMPARE(PS.try_pop(res7),true);
    QCOMPARE(res7.get_value(),expected2);

    QCOMPARE(PS.is_empty(),true);


/**/
    qDebug()<<"... lock_free_queue_class_test ends..."<<endl;
}
QTEST_APPLESS_MAIN(lock_free_queue_test)

#include "tst_lock_free_queue_test.moc"
