#ifndef PARALLEL_STACK_TESTS_H
#define PARALLEL_STACK_TESTS_H
#include "autotest.h"

class parallel_stack_tests : public QObject
{
    Q_OBJECT
public:
    parallel_stack_tests();
    ~parallel_stack_tests();
private slots:
    void initTestCase();
    void cleanupTestCase();
    void parallel_stack_test_data();
    void parallel_stack_test();
};


DECLARE_TEST(parallel_stack_tests)
#endif // PARALLEL_STACK_TESTS_H
