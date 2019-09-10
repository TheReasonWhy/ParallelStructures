#include <QtTest>
#include"victim.h"
#include"example_class.h"
#include<work_generator.hpp>
#include"parallel_stack.hpp"

// add necessary includes here

class work_generator_test : public QObject
{
    Q_OBJECT

public:
    work_generator_test();
    ~work_generator_test();

private slots:
/*    */
    void indexator_test_data();
    void indexator_test();


    void work_generator_test1_data();
    void work_generator_test1();

};

work_generator_test::work_generator_test()
{

}

work_generator_test::~work_generator_test()
{

}

void work_generator_test::indexator_test_data()
{
    qDebug()<<"... indexator_test_data ..."<<endl;
    QTest::addColumn<unsigned>("test_level0");
    QTest::addColumn<unsigned>("test_level1");
    QTest::addColumn<unsigned>("test_level2");
    QTest::addColumn<unsigned>("test_level3");

    QTest::addColumn<unsigned>("test_level4");
    QTest::addColumn<unsigned>("test_level5");
    QTest::addColumn<unsigned>("test_level6");
    QTest::addColumn<unsigned>("test_level7");

    QTest::addColumn<unsigned>("expected_height");

    QTest::addColumn<unsigned>("expected_step_size0");
    QTest::addColumn<unsigned>("expected_step_size1");
    QTest::addColumn<unsigned>("expected_step_size2");
    QTest::addColumn<unsigned>("expected_step_size3");

    QTest::addColumn<unsigned>("expected_step_size4");
    QTest::addColumn<unsigned>("expected_step_size5");
    QTest::addColumn<unsigned>("expected_step_size6");
    QTest::addColumn<unsigned>("expected_step_size7");

    QTest::addColumn<unsigned>("expected_first_position0");
    QTest::addColumn<unsigned>("expected_first_position1");
    QTest::addColumn<unsigned>("expected_first_position2");
    QTest::addColumn<unsigned>("expected_first_position3");

    QTest::addColumn<unsigned>("expected_first_position4");
    QTest::addColumn<unsigned>("expected_first_position5");
    QTest::addColumn<unsigned>("expected_first_position6");
    QTest::addColumn<unsigned>("expected_first_position7");

    QTest::newRow("data_1")<< 0U<< 1U << 2U<< 3U << 4U<< 5U << 6U<< 7U
    << 7U
    << 128U<< 64U << 32U<< 16U << 8U<< 4U << 2U << 0U // step_size
    << 64U<< 32U << 16U<< 8U << 4U<< 2U << 1U << 0U; // first_position
}

void work_generator_test::indexator_test()
{
    qDebug()<<"... indexator_test_test ..."<<endl;

    QFETCH( unsigned, test_level0 );
    QFETCH( unsigned, test_level1);
    QFETCH( unsigned, test_level2 );
    QFETCH( unsigned, test_level3);
    QFETCH( unsigned, test_level4 );
    QFETCH( unsigned, test_level5);
    QFETCH( unsigned, test_level6 );
    QFETCH( unsigned, test_level7);

        QFETCH(unsigned, expected_height);

    QFETCH( unsigned, expected_step_size0);
    QFETCH( unsigned, expected_first_position0 );
    QFETCH( unsigned, expected_step_size1);
    QFETCH( unsigned, expected_first_position1 );
    QFETCH( unsigned, expected_step_size2);
    QFETCH( unsigned, expected_first_position2 );
    QFETCH( unsigned, expected_step_size3);
    QFETCH( unsigned, expected_first_position3 );
    QFETCH( unsigned, expected_step_size4);
    QFETCH( unsigned, expected_first_position4 );
    QFETCH( unsigned, expected_step_size5);
    QFETCH( unsigned, expected_first_position5 );
    QFETCH( unsigned, expected_step_size6);
    QFETCH( unsigned, expected_first_position6 );
    QFETCH( unsigned, expected_step_size7);
    QFETCH( unsigned, expected_first_position7 );

    work_generator <decltype(&example_class<>::index), (&example_class<>::index), example_class<>, 100, parallel_stack> WG;
    size_t expected_capacity(128);
    QCOMPARE(expected_capacity,expected_capacity);
    QCOMPARE(expected_height,expected_height);
    QCOMPARE(WG.indexator_capacity(),expected_capacity);
    QCOMPARE(WG.indexator_height(),expected_height);

    QCOMPARE(WG.indexator_step_size(test_level0),expected_step_size0);
    QCOMPARE(WG.indexator_first_position(test_level0),expected_first_position0);

    QCOMPARE(WG.indexator_step_size(test_level1),expected_step_size1);
    QCOMPARE(WG.indexator_first_position(test_level1),expected_first_position1);

    QCOMPARE(WG.indexator_step_size(test_level2),expected_step_size2);
    QCOMPARE(WG.indexator_first_position(test_level2),expected_first_position2);

    QCOMPARE(WG.indexator_step_size(test_level3),expected_step_size3);
    QCOMPARE(WG.indexator_first_position(test_level3),expected_first_position3);

    QCOMPARE(WG.indexator_step_size(test_level4),expected_step_size4);
    QCOMPARE(WG.indexator_first_position(test_level4),expected_first_position4);

    QCOMPARE(WG.indexator_step_size(test_level5),expected_step_size5);
    QCOMPARE(WG.indexator_first_position(test_level5),expected_first_position5);

    QCOMPARE(WG.indexator_step_size(test_level6),expected_step_size6);
    QCOMPARE(WG.indexator_first_position(test_level6),expected_first_position6);

    QCOMPARE(WG.indexator_step_size(test_level7),expected_step_size7);
    QCOMPARE(WG.indexator_first_position(test_level7),expected_first_position7);

    qDebug()<<"... indexator_test_test ends..."<<endl;
}
/**/
void work_generator_test::work_generator_test1_data()
{
    qDebug()<<"... work_generator_test_data ..."<<endl;
}

void work_generator_test::work_generator_test1()
{
    qDebug()<<"... work_generator_test_starts..."<<endl;

    work_generator <decltype(&victim<>::get_value), (&victim<>::get_value), victim<>, 100,parallel_stack> WG;
    size_t control_capacity(128);

    QCOMPARE(WG.indexator_capacity(),control_capacity);
    parallel_stack<work<decltype(&victim<>::get_value), (&victim<>::get_value), victim<>>> PS;
    WG.commit_all_works();

    PS = WG.create_random_works(5);
    work<decltype(&victim<>::get_value), (&victim<>::get_value), victim<>> W;
    while (!PS.is_empty()) {
        W = *PS.pop().get();
        qDebug()<<" "<< W() <<endl;
    }
    /**/
    qDebug()<<"... work_generator_test_ends..."<<endl;
}

QTEST_APPLESS_MAIN(work_generator_test)

#include "tst_work_generator_test.moc"

