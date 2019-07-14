#ifndef LOCK_FREE_QUEUE_TESTS_H
#define LOCK_FREE_QUEUE_TESTS_H
#include "autotest.h"

class lock_free_queue_tests : public QObject
{
    Q_OBJECT
public:
    lock_free_queue_tests();
    ~lock_free_queue_tests();
private slots:
    void initTestCase();
    void cleanupTestCase();

    void lock_free_queue_test_data();
    void lock_free_queue_test();
};


DECLARE_TEST(lock_free_queue_tests)
#endif // LOCK_FREE_QUEUE_TESTS_H
