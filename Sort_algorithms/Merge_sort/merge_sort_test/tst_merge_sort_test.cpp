#include <QtTest>
#include<merge_sort.hpp>

// add necessary includes here

class merge_sort_test : public QObject
{
    Q_OBJECT

public:
    merge_sort_test();
    ~merge_sort_test();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1_data();
    void test_case1();

};

merge_sort_test::merge_sort_test()
{

}

merge_sort_test::~merge_sort_test()
{

}

void merge_sort_test::initTestCase()
{

}

void merge_sort_test::cleanupTestCase()
{

}

void merge_sort_test::test_case1_data()
{
    qDebug()<<"... parallel_stack_test_data ..."<<endl;

    QTest::addColumn<unsigned>("input1");
    QTest::addColumn<unsigned>("input2");
    QTest::addColumn<unsigned>("input3");
    QTest::addColumn<unsigned>("input4");
    QTest::addColumn<unsigned>("input5");
    QTest::addColumn<unsigned>("input6");
    QTest::addColumn<unsigned>("input7");
    QTest::addColumn<unsigned>("input8");
    QTest::addColumn<unsigned>("input9");
    QTest::addColumn<unsigned>("input10");
    QTest::addColumn<unsigned>("input11");
    QTest::addColumn<unsigned>("input12");
    QTest::addColumn<unsigned>("input13");
    QTest::addColumn<unsigned>("input14");

    QTest::addColumn<unsigned>("expected1");
    QTest::addColumn<unsigned>("expected2");
    QTest::addColumn<unsigned>("expected3");
    QTest::addColumn<unsigned>("expected4");
    QTest::addColumn<unsigned>("expected5");
    QTest::addColumn<unsigned>("expected6");
    QTest::addColumn<unsigned>("expected7");
    QTest::addColumn<unsigned>("expected8");
    QTest::addColumn<unsigned>("expected9");
    QTest::addColumn<unsigned>("expected10");
    QTest::addColumn<unsigned>("expected11");
    QTest::addColumn<unsigned>("expected12");
    QTest::addColumn<unsigned>("expected13");
    QTest::addColumn<unsigned>("expected14");
    QTest::newRow("data_1") << 11U << 1U << 13U << 8U << 9U << 12U << 5U << 7U << 6U << 10U << 14U << 3U << 2U << 4U
                                << 1U << 2U << 3U << 4U << 5U << 6U << 7U << 8U << 9U << 10U << 11U << 12U << 13U << 14U;
}

void merge_sort_test::test_case1()
{
    qDebug()<<"... parallel_stack_class_test..."<<endl;

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
    QFETCH( unsigned, input8 );
    QFETCH( unsigned, expected8);
    QFETCH( unsigned, input9 );
    QFETCH( unsigned, expected9);
    QFETCH( unsigned, input10 );
    QFETCH( unsigned, expected10);
    QFETCH( unsigned, input11 );
    QFETCH( unsigned, expected11);
    QFETCH( unsigned, input12 );
    QFETCH( unsigned, expected12);
    QFETCH( unsigned, input13 );
    QFETCH( unsigned, expected13);
    QFETCH( unsigned, input14 );
    QFETCH( unsigned, expected14);

    std::vector<unsigned> test_vec = {input1,input2,input3,input4,input5,input6,
                                          input7,input8,input9,input10,input11,input12,
                                          input13,input14};
    Merge_sort<unsigned>::sort(test_vec);

    /**/
    QCOMPARE(test_vec.at(0),expected1);
    QCOMPARE(test_vec.at(1),expected2);
    QCOMPARE(test_vec.at(2),expected3);
    QCOMPARE(test_vec.at(3),expected4);
    QCOMPARE(test_vec.at(4),expected5);
    QCOMPARE(test_vec.at(5),expected6);
    QCOMPARE(test_vec.at(6),expected7);
    QCOMPARE(test_vec.at(7),expected8);
    QCOMPARE(test_vec.at(8),expected9);
    QCOMPARE(test_vec.at(9),expected10);
    QCOMPARE(test_vec.at(10),expected11);
    QCOMPARE(test_vec.at(11),expected12);
    QCOMPARE(test_vec.at(12),expected13);
    QCOMPARE(test_vec.at(13),expected14);

    qDebug()<<"... parallel_stack_class_test_ends..."<<endl;
}

QTEST_APPLESS_MAIN(merge_sort_test)

#include "tst_merge_sort_test.moc"
