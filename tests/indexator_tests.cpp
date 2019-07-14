#include "indexator_tests.h"

indexator_tests::indexator_tests()
{

}

indexator_tests::~indexator_tests()
{

}

void indexator_tests::initTestCase()
{

}

void indexator_tests::cleanupTestCase()
{

}

void indexator_tests::indexator_tests_data()
{
    qDebug()<<"... indexator_test_data ..."<<endl;
/*    QTest::addColumn<unsigned>("test_level0");
    QTest::addColumn<unsigned>("test_level1");
    QTest::addColumn<unsigned>("test_level2");
    QTest::addColumn<unsigned>("test_level3");

    QTest::addColumn<unsigned>("test_level4");
    QTest::addColumn<unsigned>("test_level5");
    QTest::addColumn<unsigned>("test_level6");
    QTest::addColumn<unsigned>("test_level7");
*/
    QTest::addColumn<unsigned>("expected_height");
/*
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
*/
    QTest::newRow("data_1")<< 7U; //<< 0U << 1U<< 2U << 3U<< 4U << 5U<< 6U << 7U

    //<< 0U<< 64U << 32U<< 16U << 8U<< 4U << 2U << 0U // step_size
    //<< 64U<< 32U << 16U<< 8U << 4U<< 2U << 1U << 0U; // first_position
}

void indexator_tests::indexator_tests_test()
{
    qDebug()<<"... indexator_test_test ..."<<endl;
    /*
    QFETCH( unsigned, test_level0 );
    QFETCH( unsigned, test_level1);
    QFETCH( unsigned, test_level2 );
    QFETCH( unsigned, test_level3);
    QFETCH( unsigned, test_level4 );
    QFETCH( unsigned, test_level5);
    QFETCH( unsigned, test_level6 );
    QFETCH( unsigned, test_level7);

        QFETCH(unsigned, expected_height);
*/
    /*QFETCH( unsigned, expected_step_size0);
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
*/
    Factory_abstract<example,100> F;
    std::unique_ptr<example> V1 = F.create_object();
    std::unique_ptr<example> V2 = F.create_object();
    std::unique_ptr<example> V3 = F.create_object();
    //qDebug()<<expected_height<<endl;
    //unsigned S1(0);
    //unsigned S2(1);
    //unsigned S3(2);
 /*   size_t expected_capacity(128);
    QCOMPARE(expected_capacity,expected_capacity);
    QCOMPARE(expected_height,expected_height);
    QCOMPARE(F.indexator_capacity(),expected_capacity);
    QCOMPARE(F.indexator_height(),expected_height);

    QCOMPARE(F.indexator_step_size(test_level0),expected_step_size0);
    QCOMPARE(F.indexator_first_position(test_level0),expected_first_position0);

    QCOMPARE(F.indexator_step_size(test_level1),expected_step_size1);
    QCOMPARE(F.indexator_first_position(test_level1),expected_first_position1);

    QCOMPARE(F.indexator_step_size(test_level2),expected_step_size2);
    QCOMPARE(F.indexator_first_position(test_level2),expected_first_position2);

    QCOMPARE(F.indexator_step_size(test_level3),expected_step_size3);
    QCOMPARE(F.indexator_first_position(test_level3),expected_first_position3);

    QCOMPARE(F.indexator_step_size(test_level4),expected_step_size4);
    QCOMPARE(F.indexator_first_position(test_level4),expected_first_position4);

    QCOMPARE(F.indexator_step_size(test_level5),expected_step_size5);
    QCOMPARE(F.indexator_first_position(test_level5),expected_first_position5);

    QCOMPARE(F.indexator_step_size(test_level6),expected_step_size6);
    QCOMPARE(F.indexator_first_position(test_level6),expected_first_position6);

    QCOMPARE(F.indexator_step_size(test_level7),expected_step_size7);
    QCOMPARE(F.indexator_first_position(test_level7),expected_first_position7);
*/
/*

    Index_type indexator_first_position(Index_type A){
        return indexator::first_position(A);
    }
    Index_type indexator_step_size(Index_type level){
        return indexator::step_size(level);
    }

*/
    //QCOMPARE(V1.get()->index(),S1);
    //QCOMPARE(V2.get()->index(),S2);
    //QCOMPARE(V3.get()->index(),S3);
    qDebug()<<"... indexator_test_test ends..."<<endl;
}
/*
void indexator_tests::indexator_tests2_data()
{
    qDebug()<<"... indexator_tests2_data ..."<<endl;
    QTest::addColumn<unsigned>("expected_height");
    QTest::newRow("data_1")<< 7U; //<< 0U << 1U<< 2U << 3U<< 4U << 5U<< 6U << 7U
}

void indexator_tests::indexator_tests2_test()
{
    qDebug()<<"... indexator_tests2_test ..."<<endl;
    QFETCH(unsigned,expected_height);
    QCOMPARE(expected_height,7U);
    qDebug()<<"... indexator_tests2_test ends ..."<<endl;
}


*/








