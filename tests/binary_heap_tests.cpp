#include "binary_heap_tests.h"

binary_heap_tests::binary_heap_tests()
{

}

binary_heap_tests::~binary_heap_tests()
{

}

void binary_heap_tests::initTestCase()
{

}

void binary_heap_tests::cleanupTestCase()
{

}

void binary_heap_tests::binary_heap_test_data()
{
    qDebug()<<"... binary_heap_test_data ..."<<endl;
}

void binary_heap_tests::binary_heap_test()
{
    qDebug()<<"... binary_heap_test..."<<endl;

    std::array<unsigned, 10> AR{10,11,2,333,545,363,25,117,34,63};
    std::array<unsigned, 10> sorted_AR = *(heap_sort<unsigned,AR.size(),std::array, std::array>(AR).get());

    std::array<unsigned, 15> AR2{150,551,33,44,545,363,25,117,34,63,25,117,34,63,94};
    std::array<unsigned, 15> sorted_AR2 = *(heap_sort<unsigned,AR2.size(),std::array, std::array>(AR2).get());

    std::vector<unsigned> V1{910,141,92,3,54,36,25,117,4,963};
    std::array<unsigned, 10> sorted_V1 = *(heap_sort<unsigned,10,std::vector, std::array>(V1).get());

    std::array<unsigned, 10> AR3{910,141,92,3,54,36,25,117,4,963};
    std::array<unsigned, 10> sorted_AR3 = AR3;
    heap_sort<unsigned,10,std::array>(sorted_AR3);

    std::vector<unsigned> V2{910,141,92,3,54,36,25,117,4,963};
    std::vector<unsigned> sorted_V2 = *(heap_sort<unsigned,10,std::vector>(V2).get());


    QCOMPARE(AR.at(4),sorted_AR.at(9));
    QCOMPARE(AR2.at(1),sorted_AR2.at(14));
    QCOMPARE(V1.at(3),sorted_V1.at(0));
    QCOMPARE(AR3.at(3),sorted_AR3.at(9));
    QCOMPARE(V2.at(3),sorted_V2.at(0));


    qDebug()<<"... binary_heap_test_ends..."<<endl;
}





















