#ifndef BINARY_TREE_TESTS_H
#define BINARY_TREE_TESTS_H
#include "autotest.h"

class binary_tree_tests : public QObject
{
    Q_OBJECT
public:
    binary_tree_tests();
    ~binary_tree_tests();
private slots:
    void initTestCase();
    void cleanupTestCase();
    void insert_pop_test_data();
    void insert_pop_test();
    void insert_unique_pop_test_data();
    void insert_unique_pop_test();
    void merge_with_test_data();
    void merge_with_test();
};



DECLARE_TEST(binary_tree_tests)
#endif // BINARY_TREE_TESTS_H
