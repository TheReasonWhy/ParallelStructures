#include <QtTest>
#include"binary_tree.hpp"

// add necessary includes here

class binary_tree_test : public QObject
{
    Q_OBJECT

public:
    binary_tree_test();
    ~binary_tree_test();

private slots:
    void insert_pop_test_data();
    void insert_pop_test();
    void insert_unique_pop_test_data();
    void insert_unique_pop_test();
    void merge_with_test_data();
    void merge_with_test();

};

binary_tree_test::binary_tree_test()
{

}

binary_tree_test::~binary_tree_test()
{

}


void binary_tree_test::insert_pop_test_data()
{
    qDebug()<<"... insert_pop_test_data ..."<<endl;

    QTest::addColumn<unsigned>("key1");
    QTest::addColumn<unsigned>("value1");
    QTest::addColumn<unsigned>("key2");
    QTest::addColumn<unsigned>("value2");
    QTest::addColumn<unsigned>("key3");
    QTest::addColumn<unsigned>("value3");
    QTest::addColumn<unsigned>("key4");
    QTest::addColumn<unsigned>("value4");
    QTest::addColumn<unsigned>("key5");
    QTest::addColumn<unsigned>("value5");

    QTest::addColumn<unsigned>("key6");
    QTest::addColumn<unsigned>("value6");
    QTest::addColumn<unsigned>("key7");
    QTest::addColumn<unsigned>("value7");
    QTest::addColumn<unsigned>("key8");
    QTest::addColumn<unsigned>("value8");
    QTest::addColumn<unsigned>("key9");
    QTest::addColumn<unsigned>("value9");
    QTest::addColumn<unsigned>("key10");
    QTest::addColumn<unsigned>("value10");

    QTest::addColumn<unsigned>("key11");
    QTest::addColumn<unsigned>("value11");
    QTest::addColumn<unsigned>("key12");
    QTest::addColumn<unsigned>("value12");
    QTest::addColumn<unsigned>("key13");
    QTest::addColumn<unsigned>("value13");
    QTest::addColumn<unsigned>("key14");
    QTest::addColumn<unsigned>("value14");
    QTest::addColumn<unsigned>("key15");
    QTest::addColumn<unsigned>("value15");
    QTest::addColumn<unsigned>("expected_key_1");
    QTest::addColumn<unsigned>("expected_key_2");
    QTest::addColumn<unsigned>("expected_key_3");
    QTest::addColumn<unsigned>("expected_key_4");
    QTest::addColumn<unsigned>("expected_key_5");

    QTest::addColumn<unsigned>("expected_key_6");
    QTest::addColumn<unsigned>("expected_key_7");
    QTest::addColumn<unsigned>("expected_key_8");
    QTest::addColumn<unsigned>("expected_key_9");
    QTest::addColumn<unsigned>("expected_key_10");

    QTest::addColumn<unsigned>("expected_key_11");
    QTest::addColumn<unsigned>("expected_key_12");
    QTest::addColumn<unsigned>("expected_key_13");
    QTest::addColumn<unsigned>("expected_key_14");
    QTest::addColumn<unsigned>("expected_key_15");
    QTest::newRow("data_1") << 1U << 2300U<< 2U << 2400U<< 3U << 2500U<< 4U << 2600U<< 5U << 2700U
                               << 10U << 2300U<< 9U << 2400U<< 8U << 2500U<< 7U << 2600U<< 6U << 2700U
                                  << 20U << 2300U<< 16U << 2400U<< 19U << 2500U<< 17U << 2600U<< 18U << 2700U
                               << 6U << 7U << 8U << 9U << 18U
                               << 17U << 19U << 16U << 20U << 10U
                               << 5U << 4U << 3U << 2U << 1U;
    QTest::newRow("data_2") << 11U << 2300U<< 2U << 2400U<< 30U << 2500U<< 4U << 2600U<< 50U << 2700U
                            << 10U << 2300U<< 9U << 2400U<< 18U << 2500U<< 7U << 2600U<< 600U << 2700U
                               << 200U << 2300U<< 16U << 2400U<< 1U << 2500U<< 2U << 2600U<< 44U << 2700U
                            << 1U << 2U << 7U << 9U << 10U
                            << 4U << 2U << 16U << 18U << 44U
                            << 200U << 600U << 50U << 30U << 11U;

    QTest::newRow("data_3") << 1000U << 2300U<< 500U << 2400U<< 1500U << 2500U<< 4U << 2600U<< 150U << 2700U
                            << 1710U << 2300U<< 900U << 2400U<< 389U << 2500U<< 780U << 2600U<< 1600U << 2700U
                               << 2000U << 2300U<< 16U << 2400U<< 519U << 2500U<< 1117U << 2600U<< 218U << 2700U
                            << 16U << 218U << 389U << 150U << 4U
                            << 519U << 780U << 900U << 500U << 1117U
                            << 1600U << 2000U << 1710U << 1500U << 1000U;
}

