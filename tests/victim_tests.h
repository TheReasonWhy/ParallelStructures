#ifndef VICTIM_TESTS_H
#define VICTIM_TESTS_H
#include "autotest.h"

class victim_tests : public QObject
{
    Q_OBJECT
public:
    victim_tests();
    ~victim_tests();
private slots:
    void initTestCase();
    void cleanupTestCase();
    void victim_test_data();
    void victim_test();

};

DECLARE_TEST(victim_tests)
#endif // VICTIM_TESTS_H
