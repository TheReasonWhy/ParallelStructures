#include <QtTest>
#include<parallel_binary_tree.hpp>
#include<victim.h>
// add necessary includes here

class parallel_binary_tree_test : public QObject
{
    Q_OBJECT

public:
    parallel_binary_tree_test();
    ~parallel_binary_tree_test();

private slots:
    void binary_tree_test_data();
    void binary_tree_test();

};

parallel_binary_tree_test::parallel_binary_tree_test()
{

}

parallel_binary_tree_test::~parallel_binary_tree_test()
{

}

void parallel_binary_tree_test::binary_tree_test_data()
{
    qDebug()<<"... binary_tree_test_data ..."<<endl;

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
    QTest::newRow("data_1") << 1U << 2U << 3U << 4U << 5U << 6U << 7U << 7U << 6U << 5U << 4U << 3U << 2U << 1U;
    QTest::newRow("data_2") << 1U << 2U << 3U << 4U << 5U << 6U << 7U << 7U << 6U << 5U << 4U << 3U << 2U << 1U;
    QTest::newRow("data_3") << 7U << 6U << 5U << 4U << 3U << 2U << 1U << 1U << 2U << 3U << 4U << 5U << 6U << 7U;
    QTest::newRow("data_4") << 4U << 5U << 3U << 6U << 2U << 7U << 1U << 7U << 6U << 5U << 1U << 2U << 3U << 4U;
    QTest::newRow("data_5") << 4U << 6U << 2U << 5U << 1U << 3U << 7U << 7U << 5U << 6U << 3U << 1U << 2U << 4U;
}

void parallel_binary_tree_test::binary_tree_test()
{
    qDebug()<<"... binary_tree_class_test..."<<endl;
    parallel_binary_tree<victim<>> B;
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

    std::unique_ptr<victim<>> V1 = std::make_unique<victim<>>(input1);
    std::unique_ptr<victim<>> V2 = std::make_unique<victim<>>(input2);
    std::unique_ptr<victim<>> V3 = std::make_unique<victim<>>(input3);
    std::unique_ptr<victim<>> V4 = std::make_unique<victim<>>(input4);
    std::unique_ptr<victim<>> V5 = std::make_unique<victim<>>(input5);
    std::unique_ptr<victim<>> V6 = std::make_unique<victim<>>(input6);
    std::unique_ptr<victim<>> V7 = std::make_unique<victim<>>(input7);

    QCOMPARE(B.push(V1.get()->get_value()), true);
    QCOMPARE(B.push(V2.get()->get_value()), true);
    QCOMPARE(B.push(V3.get()->get_value()), true);
    QCOMPARE(B.push(V4.get()->get_value()), true);
    QCOMPARE(B.push(V5.get()->get_value()), true);
    QCOMPARE(B.push(V6.get()->get_value()), true);
    QCOMPARE(B.push(V7.get()->get_value()), true);

    unsigned res(0);
    QCOMPARE(B.pop(res), true);
    QCOMPARE(res, expected1);
    QCOMPARE(B.pop(res), true);
    QCOMPARE(res, expected2);
    QCOMPARE(B.pop(res), true);
    QCOMPARE(res, expected3);
    QCOMPARE(B.pop(res), true);
    QCOMPARE(res, expected4);
    QCOMPARE(B.pop(res), true);
    QCOMPARE(res, expected5);
    QCOMPARE(B.pop(res), true);
    QCOMPARE(res, expected6);
    QCOMPARE(B.pop(res), true);
    QCOMPARE(res, expected7);
    QCOMPARE(B.is_empty(), true);
    qDebug()<<"... res..."<< res <<endl;
}

QTEST_APPLESS_MAIN(parallel_binary_tree_test)

#include "tst_parallel_binary_tree_test.moc"
