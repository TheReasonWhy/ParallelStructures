#include "parallel_set_tests.h"

parallel_set_tests::parallel_set_tests()
{

}

parallel_set_tests::~parallel_set_tests()
{

}

void parallel_set_tests::initTestCase()
{

}

void parallel_set_tests::cleanupTestCase()
{

}

void parallel_set_tests::parallel_set_test_data()
{
    qDebug()<<"... parallel_set_test_data ..."<<endl;

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

void parallel_set_tests::parallel_set_test()
{
    qDebug()<<"... parallel_set_class_test..."<<endl;

    parallel_set<victim, lock_free_queue> PS;

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

    victim res;
    QCOMPARE(PS.try_pop(res),true);
    QCOMPARE(res.get_value(),expected1);
    QCOMPARE(PS.try_pop(res),true);
    QCOMPARE(res.get_value(),expected2);
    QCOMPARE(PS.try_pop(res),true);
    QCOMPARE(res.get_value(),expected3);
    QCOMPARE(PS.try_pop(res),true);
    QCOMPARE(res.get_value(),expected4);
    QCOMPARE(PS.try_pop(res),true);
    QCOMPARE(res.get_value(),expected5);
    QCOMPARE(PS.try_pop(res),true);
    QCOMPARE(res.get_value(),expected6);
    QCOMPARE(PS.try_pop(res),true);
    QCOMPARE(res.get_value(),expected7);

    QCOMPARE(PS.is_empty(),false);
    PS.clear_tree();
    QCOMPARE(PS.is_empty(),true);
    qDebug()<<"... parallel_set_class_test_ends..."<<endl;
}
