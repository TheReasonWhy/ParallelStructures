#include "work_generator_tests.h"

work_generator_tests::work_generator_tests()
{

}

work_generator_tests::~work_generator_tests()
{

}

void work_generator_tests::initTestCase()
{

}

void work_generator_tests::cleanupTestCase()
{

}

void work_generator_tests::work_generator_test_data()
{
    qDebug()<<"... work_generator_test_data ..."<<endl;
}

void work_generator_tests::work_generator_test()
{
    qDebug()<<"... work_generator_test_starts..."<<endl;

    work_generator <decltype(&victim::get_value_c), (&victim::get_value_c), victim> WG;

    QCOMPARE(WG.reset_control_sum(),true);

    QCOMPARE(WG.create_test_works(10),true);
    QCOMPARE(WG.perform_test_works(),true);
    QCOMPARE(WG.get_control_sum(),WG.get_accumulated_sum());

    qDebug()<<"... work_generator_test_ends..."<<endl;
}
