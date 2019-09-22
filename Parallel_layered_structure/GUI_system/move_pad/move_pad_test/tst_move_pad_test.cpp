#include <QtTest>
#include <QCoreApplication>
// add necessary includes here

class move_pad_test : public QObject
{
    Q_OBJECT

public:
    move_pad_test();
    ~move_pad_test();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

move_pad_test::move_pad_test()
{

}

move_pad_test::~move_pad_test()
{

}

void move_pad_test::initTestCase()
{

}

void move_pad_test::cleanupTestCase()
{

}

void move_pad_test::test_case1()
{

}

QTEST_APPLESS_MAIN(move_pad_test)

#include "tst_move_pad_test.moc"
