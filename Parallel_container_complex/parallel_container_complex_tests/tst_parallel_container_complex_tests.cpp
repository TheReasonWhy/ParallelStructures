#include <QtTest>
#include<thread_system.hpp>
// add necessary includes here

class parallel_container_complex_tests : public QObject
{
    Q_OBJECT

public:
    parallel_container_complex_tests();
    ~parallel_container_complex_tests();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

parallel_container_complex_tests::parallel_container_complex_tests()
{

}

parallel_container_complex_tests::~parallel_container_complex_tests()
{

}

void parallel_container_complex_tests::initTestCase()
{

}

void parallel_container_complex_tests::cleanupTestCase()
{
}

void parallel_container_complex_tests::test_case1()
{
    size_t const num_lvl(4);
    size_t const num_routables(30);
    size_t const num_elems(370);
    //unsigned get_control_sum(unsigned lvl, unsigned id)
    //template<size_t LEVELS_NUM, size_t ROUTABLES_NUM, size_t ELEMENTS_NUM>
    thread_system<num_lvl,num_routables,num_elems> TS;    
    unsigned lvl = 0;
    unsigned rtbl = 0;
    unsigned id = 0;
    unsigned sum = TS.get_sum_recursive(lvl,rtbl,id);    

    qDebug()<< "get_sum_recursive "<<sum<<endl;
    //TS.add_element_action(0);
    //TS.process();
    //QCOMPARE(sum,TS.get_control_sum());

}

QTEST_APPLESS_MAIN(parallel_container_complex_tests)

#include "tst_parallel_container_complex_tests.moc"
