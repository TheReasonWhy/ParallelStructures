#ifndef LEVEL_TYPES_HPP
#define LEVEL_TYPES_HPP
#include<level.hpp>

class up_data_t1 : public up_data{
public:
    up_data_t1(unsigned const Param);
    virtual ~up_data_t1()override;
    virtual void call()override;
private:
};

class up_data_t2 : public up_data{
public:
    up_data_t2(unsigned const Param);
    virtual ~up_data_t2()override;
    virtual void call()override;
private:
};
up_data_t1::up_data_t1(const unsigned Param):
    up_data(Param)
{
    qDebug()<<"Level_type_1 created"<<endl;
}

up_data_t1::~up_data_t1(){}

void up_data_t1::call(){
    qDebug()<<"me Level_type_1"<<endl;
}

up_data_t2::up_data_t2(const unsigned Param):
    up_data(Param)
{
    qDebug()<<"Level_type_2 created"<<endl;
}

up_data_t2::~up_data_t2(){}

void up_data_t2::call(){
    qDebug()<<"me Level_type_2"<<endl;
}
#endif // LEVEL_TYPES_HPP
