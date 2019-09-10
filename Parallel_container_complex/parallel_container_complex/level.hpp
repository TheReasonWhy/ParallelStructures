#ifndef LEVEL_HPP
#define LEVEL_HPP
#include<QDebug>

class up_data{
public:
    up_data(unsigned Param):PARAM(Param){}
    up_data(up_data const &other):PARAM(other.PARAM){}
    virtual ~up_data(){}
    virtual void call(){}
    unsigned const PARAM;
};
#endif // LEVEL_HPP
