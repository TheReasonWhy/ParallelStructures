#include <QtTest>
#include<interval_system.hpp>

// add necessary includes here

class interval_system_tes : public QObject
{
    Q_OBJECT

public:
    interval_system_tes();
    ~interval_system_tes();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

interval_system_tes::interval_system_tes()
{

}

interval_system_tes::~interval_system_tes()
{

}

void interval_system_tes::initTestCase()
{

}

void interval_system_tes::cleanupTestCase()
{

}

void interval_system_tes::test_case1()
{
    Interval_system<unsigned,4,30,370> IS;
    IS.init("intervals.txt");
    unsigned f1(303);
    unsigned f2(79);
    unsigned f3(25);
    unsigned f5(0);
    unsigned f6(0);
    unsigned f7(0);
    unsigned f8(10);
    unsigned f9(3);
    unsigned f10(2);

    QCOMPARE(IS.get_low_id(2,4,5),f1);
    QCOMPARE(IS.get_low_id(3,4),f2);
    QCOMPARE(IS.get_middle_id(3,4),f3);

    QCOMPARE(IS.get_middle_id_by_low(3),f5);
    QCOMPARE(IS.get_up_id_by_middle(3),f6);
    QCOMPARE(IS.get_up_id_by_low(3),f7);

    QCOMPARE(IS.get_middle_id_by_low(223),f8);
    QCOMPARE(IS.get_up_id_by_middle(23),f9);
    QCOMPARE(IS.get_up_id_by_low(333),f10);

    /*
    static T get_middle_id_by_low(size_t const low_id);
    static size_t get_up_id_by_middle(size_t const middle_id);
    static size_t get_up_id_by_low(size_t const low_id);
    */
}

QTEST_APPLESS_MAIN(interval_system_tes)

#include "tst_interval_system_tes.moc"
