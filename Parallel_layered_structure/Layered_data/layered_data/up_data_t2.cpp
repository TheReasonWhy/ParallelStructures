#include "up_data_t2.h"

up_data_t2::up_data_t2(const unsigned Param):
    up_data(Param)
{
qDebug()<<"up_data_t2 created"<<endl;
}

up_data_t2::~up_data_t2(){}

unsigned up_data_t2::call(){
    return PARAM;
}
