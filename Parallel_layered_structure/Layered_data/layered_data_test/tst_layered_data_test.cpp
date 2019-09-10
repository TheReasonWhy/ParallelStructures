#include <QtTest>
#include<layered_data.h>

// add necessary includes here

class layered_data_test : public QObject
{
    Q_OBJECT

public:
    layered_data_test();
    ~layered_data_test();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

layered_data_test::layered_data_test()
{

}

layered_data_test::~layered_data_test()
{

}

void layered_data_test::initTestCase()
{

}

void layered_data_test::cleanupTestCase()
{

}

void layered_data_test::test_case1()
{
    Layered_data<unsigned,4,30,370> LD;
    LD.init("layered_data.txt");
    unsigned t0(0);
    unsigned t1(1);
    unsigned u0(333);
    unsigned u1(322);
    unsigned m0(25);
    unsigned m1(16);
    unsigned e0(565);
    unsigned e1(566);
    QCOMPARE(LD.get_up_data(0)->get_type(),t0);
    QCOMPARE(LD.get_middle_data(0)->get_type(),t1);
    QCOMPARE(LD.get_low_data(0)->get_type(),t0);

    QCOMPARE(LD.get_up_data(0)->call(),u0);
    QCOMPARE(LD.get_middle_data(0)->call(),m0);
    QCOMPARE(LD.get_low_data(10)->call(),e0);

    QCOMPARE(LD.get_up_data(1)->get_type(),t1);
    QCOMPARE(LD.get_middle_data(1)->get_type(),t0);
    QCOMPARE(LD.get_low_data(1)->get_type(),t1);

    QCOMPARE(LD.get_up_data(1)->call(),u1);
    QCOMPARE(LD.get_middle_data(6)->call(),m1);
    QCOMPARE(LD.get_low_data(11)->call(),e1);
}

QTEST_APPLESS_MAIN(layered_data_test)

#include "tst_layered_data_test.moc"




















