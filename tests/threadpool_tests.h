#ifndef THREADPOOL_TESTS_H
#define THREADPOOL_TESTS_H

#include "autotest.h"

class threadpool_tests : public QObject
{
    Q_OBJECT

public:
    threadpool_tests();
    ~threadpool_tests();

private slots:
    void initTestCase();
    void cleanupTestCase();

    void threadpool_set_default_test_data();
    void threadpool_set_default_test();

    void threadpool_set_parallel_stack_test_data();
    void threadpool_set_parallel_stack_test();

    void threadpool_set_lock_free_queue_test_data();
    void threadpool_set_lock_free_queue_test();

    void threadpool_set_parallel_queue_test_data();
    void threadpool_set_parallel_queue_test();
};


DECLARE_TEST(threadpool_tests)

#endif // THREADPOOL_TESTS_H
