#include <QtTest>
#include <QCoreApplication>
#include <parallel_set.hpp>
#include <victim.h>
#include <binary_tree.h>
#include<parallel_queue.hpp>
#include<lock_free_queue.hpp>
#include<work_generator.h>
#include<vector>

// add necessary includes here

class MyTestCase : public QObject
{
    Q_OBJECT

public:
    MyTestCase();
    ~MyTestCase();

private slots:
    void initTestCase();
    void cleanupTestCase();

    void victim_test_data();
    void victim_test();

    void binary_tree_test_data();
    void binary_tree_test();

    void parallel_stack_test_data();
    void parallel_stack_test();

    void lock_free_queue_test_data();
    void lock_free_queue_test();

    void parallel_queue_test_data();
    void parallel_queue_test();

    void set_parallel_test_data();
    void set_parallel_test();

    void work_generator_test_data();
    void work_generator_test();

    void threadpool_set_default_test_data();
    void threadpool_set_default_test();

    void threadpool_set_parallel_stack_test_data();
    void threadpool_set_parallel_stack_test();

    void threadpool_set_lock_free_queue_test_data();
    void threadpool_set_lock_free_queue_test();

    void threadpool_set_parallel_queue_test_data();
    void threadpool_set_parallel_queue_test();

    /**/

};

MyTestCase::MyTestCase()
{

}

MyTestCase::~MyTestCase()
{

}

void MyTestCase::initTestCase()
{
    qDebug()<<"... Init ..."<<endl;
}

void MyTestCase::victim_test_data(){
    qDebug()<<"... victim_test_data ..."<<endl;
    QTest::addColumn<unsigned>("input");
    QTest::addColumn<unsigned>("expected");
    QTest::newRow("data_1") << 8U << 8U;
}

void MyTestCase::cleanupTestCase()
{
qDebug()<<"... Cleanup ..."<<endl;
}

