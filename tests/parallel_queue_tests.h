#ifndef PARALLEL_QUEUE_TESTS_H
#define PARALLEL_QUEUE_TESTS_H
#include "autotest.h"

class parallel_queue_tests : public QObject
{
    Q_OBJECT
public:
    parallel_queue_tests();
    ~parallel_queue_tests();
private slots:
    void initTestCase();
    void cleanupTestCase();
    void parallel_queue_test_data();
    void parallel_queue_test();
};


DECLARE_TEST(parallel_queue_tests)
#endif // PARALLEL_QUEUE_TESTS_H
