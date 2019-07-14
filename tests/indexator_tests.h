#ifndef INDEXATOR_TESTS_H
#define INDEXATOR_TESTS_H
#include "autotest.h"

class indexator_tests: public QObject
{
    Q_OBJECT
public:
    indexator_tests();
    ~indexator_tests();
private slots:
    void initTestCase();
    void cleanupTestCase();
    void indexator_tests_data();
    void indexator_tests_test();
    //void indexator_tests2_data();
    //void indexator_tests2_test();
};



DECLARE_TEST(indexator_tests)
#endif // INDEXATOR_TESTS_H