void binary_tree_test::insert_pop_test()
{
    qDebug()<<"... insert_pop_test..."<<endl;
    QFETCH( unsigned, key1 ); QFETCH( unsigned, value1);
    QFETCH( unsigned, key2 ); QFETCH( unsigned, value2);
    QFETCH( unsigned, key3 ); QFETCH( unsigned, value3);
    QFETCH( unsigned, key4 ); QFETCH( unsigned, value4);
    QFETCH( unsigned, key5 ); QFETCH( unsigned, value5);
    QFETCH( unsigned, key6 ); QFETCH( unsigned, value6);
    QFETCH( unsigned, key7 ); QFETCH( unsigned, value7);
    QFETCH( unsigned, key8 ); QFETCH( unsigned, value8);
    QFETCH( unsigned, key9 ); QFETCH( unsigned, value9);
    QFETCH( unsigned, key10 ); QFETCH( unsigned, value10);
    QFETCH( unsigned, key11 ); QFETCH( unsigned, value11);
    QFETCH( unsigned, key12 ); QFETCH( unsigned, value12);
    QFETCH( unsigned, key13 ); QFETCH( unsigned, value13);
    QFETCH( unsigned, key14 ); QFETCH( unsigned, value14);
    QFETCH( unsigned, key15 ); QFETCH( unsigned, value15);
    QFETCH( unsigned, expected_key_1);
    QFETCH( unsigned, expected_key_2);
    QFETCH( unsigned, expected_key_3);
    QFETCH( unsigned, expected_key_4);
    QFETCH( unsigned, expected_key_5);
    QFETCH( unsigned, expected_key_6);
    QFETCH( unsigned, expected_key_7);
    QFETCH( unsigned, expected_key_8);
    QFETCH( unsigned, expected_key_9);
    QFETCH( unsigned, expected_key_10);
    QFETCH( unsigned, expected_key_11);
    QFETCH( unsigned, expected_key_12);
    QFETCH( unsigned, expected_key_13);
    QFETCH( unsigned, expected_key_14);
    QFETCH( unsigned, expected_key_15);

binarytree<unsigned> BT;
QCOMPARE(BT.insert(key1,value1),true);
QCOMPARE(BT.insert(key2,value2),true);
QCOMPARE(BT.insert(key3,value3),true);
QCOMPARE(BT.insert(key4,value4),true);
QCOMPARE(BT.insert(key5,value5),true);
QCOMPARE(BT.insert(key6,value6),true);
QCOMPARE(BT.insert(key7,value7),true);
QCOMPARE(BT.insert(key8,value8),true);
QCOMPARE(BT.insert(key9,value9),true);
QCOMPARE(BT.insert(key10,value10),true);
QCOMPARE(BT.insert(key11,value11),true);
QCOMPARE(BT.insert(key12,value12),true);
QCOMPARE(BT.insert(key13,value13),true);
QCOMPARE(BT.insert(key14,value14),true);
QCOMPARE(BT.insert(key15,value15),true);

QCOMPARE(BT.pop().first,expected_key_1);
QCOMPARE(BT.pop().first,expected_key_2);
QCOMPARE(BT.pop().first,expected_key_3);
QCOMPARE(BT.pop().first,expected_key_4);
QCOMPARE(BT.pop().first,expected_key_5);
QCOMPARE(BT.pop().first,expected_key_6);
QCOMPARE(BT.pop().first,expected_key_7);
QCOMPARE(BT.pop().first,expected_key_8);
QCOMPARE(BT.pop().first,expected_key_9);
QCOMPARE(BT.pop().first,expected_key_10);
QCOMPARE(BT.pop().first,expected_key_11);
QCOMPARE(BT.pop().first,expected_key_12);
QCOMPARE(BT.pop().first,expected_key_13);
QCOMPARE(BT.pop().first,expected_key_14);
QCOMPARE(BT.pop().first,expected_key_15);

qDebug()<<"... binary_tree_test_ends..."<<endl;
}

