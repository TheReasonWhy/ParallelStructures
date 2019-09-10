#include <QtTest>
#include"example_class.h"
#include"factory_abstract.hpp"
// add necessary includes here

class factory_abstract_test : public QObject
{
    Q_OBJECT

public:
    factory_abstract_test();
    ~factory_abstract_test();

private slots:
    void FA_test_data();
    void FA_test();

};

factory_abstract_test::factory_abstract_test()
{

}

factory_abstract_test::~factory_abstract_test()
{

}

void factory_abstract_test::FA_test_data()
{
    qDebug()<<"... factory_abstract_test_data ..."<<endl;

}
void factory_abstract_test::FA_test()
{
    qDebug()<<"... factory_abstract_test ..."<<endl;

    qDebug()<<"... factory_abstract_test ends..."<<endl;
}

QTEST_APPLESS_MAIN(factory_abstract_test)

#include "tst_factory_abstract_test.moc"
