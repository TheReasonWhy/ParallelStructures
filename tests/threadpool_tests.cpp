#include "threadpool_tests.h"



threadpool_tests::threadpool_tests()
{

}

threadpool_tests::~threadpool_tests()
{

}

void threadpool_tests::initTestCase()
{
    qDebug()<<"... Init ..."<<endl;
}

void threadpool_tests::cleanupTestCase()
{

}

void threadpool_tests::threadpool_set_default_test_data(){
    qDebug()<<"... threadpool_set_default_test_data ..."<<endl;
}

void threadpool_tests::threadpool_set_default_test(){
    qDebug()<<"... threadpool_set_default_test ..."<<endl;
    work_generator <decltype(&victim::get_value_c), (&victim::get_value_c), victim> WG;

    QCOMPARE(WG.reset_control_sum(),true);

    QCOMPARE(WG.create_test_works(10),true);
    QCOMPARE(WG.submit_everything(),true);

    QCOMPARE(WG.get_control_sum(),WG.get_accumulated_sum());

    //victim::reset_sum();
    qDebug()<<"... threadpool_set_default_test_end ..."<<endl;
}

void threadpool_tests::threadpool_set_parallel_stack_test_data(){
    qDebug()<<"... threadpool_set_parallel_stack_test_data ..."<<endl;
}

void threadpool_tests::threadpool_set_parallel_stack_test(){
    qDebug()<<"... threadpool_set_parallel_stack_test ..."<<endl;
    work_generator <decltype(&victim::get_value_c), (&victim::get_value_c), victim, parallel_stack> WG;

    QCOMPARE(WG.reset_control_sum(),true);

    QCOMPARE(WG.create_test_works(100),true);
    QCOMPARE(WG.submit_everything(),true);
    QCOMPARE(WG.get_control_sum(),WG.get_accumulated_sum());

    qDebug()<<"... threadpool_set_parallel_stack_test_end ..."<<endl;
}

void threadpool_tests::threadpool_set_lock_free_queue_test_data(){
    qDebug()<<"... threadpool_set_lock_free_queue_test_data ..."<<endl;
}

void threadpool_tests::threadpool_set_lock_free_queue_test(){
    qDebug()<<"... threadpool_set_lock_free_queue_test ..."<<endl;
    work_generator <decltype(&victim::get_value_c), (&victim::get_value_c), victim, lock_free_queue> WG;

    QCOMPARE(WG.reset_control_sum(),true);

    QCOMPARE(WG.create_test_works(100),true);
    QCOMPARE(WG.submit_everything(),true);
    QCOMPARE(WG.get_control_sum(),WG.get_accumulated_sum());

    //victim::reset_sum();
    qDebug()<<"... threadpool_set_lock_free_queue_test_end ..."<<endl;
}

void threadpool_tests::threadpool_set_parallel_queue_test_data(){
    qDebug()<<"... threadpool_set_parallel_queue_test_data ..."<<endl;
}

void threadpool_tests::threadpool_set_parallel_queue_test(){
    qDebug()<<"... threadpool_set_parallel_queue_test ..."<<endl;
    work_generator <decltype(&victim::get_value_c), (&victim::get_value_c), victim, lock_free_queue> WG;

    QCOMPARE(WG.reset_control_sum(),true);

    QCOMPARE(WG.create_test_works(100),true);
    QCOMPARE(WG.submit_everything(),true);
    QCOMPARE(WG.get_control_sum(),WG.get_accumulated_sum());

    qDebug()<<"... threadpool_set_parallel_queue_test_end ..."<<endl;
}
