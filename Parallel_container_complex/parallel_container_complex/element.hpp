#ifndef ELEMENT_HPP
#define ELEMENT_HPP
#include<QDebug>

class low_data{
public:
    low_data(unsigned Param):PARAM(Param){}
    low_data(low_data const &other):PARAM(other.PARAM){}
    virtual ~low_data(){}
    virtual unsigned call(){return PARAM;}
    virtual unsigned get_param(){return PARAM;}
    unsigned const PARAM;
};
#endif // ELEMENT_HPP
