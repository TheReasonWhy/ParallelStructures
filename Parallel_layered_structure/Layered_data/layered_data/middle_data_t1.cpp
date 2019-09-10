#include "middle_data_t1.h"

middle_data_t1::middle_data_t1(const unsigned Width, const unsigned Height):
    middle_data(Width, Height)
{
    qDebug()<<"middle_data_t1 created"<<endl;
}

middle_data_t1::~middle_data_t1(){}

unsigned middle_data_t1::call(){
    return WIDTH*HEIGHT;
}
