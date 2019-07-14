#ifndef WORK_GENERATOR_TESTS_H
#define WORK_GENERATOR_TESTS_H
#include "autotest.h"

class work_generator_tests : public QObject
{
        Q_OBJECT
public:
    work_generator_tests();
    ~work_generator_tests();
private slots:
    void initTestCase();
    void cleanupTestCase();
    void work_generator_test_data();
    void work_generator_test();
};

DECLARE_TEST(work_generator_tests)
#endif // WORK_GENERATOR_TESTS_H
