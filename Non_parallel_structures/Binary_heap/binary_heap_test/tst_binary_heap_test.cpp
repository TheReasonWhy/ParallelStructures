#include <QtTest>
#include"binary_heap.hpp"
// add necessary includes here

class binary_heap_test : public QObject
{
    Q_OBJECT

public:
    binary_heap_test();
    ~binary_heap_test();

private slots:
    void B_heap_test_data();
    void B_heap_test();

};

binary_heap_test::binary_heap_test()
{

}

binary_heap_test::~binary_heap_test()
{

}

void binary_heap_test::B_heap_test_data()
{

}

void binary_heap_test::B_heap_test()
{

}



QTEST_APPLESS_MAIN(binary_heap_test)

#include "tst_binary_heap_test.moc"
