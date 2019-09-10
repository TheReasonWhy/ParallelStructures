#include <QtTest>
#include<threadpool_client.hpp>
#include<threadpool_client.hpp>
#include<victim.h>
#include<work_generator.hpp>
#include<lock_free_queue.hpp>
#include<lock_free_queue_packaged_task.hpp>
#include<parallel_stack.hpp>
#include<parallel_stack_packaged.hpp>
#include<lock_free_queue_unique_lock.hpp>
// add necessary includes here

class threadpool_client_test : public QObject
{
    Q_OBJECT

public:
    threadpool_client_test();
    ~threadpool_client_test();


private slots:
/*
    void TP_set_parallel_stack_test_data();
    void TP_set_parallel_stack_test();

    void lock_test_data();
    void lock_test();
*//*
    void TP_set_lock_free_queue_unique_lock_test_data();
    void TP_set_lock_free_queue_unique_lock_test();

    void TP_set_lock_free_queue_test_data();
    void TP_set_lock_free_queue_test();
*/
    void TP_set_parallel_stack_test_data();
    void TP_set_parallel_stack_test();
/*
    void TP_set_lock_free_queue_test2_data();
    void TP_set_lock_free_queue_test2();
*/
    void TP_set_parallel_stack_test2_data();
    void TP_set_parallel_stack_test2();


};

threadpool_client_test::threadpool_client_test()
{

}

threadpool_client_test::~threadpool_client_test()
{

}
/*
void threadpool_client_test::lock_test_data()
{

}

void threadpool_client_test::lock_test()
{

        qDebug()<<"... lock_test ..."<<endl;
        std::shared_ptr<victim<>> v;
        int ff(7);
        std::atomic<std::shared_ptr<int>> V(ff);
        std::atomic<int> F(ff);
        //qDebug()<<"... is_lock_free ..."<<std::atomic_is_lock_free(&v) <<endl;
        qDebug()<<"... is_lock_free ..."<<std::atomic_is_lock_free(&F) <<endl;
}




void threadpool_client_test::TP_set_lock_free_queue_unique_lock_test_data(){
    qDebug()<<"... threadpool_set_lock_free_queue_test_data ..."<<endl;
}

void threadpool_client_test::TP_set_lock_free_queue_unique_lock_test(){
qDebug()<<"... TP_set_lock_free_queue_test ..."<<endl;

        Threadpool_client <decltype(&victim<>::get_value),
                    (&victim<>::get_value),
                    victim<>,
                    100,
                    parallel_stack,
                    parallel_stack,
                    lock_free_queue_unique_lock> TC;

    QCOMPARE(TC.reset_control_sum(),true);

    QCOMPARE(TC.create_test_works(10),true);
    QCOMPARE(TC.submit_everything(),true);
    QCOMPARE(TC.get_control_sum(),TC.get_accumulated_sum());
    //victim::reset_sum();
    qDebug()<<"... threadpool_set_lock_free_queue_test_end ..."<<endl;
}



void threadpool_client_test::TP_set_lock_free_queue_test_data(){
    qDebug()<<"... threadpool_set_lock_free_queue_test_data ..."<<endl;
}

void threadpool_client_test::TP_set_lock_free_queue_test(){
qDebug()<<"... TP_set_lock_free_queue_test ..."<<endl;

        Threadpool_client <decltype(&victim<>::get_value),
                    (&victim<>::get_value),
                    victim<>,
                    100,
                    parallel_stack,
                    parallel_stack,
                    lock_free_queue> TC;

    QCOMPARE(TC.reset_control_sum(),true);

    QCOMPARE(TC.create_test_works(10),true);
    QCOMPARE(TC.submit_everything(),true);
    QCOMPARE(TC.get_control_sum(),TC.get_accumulated_sum());
    //victim::reset_sum();
    qDebug()<<"... threadpool_set_lock_free_queue_test_end ..."<<endl;
}


*/
void threadpool_client_test::TP_set_parallel_stack_test_data(){
    qDebug()<<"... threadpool_set_parallel_queue_test_data ..."<<endl;
}

void threadpool_client_test::TP_set_parallel_stack_test(){
    qDebug()<<"... threadpool_set_parallel_queue_test ..."<<endl;
            Threadpool_client <decltype(&victim<>::get_value),
                    (&victim<>::get_value),
                    victim<>,
                    100,
                    parallel_stack,
                    parallel_stack_packaged,
                    parallel_stack_packaged> TC;

    QCOMPARE(TC.reset_control_sum(),true);

    QCOMPARE(TC.create_test_works(10),true);
    QCOMPARE(TC.submit_everything(),true);
    QCOMPARE(TC.get_control_sum(),TC.get_accumulated_sum());

    qDebug()<<"... threadpool_set_parallel_queue_test_end ..."<<endl;
}
/*
void threadpool_client_test::TP_set_lock_free_queue_test2_data(){
    qDebug()<<"... threadpool_set_lock_free_queue_test_data ..."<<endl;
}

void threadpool_client_test::TP_set_lock_free_queue_test2(){
    qDebug()<<"... threadpool_set_lock_free_queue_test ..."<<endl;
        Threadpool_client2 <decltype(&victim<>::get_value),
                    (&victim<>::get_value),
                    victim<>,
                    100,
                    parallel_stack,
                    parallel_stack,
                    lock_free_queue_packaged_task> TC;

    QCOMPARE(TC.reset_control_sum(),true);

    QCOMPARE(TC.create_test_works(10),true);
    QCOMPARE(TC.submit_everything(),true);
    QCOMPARE(TC.get_control_sum(),TC.get_accumulated_sum());

    //victim::reset_sum();
    qDebug()<<"... threadpool_set_lock_free_queue_test_end ..."<<endl;
}
*/
void threadpool_client_test::TP_set_parallel_stack_test2_data(){
    qDebug()<<"... threadpool_set_parallel_queue_test_data ..."<<endl;
}

void threadpool_client_test::TP_set_parallel_stack_test2(){
    qDebug()<<"... threadpool_set_parallel_queue_test ..."<<endl;
            Threadpool_client <decltype(&victim<>::get_value),
                    (&victim<>::get_value),
                    victim<>,
                    100,
                    parallel_stack,
                    parallel_stack_packaged,
                    parallel_stack_packaged> TC;

    QCOMPARE(TC.reset_control_sum(),true);

    QCOMPARE(TC.create_test_works(10),true);
    QCOMPARE(TC.submit_everything(),true);
    QCOMPARE(TC.get_control_sum(),TC.get_accumulated_sum());

    qDebug()<<"... threadpool_set_parallel_queue_test_end ..."<<endl;
}

/**/
QTEST_APPLESS_MAIN(threadpool_client_test)

#include "tst_threadpool_client_test.moc"
