#include <QtTest>
#include"victim.h"
#include"example_class.h"
// add necessary includes here

class victim_test : public QObject
{
    Q_OBJECT

public:
    victim_test();
    ~victim_test();

private slots:
    void victim_test1_data();
    void victim_test1();

    void example1_test1_data();
    void example1_test1();

};

victim_test::victim_test()
{

}

victim_test::~victim_test()
{

}

void victim_test::victim_test1_data()
{
    qDebug()<<"... victim_test_data ..."<<endl;
    QTest::addColumn<unsigned>("input");
    QTest::addColumn<unsigned>("expected");
    QTest::newRow("data_1") << 8U << 8U;
}

void victim_test::victim_test1()
{
    qDebug()<<"... victim_class_test..."<<endl;
    QFETCH( unsigned, input );
    QFETCH( unsigned, expected );
    victim V(input);
    QCOMPARE(V.get_value(),expected);
}

void victim_test::example1_test1_data()
{
    qDebug()<<"... victim_test_data ..."<<endl;
    qDebug()<<"... victim_test_data ..."<<endl;
    QTest::addColumn<unsigned>("input");
    QTest::addColumn<unsigned>("expected");
    QTest::newRow("data_1") << 8U << 8U;
}

void victim_test::example1_test1()
{
    qDebug()<<"... example_class_test..."<<endl;
    QFETCH( unsigned, input );
    QFETCH( unsigned, expected );
    example_class V(input);
    QCOMPARE(V.index(),expected);
}

/**/





QTEST_APPLESS_MAIN(victim_test)

#include "tst_victim_test.moc"
