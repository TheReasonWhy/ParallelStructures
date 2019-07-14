#include "victim_tests.h"

victim_tests::victim_tests()
{

}

victim_tests::~victim_tests()
{

}

void victim_tests::initTestCase()
{

}

void victim_tests::cleanupTestCase()
{

}

void victim_tests::victim_test_data()
{
    qDebug()<<"... victim_test_data ..."<<endl;
    QTest::addColumn<unsigned>("input");
    QTest::addColumn<unsigned>("expected");
    QTest::newRow("data_1") << 8U << 8U;
}

void victim_tests::victim_test()
{
    qDebug()<<"... victim_class_test..."<<endl;
    QFETCH( unsigned, input );
    QFETCH( unsigned, expected );
    victim V(input);
    QCOMPARE(V.get_value(),expected);
}/**/

