#include "middle_data_t2.h"



middle_data_t2::middle_data_t2(const unsigned Width, const unsigned Height):
    middle_data(Width, Height)
{
    qDebug()<<"middle_data_t2 created"<<endl;
}

middle_data_t2::~middle_data_t2(){}

unsigned middle_data_t2::call(){
    return WIDTH*HEIGHT;
}
