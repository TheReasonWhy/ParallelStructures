#ifndef PARALLEL_SET_TESTS_H
#define PARALLEL_SET_TESTS_H
#include "autotest.h"

class parallel_set_tests : public QObject
{
    Q_OBJECT
public:
    parallel_set_tests();
    ~parallel_set_tests();
private slots:
    void initTestCase();
    void cleanupTestCase();
    void parallel_set_test_data();
    void parallel_set_test();
};


DECLARE_TEST(parallel_set_tests)
#endif // PARALLEL_SET_TESTS_H
