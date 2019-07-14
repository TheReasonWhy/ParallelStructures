#ifndef BINARY_HEAP_TESTS_H
#define BINARY_HEAP_TESTS_H
#include "autotest.h"

class binary_heap_tests: public QObject
{
    Q_OBJECT
public:
    binary_heap_tests();
    ~binary_heap_tests();
private slots:
    void initTestCase();
    void cleanupTestCase();
    void binary_heap_test_data();
    void binary_heap_test();
};


DECLARE_TEST(binary_heap_tests)
#endif // BINARY_HEAP_TESTS_H