void binary_tree_test::insert_unique_pop_test_data()
{
    qDebug()<<"... insert_unique_pop_test_data..."<<endl;
    QTest::addColumn<unsigned>("key1");
    QTest::addColumn<unsigned>("value1");
    QTest::addColumn<unsigned>("key2");
    QTest::addColumn<unsigned>("value2");
    QTest::addColumn<unsigned>("key3");
    QTest::addColumn<unsigned>("value3");
    QTest::addColumn<unsigned>("key4");
    QTest::addColumn<unsigned>("value4");
    QTest::addColumn<unsigned>("key5");
    QTest::addColumn<unsigned>("value5");

    QTest::addColumn<unsigned>("key6");
    QTest::addColumn<unsigned>("value6");
    QTest::addColumn<unsigned>("key7");
    QTest::addColumn<unsigned>("value7");
    QTest::addColumn<unsigned>("key8");
    QTest::addColumn<unsigned>("value8");
    QTest::addColumn<unsigned>("key9");
    QTest::addColumn<unsigned>("value9");
    QTest::addColumn<unsigned>("key10");
    QTest::addColumn<unsigned>("value10");

    QTest::addColumn<unsigned>("key11");
    QTest::addColumn<unsigned>("value11");
    QTest::addColumn<unsigned>("key12");
    QTest::addColumn<unsigned>("value12");
    QTest::addColumn<unsigned>("key13");
    QTest::addColumn<unsigned>("value13");
    QTest::addColumn<unsigned>("key14");
    QTest::addColumn<unsigned>("value14");
    QTest::addColumn<unsigned>("key15");
    QTest::addColumn<unsigned>("value15");
    QTest::addColumn<unsigned>("HEIGHT_INSERT");
    QTest::addColumn<unsigned>("HEIGHT_INSERT_UNIQUE");
    QTest::newRow("data_1") << 1U << 2300U<< 2U << 2400U<< 3U << 2500U<< 4U << 2600U<< 5U << 2700U
                               << 10U << 2300U<< 9U << 2400U<< 8U << 2500U<< 7U << 2600U<< 6U << 2700U
                                  << 20U << 2300U<< 16U << 2400U<< 19U << 2500U<< 2U << 2600U<< 18U << 2700U
                               << 9U << 9U;
    QTest::newRow("data_2") << 11U << 2300U<< 2U << 2400U<< 30U << 2500U<< 4U << 2600U<< 50U << 2700U
                            << 10U << 2300U<< 9U << 2400U<< 18U << 2500U<< 7U << 2600U<< 600U << 2700U
                               << 200U << 2300U<< 16U << 2400U<< 1U << 2500U<< 2U << 2600U<< 44U << 2700U
                            << 5U << 5U;

    QTest::newRow("data_3") << 1000U << 2300U<< 500U << 2400U<< 1500U << 2500U<< 2U << 2600U<< 150U << 2700U
                            << 1710U << 2300U<< 900U << 2400U<< 389U << 2500U<< 780U << 2600U<< 1600U << 2700U
                               << 2000U << 2300U<< 16U << 2400U<< 519U << 2500U<< 2U << 2600U<< 218U << 2700U
                            << 5U << 5U;
}

