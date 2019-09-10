#include <QtTest>
#include<threadpool_binary_tree.hpp>

// add necessary includes here

class threadpool_test : public QObject
{
    Q_OBJECT

public:
    threadpool_test();
    ~threadpool_test();

private slots:
    void test_case1();

};

threadpool_test::threadpool_test()
{

}

threadpool_test::~threadpool_test()
{

}

void threadpool_test::test_case1()
{
qDebug()<<"... test_case1..."<<endl;
}

QTEST_APPLESS_MAIN(threadpool_test)

#include "tst_threadpool_test.moc"