void MyTestCase::victim_test()
{
    qDebug()<<"... victim_class_test..."<<endl;
    QFETCH( unsigned, input );
    QFETCH( unsigned, expected );
    victim V(input);
    QCOMPARE(V.get_value(),expected);
    QBENCHMARK{
        V.get_value();
    }

}
void MyTestCase::binary_tree_test_data(){

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

        /**/
}
void MyTestCase::binary_tree_test()
{
qDebug()<<"... binary_tree_class_test..."<<endl;
binary_tree<victim> B;
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

std::unique_ptr<victim> V1 = std::make_unique<victim>(input1);
std::unique_ptr<victim> V2 = std::make_unique<victim>(input2);
std::unique_ptr<victim> V3 = std::make_unique<victim>(input3);
std::unique_ptr<victim> V4 = std::make_unique<victim>(input4);
std::unique_ptr<victim> V5 = std::make_unique<victim>(input5);
std::unique_ptr<victim> V6 = std::make_unique<victim>(input6);
std::unique_ptr<victim> V7 = std::make_unique<victim>(input7);

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

void MyTestCase::parallel_stack_test_data(){

    qDebug()<<"... parallel_stack_test_data ..."<<endl;

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
}
void MyTestCase::parallel_stack_test(){
    qDebug()<<"... parallel_stack_class_test..."<<endl;

    parallel_stack<victim> PS;

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

    victim V1(input1);
    victim V2(input2);
    victim V3(input3);
    victim V4(input4);
    victim V5(input5);
    victim V6(input6);
    victim V7(input7);
    PS.push(std::move(V1));
    PS.push(std::move(V2));
    PS.push(std::move(V3));
    PS.push(std::move(V4));
    PS.push(std::move(V5));
    PS.push(std::move(V6));
    PS.push(std::move(V7));

    QCOMPARE(PS.pop().get()->get_value(),expected1);
    QCOMPARE(PS.pop().get()->get_value(),expected2);
    QCOMPARE(PS.pop().get()->get_value(),expected3);
    QCOMPARE(PS.pop().get()->get_value(),expected4);
    QCOMPARE(PS.pop().get()->get_value(),expected5);
    QCOMPARE(PS.pop().get()->get_value(),expected6);
    QCOMPARE(PS.pop().get()->get_value(),expected7);
    /**/
    QCOMPARE(PS.is_empty(),true);
    qDebug()<<"... parallel_stack_class_test_ends..."<<endl;

}
void MyTestCase::lock_free_queue_test_data(){
    qDebug()<<"... lock_free_queue_test_data ..."<<endl;

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
    QTest::newRow("data_1") << 1U << 2U << 3U << 4U << 5U << 6U << 7U << 1U << 2U << 3U << 4U << 5U << 6U << 7U;
}

void MyTestCase::lock_free_queue_test(){
    qDebug()<<"... lock_free_queue_class_test..."<<endl;

    lock_free_queue<victim> PS;

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


    victim V1(input1);
    victim V2(input2);
    victim V3(input3);
    victim V4(input4);
    victim V5(input5);
    victim V6(input6);
    victim V7(input7);

    PS.push(std::move(V1));
    PS.push(std::move(V2));
    PS.push(std::move(V3));
    PS.push(std::move(V4));
    PS.push(std::move(V5));
    PS.push(std::move(V6));
    PS.push(std::move(V7));

    QCOMPARE(PS.pop().get()->get_value(),expected1);
    QCOMPARE(PS.pop().get()->get_value(),expected2);
    QCOMPARE(PS.pop().get()->get_value(),expected3);
    QCOMPARE(PS.pop().get()->get_value(),expected4);
    QCOMPARE(PS.pop().get()->get_value(),expected5);
    QCOMPARE(PS.pop().get()->get_value(),expected6);
    QCOMPARE(PS.pop().get()->get_value(),expected7);



    QCOMPARE(PS.is_empty(),true);
    qDebug()<<"... lock_free_queue_class_test ends..."<<endl;
        /**/
}

void MyTestCase::parallel_queue_test_data(){
    qDebug()<<"... parallel_queue_test_data ..."<<endl;

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
    QTest::newRow("data_1") << 1U << 2U << 3U << 4U << 5U << 6U << 7U << 1U << 2U << 3U << 4U << 5U << 6U << 7U;
}
void MyTestCase::parallel_queue_test(){
    qDebug()<<"... parallel_queue_class_test..."<<endl;
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

    parallel_queue<victim> PS;
    victim V1(input1);
    victim V2(input2);
    victim V3(input3);
    victim V4(input4);
    victim V5(input5);
    victim V6(input6);
    victim V7(input7);

    PS.push(std::move(V1));
    PS.push(std::move(V2));
    PS.push(std::move(V3));
    PS.push(std::move(V4));
    PS.push(std::move(V5));
    PS.push(std::move(V6));
    PS.push(std::move(V7));

    QCOMPARE(PS.pop().get()->get_value(),expected1);
    QCOMPARE(PS.pop().get()->get_value(),expected2);
    QCOMPARE(PS.pop().get()->get_value(),expected3);
    QCOMPARE(PS.pop().get()->get_value(),expected4);
    QCOMPARE(PS.pop().get()->get_value(),expected5);
    QCOMPARE(PS.pop().get()->get_value(),expected6);
    QCOMPARE(PS.pop().get()->get_value(),expected7);

    QCOMPARE(PS.is_empty(),true);

    /**/
    qDebug()<<"... parallel_queue_class_test_ends..."<<endl;
}

void MyTestCase::set_parallel_test_data(){
    qDebug()<<"... parallel_set_test_data ..."<<endl;

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
    QTest::newRow("data_1") << 1U << 2U << 3U << 4U << 5U << 6U << 7U << 1U << 2U << 3U << 4U << 5U << 6U << 7U;
}



void MyTestCase::set_parallel_test(){

    parallel_set<victim, lock_free_queue> PS;

    qDebug()<<"... parallel_set_class_test..."<<endl;
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

    victim V1(input1);
    victim V2(input2);
    victim V3(input3);
    victim V4(input4);
    victim V5(input5);
    victim V6(input6);
    victim V7(input7);
    PS.push(std::move(V1));
    PS.push(std::move(V2));
    PS.push(std::move(V3));
    PS.push(std::move(V4));
    PS.push(std::move(V5));
    PS.push(std::move(V6));
    PS.push(std::move(V7));

    victim res;
    QCOMPARE(PS.try_pop(res),true);
    QCOMPARE(res.get_value(),expected1);
    QCOMPARE(PS.try_pop(res),true);
    QCOMPARE(res.get_value(),expected2);
    QCOMPARE(PS.try_pop(res),true);
    QCOMPARE(res.get_value(),expected3);
    QCOMPARE(PS.try_pop(res),true);
    QCOMPARE(res.get_value(),expected4);
    QCOMPARE(PS.try_pop(res),true);
    QCOMPARE(res.get_value(),expected5);
    QCOMPARE(PS.try_pop(res),true);
    QCOMPARE(res.get_value(),expected6);
    QCOMPARE(PS.try_pop(res),true);
    QCOMPARE(res.get_value(),expected7);

    QCOMPARE(PS.is_empty(),false);
    PS.clear_tree();
    QCOMPARE(PS.is_empty(),true);
    qDebug()<<"... parallel_set_class_test_ends..."<<endl;
/*    */
}


void MyTestCase::work_generator_test_data(){
qDebug()<<"... work_generator_test_data ..."<<endl;

}
void MyTestCase::work_generator_test(){
    qDebug()<<"... work_generator_test_starts..."<<endl;

    work_generator <decltype(&victim::get_value_c), (&victim::get_value_c), victim> WG;
    QCOMPARE(WG.create_test_works(10),true);
    QCOMPARE(WG.perform_test_works(),true);
    QCOMPARE(victim::sum_accumulated,WG.sum_accumulated());

    qDebug()<<"... work_generator_test_ends..."<<endl;
}
/**/

void MyTestCase::threadpool_set_default_test_data(){
    qDebug()<<"... threadpool_set_default_test_data ..."<<endl;
}
void MyTestCase::threadpool_set_default_test(){
    qDebug()<<"... threadpool_set_default_test ..."<<endl;
    work_generator <decltype(&victim::get_value_c), (&victim::get_value_c), victim> WG;
    QCOMPARE(WG.create_test_works(10),true);
    QCOMPARE(WG.submit_everything(),true);
    QCOMPARE(victim::sum_accumulated,WG.sum_accumulated());

    //victim::reset_sum();
    qDebug()<<"... threadpool_set_default_test_end ..."<<endl;
}

void MyTestCase::threadpool_set_parallel_stack_test_data(){
    qDebug()<<"... threadpool_set_parallel_stack_test_data ..."<<endl;
}
void MyTestCase::threadpool_set_parallel_stack_test(){
    qDebug()<<"... threadpool_set_parallel_stack_test ..."<<endl;
    work_generator <decltype(&victim::get_value_c), (&victim::get_value_c), victim, parallel_stack> WG;
    QCOMPARE(WG.create_test_works(10),true);
    QCOMPARE(WG.submit_everything(),true);
    QCOMPARE(victim::sum_accumulated,WG.sum_accumulated());

    victim::reset_sum();
    qDebug()<<"... threadpool_set_parallel_stack_test_end ..."<<endl;
}


void MyTestCase::threadpool_set_lock_free_queue_test_data(){
    qDebug()<<"... threadpool_set_lock_free_queue_test_data ..."<<endl;
}
void MyTestCase::threadpool_set_lock_free_queue_test(){
    qDebug()<<"... threadpool_set_lock_free_queue_test ..."<<endl;
    work_generator <decltype(&victim::get_value_c), (&victim::get_value_c), victim, lock_free_queue> WG;
    QCOMPARE(WG.create_test_works(10),true);
    QCOMPARE(WG.submit_everything(),true);
    QCOMPARE(victim::sum_accumulated,WG.sum_accumulated());

    //victim::reset_sum();
    qDebug()<<"... threadpool_set_lock_free_queue_test_end ..."<<endl;
}

void MyTestCase::threadpool_set_parallel_queue_test_data(){
    qDebug()<<"... threadpool_set_parallel_queue_test_data ..."<<endl;
}
void MyTestCase::threadpool_set_parallel_queue_test(){
    qDebug()<<"... threadpool_set_parallel_queue_test ..."<<endl;
    work_generator <decltype(&victim::get_value_c), (&victim::get_value_c), victim, lock_free_queue> WG;
    QCOMPARE(WG.create_test_works(10),true);
    QCOMPARE(WG.submit_everything(),true);
    QCOMPARE(victim::sum_accumulated,WG.sum_accumulated());

    qDebug()<<"... threadpool_set_parallel_queue_test_end ..."<<endl;
}


QTEST_MAIN(MyTestCase)

#include "tst_mytestcase.moc"