void binary_tree_test::insert_unique_pop_test()
{
    qDebug()<<"... insert_unique_pop_test..."<<endl;

    QFETCH( unsigned, key1 ); QFETCH( unsigned, value1);
    QFETCH( unsigned, key2 ); QFETCH( unsigned, value2);
    QFETCH( unsigned, key3 ); QFETCH( unsigned, value3);
    QFETCH( unsigned, key4 ); QFETCH( unsigned, value4);
    QFETCH( unsigned, key5 ); QFETCH( unsigned, value5);
    QFETCH( unsigned, key6 ); QFETCH( unsigned, value6);
    QFETCH( unsigned, key7 ); QFETCH( unsigned, value7);
    QFETCH( unsigned, key8 ); QFETCH( unsigned, value8);
    QFETCH( unsigned, key9 ); QFETCH( unsigned, value9);
    QFETCH( unsigned, key10 ); QFETCH( unsigned, value10);
    QFETCH( unsigned, key11 ); QFETCH( unsigned, value11);
    QFETCH( unsigned, key12 ); QFETCH( unsigned, value12);
    QFETCH( unsigned, key13 ); QFETCH( unsigned, value13);
    QFETCH( unsigned, key14 ); QFETCH( unsigned, value14);
    QFETCH( unsigned, key15 ); QFETCH( unsigned, value15);
    QFETCH( unsigned, HEIGHT_INSERT);
    QFETCH( unsigned, HEIGHT_INSERT_UNIQUE);

binarytree<unsigned> BT_ordinar;
binarytree<unsigned> BT_unique;
QCOMPARE(BT_ordinar.insert(key1,value1),true);
QCOMPARE(BT_ordinar.insert(key2,value2),true);
QCOMPARE(BT_ordinar.insert(key3,value3),true);
QCOMPARE(BT_ordinar.insert(key4,value4),true);
QCOMPARE(BT_ordinar.insert(key5,value5),true);
QCOMPARE(BT_ordinar.insert(key6,value6),true);
QCOMPARE(BT_ordinar.insert(key7,value7),true);
QCOMPARE(BT_ordinar.insert(key8,value8),true);
QCOMPARE(BT_ordinar.insert(key9,value9),true);
QCOMPARE(BT_ordinar.insert(key10,value10),true);
QCOMPARE(BT_ordinar.insert(key11,value11),true);
QCOMPARE(BT_ordinar.insert(key12,value12),true);
QCOMPARE(BT_ordinar.insert(key13,value13),true);
QCOMPARE(BT_ordinar.insert(key14,value14),true);
QCOMPARE(BT_ordinar.insert(key15,value15),true);

QCOMPARE(BT_unique.insert_unique(key1,value1),true);
QCOMPARE(BT_unique.insert_unique(key2,value2),true);
QCOMPARE(BT_unique.insert_unique(key3,value3),true);
QCOMPARE(BT_unique.insert_unique(key4,value4),true);
QCOMPARE(BT_unique.insert_unique(key5,value5),true);
QCOMPARE(BT_unique.insert_unique(key6,value6),true);
QCOMPARE(BT_unique.insert_unique(key7,value7),true);
QCOMPARE(BT_unique.insert_unique(key8,value8),true);
QCOMPARE(BT_unique.insert_unique(key9,value9),true);
QCOMPARE(BT_unique.insert_unique(key10,value10),true);
QCOMPARE(BT_unique.insert_unique(key11,value11),true);
QCOMPARE(BT_unique.insert_unique(key12,value12),true);
QCOMPARE(BT_unique.insert_unique(key13,value13),true);
QCOMPARE(BT_unique.insert_unique(key14,value14),false);
QCOMPARE(BT_unique.insert_unique(key15,value15),true);

QCOMPARE(BT_ordinar.height(),HEIGHT_INSERT);
QCOMPARE(BT_ordinar.height(),HEIGHT_INSERT_UNIQUE);

qDebug()<<"... insert_unique_pop_test ends..."<<endl;
}

