#include "low_data_t2.h"
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

unsigned low_data_t2::get_type()
{
    return 1;
}
