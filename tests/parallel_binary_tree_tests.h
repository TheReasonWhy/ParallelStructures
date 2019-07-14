#ifndef PARALLEL_BINARY_TREE_TESTS_H
#define PARALLEL_BINARY_TREE_TESTS_H
#include "autotest.h"

class parallel_binary_tree_tests : public QObject
{
    Q_OBJECT
   public:
       parallel_binary_tree_tests();
       ~parallel_binary_tree_tests();

   private slots:
       void initTestCase();
       void cleanupTestCase();
       void binary_tree_test_data();
       void binary_tree_test();
};
DECLARE_TEST(parallel_binary_tree_tests)
#endif // PARALLEL_BINARY_TREE_TESTS_H
