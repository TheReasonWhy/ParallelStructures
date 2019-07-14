#include "lock_free_queue_tests.h"

lock_free_queue_tests::lock_free_queue_tests()
{

}

lock_free_queue_tests::~lock_free_queue_tests()
{

}

void lock_free_queue_tests::initTestCase()
{

}

void lock_free_queue_tests::cleanupTestCase()
{

}

void lock_free_queue_tests::lock_free_queue_test_data()
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

void lock_free_queue_tests::lock_free_queue_test()
{
    qDebug()<<"... lock_free_queue_class_test..."<<endl;

    lock_free_queue<victim> PS;

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


    victim V1(input1);
    victim V2(input2);
    victim V3(input3);
    victim V4(input4);
    victim V5(input5);
    victim V6(input6);
    victim V7(input7);

    PS.push(std::move(V1));
    PS.push(std::move(V2));
    PS.push(std::move(V3));
    PS.push(std::move(V4));
    PS.push(std::move(V5));
    PS.push(std::move(V6));
    PS.push(std::move(V7));

    QCOMPARE(PS.pop().get()->get_value(),expected1);
    QCOMPARE(PS.pop().get()->get_value(),expected2);
    QCOMPARE(PS.pop().get()->get_value(),expected3);
    QCOMPARE(PS.pop().get()->get_value(),expected4);
    QCOMPARE(PS.pop().get()->get_value(),expected5);
    QCOMPARE(PS.pop().get()->get_value(),expected6);
    QCOMPARE(PS.pop().get()->get_value(),expected7);



    QCOMPARE(PS.is_empty(),true);
    qDebug()<<"... lock_free_queue_class_test ends..."<<endl;
}
