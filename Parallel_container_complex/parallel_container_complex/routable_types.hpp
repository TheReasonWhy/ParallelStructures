#ifndef TEST_TYPES_HPP
#define TEST_TYPES_HPP
#include<routable.hpp>
#include<vector>

class middle_data_t1 : public middle_data{
public:
    middle_data_t1(unsigned const Width,
                    unsigned const Height);
    virtual ~middle_data_t1()override;
    virtual void call()override;

private:
};

class middle_data_t2 : public middle_data{
public:
    middle_data_t2(unsigned const Width,
                    unsigned const Height);
    virtual ~middle_data_t2()override;
    virtual void call()override;

private:
};
#endif // TEST_TYPES_HPP

middle_data_t1::middle_data_t1(const unsigned Width, const unsigned Height):
    middle_data(Width, Height)
{
    qDebug()<<"test_type_2 created"<<endl;
}

middle_data_t1::~middle_data_t1(){}

void middle_data_t1::call(){
    qDebug()<<"me test_type2"<<endl;
}

middle_data_t2::middle_data_t2(const unsigned Width, const unsigned Height):
    middle_data(Width, Height)
{
    qDebug()<<"test_type_2 created"<<endl;
}

middle_data_t2::~middle_data_t2(){}

void middle_data_t2::call(){
    qDebug()<<"me test_type2"<<endl;
}
