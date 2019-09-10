#include "up_data_t1.h"

up_data_t1::up_data_t1(const unsigned Param):
    up_data(Param)
{
qDebug()<<"up_data_t1 created"<<endl;
}

up_data_t1::~up_data_t1(){}

unsigned up_data_t1::call(){
    return PARAM;
}
