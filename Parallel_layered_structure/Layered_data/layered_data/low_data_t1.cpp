#include "low_data_t1.h"


low_data_t1::low_data_t1(const unsigned Param):
    low_data(Param)
{
}

unsigned low_data_t1::call(){
    //qDebug()<<"me Element_type_1"<<endl;
    return PARAM;
}

low_data_t1::~low_data_t1(){}

unsigned low_data_t1::get_param()
{
    return PARAM;
}

unsigned low_data_t1::get_type()
{
    return 0;
}