void binary_tree_test::merge_with_test_data()
{
    qDebug()<<"... merge_with_test_data..."<<endl;
    QTest::addColumn<unsigned>("key1_tree1");
    QTest::addColumn<unsigned>("value1_tree1");
    QTest::addColumn<unsigned>("key2_tree1");
    QTest::addColumn<unsigned>("value2_tree1");
    QTest::addColumn<unsigned>("key3_tree1");
    QTest::addColumn<unsigned>("value3_tree1");
    QTest::addColumn<unsigned>("key4_tree1");
    QTest::addColumn<unsigned>("value4_tree1");
    QTest::addColumn<unsigned>("key5_tree1");
    QTest::addColumn<unsigned>("value5_tree1");

    QTest::addColumn<unsigned>("key1_tree2");
    QTest::addColumn<unsigned>("value1_tree2");
    QTest::addColumn<unsigned>("key2_tree2");
    QTest::addColumn<unsigned>("value2_tree2");
    QTest::addColumn<unsigned>("key3_tree2");
    QTest::addColumn<unsigned>("value3_tree2");
    QTest::addColumn<unsigned>("key4_tree2");
    QTest::addColumn<unsigned>("value4_tree2");
    QTest::addColumn<unsigned>("key5_tree2");
    QTest::addColumn<unsigned>("value5_tree2");

    QTest::addColumn<unsigned>("TEST_HEIGHT1");
    QTest::addColumn<unsigned>("TEST_SIZE1");

    QTest::addColumn<unsigned>("key1_tree3");
    QTest::addColumn<unsigned>("value1_tree3");
    QTest::addColumn<unsigned>("key2_tree3");
    QTest::addColumn<unsigned>("value2_tree3");
    QTest::addColumn<unsigned>("key3_tree3");
    QTest::addColumn<unsigned>("value3_tree3");
    QTest::addColumn<unsigned>("key4_tree3");
    QTest::addColumn<unsigned>("value4_tree3");
    QTest::addColumn<unsigned>("key5_tree3");
    QTest::addColumn<unsigned>("value5_tree3");
    QTest::addColumn<unsigned>("key6_tree3");
    QTest::addColumn<unsigned>("value6_tree3");
    QTest::addColumn<unsigned>("key7_tree3");
    QTest::addColumn<unsigned>("value7_tree3");
    QTest::addColumn<unsigned>("key8_tree3");
    QTest::addColumn<unsigned>("value8_tree3");
    QTest::addColumn<unsigned>("key9_tree3");
    QTest::addColumn<unsigned>("value9_tree3");
    QTest::addColumn<unsigned>("key10_tree3");
    QTest::addColumn<unsigned>("value10_tree3");

    QTest::addColumn<unsigned>("TEST_HEIGHT2");
    QTest::addColumn<unsigned>("TEST_SIZE2");

    QTest::newRow("data_1") << 1U << 2300U<< 2U << 2400U<< 3U << 2500U<< 4U << 2600U<< 5U << 2700U
                               << 5U << 2300U<< 9U << 2400U<< 8U << 2500U<< 7U << 2600U<< 6U << 2700U
                               << 8U    //высота
                               << 10U    //размер
                               << 10U << 2300U<< 9U << 2400U<< 18U << 2500U<< 7U << 2600U<< 600U << 2700U
                               << 200U << 2300U<< 16U << 2400U<< 1U << 2500U<< 2U << 2600U<< 44U << 2700U
                               << 12U    //высота
                               << 16U;    //размер
}

