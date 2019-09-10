#include <QtTest>
#include<multiple_arrays_storage.hpp>
// add necessary includes here

class multiple_arrays_storage_test : public QObject
{
    Q_OBJECT

public:
    multiple_arrays_storage_test();
    ~multiple_arrays_storage_test();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1_data();
    void test_case1();

};

multiple_arrays_storage_test::multiple_arrays_storage_test()
{

}

multiple_arrays_storage_test::~multiple_arrays_storage_test()
{

}

void multiple_arrays_storage_test::initTestCase()
{

}

void multiple_arrays_storage_test::cleanupTestCase()
{

}

void multiple_arrays_storage_test::test_case1_data()
{

    qDebug()<<"... test_case1_data ..."<<endl;

    QTest::addColumn<unsigned>("expected1");
    QTest::addColumn<unsigned>("expected2");
    QTest::addColumn<unsigned>("expected3");
    QTest::addColumn<unsigned>("expected4");
    QTest::addColumn<unsigned>("expected5");
    QTest::addColumn<unsigned>("expected6");
    QTest::addColumn<unsigned>("expected7");
    QTest::addColumn<unsigned>("expected8");
    QTest::addColumn<unsigned>("expected9");
    QTest::newRow("row1") << 11U << 12U<< 13U << 14U<< 15U << 16U<< 17U << 18U<< 19U;
}

void multiple_arrays_storage_test::test_case1()
{

    QFETCH( unsigned, expected1);
    QFETCH( unsigned, expected2);
    QFETCH( unsigned, expected3);
    QFETCH( unsigned, expected4);
    QFETCH( unsigned, expected5);
    QFETCH( unsigned, expected6);
    QFETCH( unsigned, expected7);
    QFETCH( unsigned, expected8);
    QFETCH( unsigned, expected9);
    const size_t A1 (2);
    const size_t A2 (3);
    const size_t A3 (4);
    //unsigned U1(3);<Type, size, size, size ...>
    //unsigned U2(4);
    //unsigned U3(5);
    std::array<unsigned,A1> V1{11,12};
    std::array<unsigned,A2> V2{13,14,15};
    std::array<unsigned,A3> V3{16,17,18,19};
    multiple_arrays_storage<std::array<unsigned,A1>,std::array<unsigned,A2>,std::array<unsigned,A3>> TC(V1,V2,V3);
    std::cout<<get_value_by_index<0>(TC,0)<<std::endl;
    std::cout<<get_value_by_index<0>(TC,1)<<std::endl;
    std::cout<<get_value_by_index<1>(TC,0)<<std::endl;
    std::cout<<get_value_by_index<1>(TC,1)<<std::endl;
    std::cout<<get_value_by_index<1>(TC,2)<<std::endl;
    std::cout<<get_value_by_index<2>(TC,0)<<std::endl;
    std::cout<<get_value_by_index<2>(TC,1)<<std::endl;
    std::cout<<get_value_by_index<2>(TC,2)<<std::endl;
    std::cout<<get_value_by_index<2>(TC,3)<<std::endl;
    QCOMPARE(get_value_by_index<0>(TC,0),expected1);
    QCOMPARE(get_value_by_index<0>(TC,1),expected2);
    QCOMPARE(get_value_by_index<1>(TC,0),expected3);
    QCOMPARE(get_value_by_index<1>(TC,1),expected4);
    QCOMPARE(get_value_by_index<1>(TC,2),expected5);
    QCOMPARE(get_value_by_index<2>(TC,0),expected6);
    QCOMPARE(get_value_by_index<2>(TC,1),expected7);
    QCOMPARE(get_value_by_index<2>(TC,2),expected8);
    QCOMPARE(get_value_by_index<2>(TC,3),expected9);
}

QTEST_APPLESS_MAIN(multiple_arrays_storage_test)

#include "tst_multiple_arrays_storage_test.moc"
