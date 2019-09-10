#ifndef ELEMENT_TYPES_HPP
#define ELEMENT_TYPES_HPP
#include<element.hpp>



class low_data_t1 : public low_data{
public:
    low_data_t1(unsigned const Param);
    virtual ~low_data_t1()override;
    virtual unsigned call()override;
    virtual unsigned get_param()override;

private:
};

class low_data_t2 : public low_data{
public:
    low_data_t2(unsigned const Param);
    virtual ~low_data_t2()override;
    virtual unsigned call()override;
    virtual unsigned get_param()override;

private:
};
low_data_t1::low_data_t1(const unsigned Param):
    low_data(Param)
{
}

low_data_t1::~low_data_t1(){}

unsigned low_data_t1::call(){
    //qDebug()<<"me Element_type_1"<<endl;
    return PARAM;
}

unsigned low_data_t1::get_param()
{
    return PARAM;
}

low_data_t2::low_data_t2(const unsigned Param):
    low_data(Param)
{
    //qDebug()<<"Element_type_2 created"<<endl;
}

low_data_t2::~low_data_t2(){}

unsigned low_data_t2::call(){
    //qDebug()<<"me Element_type_2"<<endl;
    return PARAM;
}

unsigned low_data_t2::get_param()
{
    return PARAM;
}
#endif // ELEMENT_TYPES_HPP