void binary_tree_test::merge_with_test()
{
    qDebug()<<"... merge_with_test..."<<endl;
    QFETCH( unsigned, key1_tree1 ); QFETCH( unsigned, value1_tree1);
    QFETCH( unsigned, key2_tree1 ); QFETCH( unsigned, value2_tree1);
    QFETCH( unsigned, key3_tree1 ); QFETCH( unsigned, value3_tree1);
    QFETCH( unsigned, key4_tree1 ); QFETCH( unsigned, value4_tree1);
    QFETCH( unsigned, key5_tree1 ); QFETCH( unsigned, value5_tree1);

    QFETCH( unsigned, key1_tree2 ); QFETCH( unsigned, value1_tree2);
    QFETCH( unsigned, key2_tree2 ); QFETCH( unsigned, value2_tree2);
    QFETCH( unsigned, key3_tree2 ); QFETCH( unsigned, value3_tree2);
    QFETCH( unsigned, key4_tree2 ); QFETCH( unsigned, value4_tree2);
    QFETCH( unsigned, key5_tree2 ); QFETCH( unsigned, value5_tree2);

    QFETCH( unsigned, key1_tree3 ); QFETCH( unsigned, value1_tree3);
    QFETCH( unsigned, key2_tree3 ); QFETCH( unsigned, value2_tree3);
    QFETCH( unsigned, key3_tree3 ); QFETCH( unsigned, value3_tree3);
    QFETCH( unsigned, key4_tree3 ); QFETCH( unsigned, value4_tree3);
    QFETCH( unsigned, key5_tree3 ); QFETCH( unsigned, value5_tree3);

    QFETCH( unsigned, key6_tree3 ); QFETCH( unsigned, value6_tree3);
    QFETCH( unsigned, key7_tree3 ); QFETCH( unsigned, value7_tree3);
    QFETCH( unsigned, key8_tree3 ); QFETCH( unsigned, value8_tree3);
    QFETCH( unsigned, key9_tree3 ); QFETCH( unsigned, value9_tree3);
    QFETCH( unsigned, key10_tree3 ); QFETCH( unsigned, value10_tree3);

    QFETCH( unsigned, TEST_HEIGHT1);
    QFETCH( unsigned, TEST_HEIGHT2);
    QFETCH( unsigned, TEST_SIZE1);
    QFETCH( unsigned, TEST_SIZE2);


    binarytree<unsigned> BT_first;
    binarytree<unsigned> BT_second;
    binarytree<unsigned> BT_third;

    QCOMPARE(BT_first.insert(key1_tree1,value1_tree1),true);
    QCOMPARE(BT_first.insert(key2_tree1,value2_tree1),true);
    QCOMPARE(BT_first.insert(key3_tree1,value3_tree1),true);
    QCOMPARE(BT_first.insert(key4_tree1,value4_tree1),true);
    QCOMPARE(BT_first.insert(key5_tree1,value5_tree1),true);

    QCOMPARE(BT_second.insert(key1_tree2,value1_tree2),true);
    QCOMPARE(BT_second.insert(key2_tree2,value2_tree2),true);
    QCOMPARE(BT_second.insert(key3_tree2,value3_tree2),true);
    QCOMPARE(BT_second.insert(key4_tree2,value4_tree2),true);
    QCOMPARE(BT_second.insert(key5_tree2,value5_tree2),true);

    QCOMPARE(BT_third.insert(key1_tree3,value1_tree3),true);
    QCOMPARE(BT_third.insert(key2_tree3,value2_tree3),true);
    QCOMPARE(BT_third.insert(key3_tree3,value3_tree3),true);
    QCOMPARE(BT_third.insert(key4_tree3,value4_tree3),true);
    QCOMPARE(BT_third.insert(key5_tree3,value5_tree3),true);

    QCOMPARE(BT_third.insert(key6_tree3,value6_tree3),true);
    QCOMPARE(BT_third.insert(key7_tree3,value7_tree3),true);
    QCOMPARE(BT_third.insert(key8_tree3,value8_tree3),true);
    QCOMPARE(BT_third.insert(key9_tree3,value9_tree3),true);
    QCOMPARE(BT_third.insert(key10_tree3,value10_tree3),true);

    QCOMPARE(BT_first.add(BT_second).height(),TEST_HEIGHT1);
    QCOMPARE(BT_first.size(),TEST_SIZE1);
    QCOMPARE((BT_first.add_unique(BT_third)).height(),TEST_HEIGHT2);
    QCOMPARE(BT_first.size(),TEST_SIZE2);
    QCOMPARE(BT_first.erase(key4_tree3),true);
    QCOMPARE(BT_first.size(),TEST_SIZE2-1);

    QCOMPARE(BT_first.erase(key1_tree1),true);
    QCOMPARE(BT_first.size(),TEST_SIZE2-2);

    QCOMPARE(BT_first.erase(key2_tree1),true);
    QCOMPARE(BT_first.size(),TEST_SIZE2-3);

    QCOMPARE(BT_first.erase(key3_tree1),true);
    QCOMPARE(BT_first.size(),TEST_SIZE2-4);

    QCOMPARE(BT_first.erase(key4_tree1),true);
    QCOMPARE(BT_first.size(),TEST_SIZE2-5);

    QCOMPARE(BT_first.erase(key5_tree1),true);
    QCOMPARE(BT_first.size(),TEST_SIZE2-6);

    QCOMPARE(BT_first.erase(key2_tree2),true);
    QCOMPARE(BT_first.size(),TEST_SIZE2-7);

    qDebug()<<"... merge_with_test ends..."<<endl;
}

QTEST_APPLESS_MAIN(binary_tree_test)

#include "tst_binary_tree_test.moc"
