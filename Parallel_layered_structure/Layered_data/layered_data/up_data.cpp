#include "up_data.h"

up_data::up_data(){}

up_data::up_data(unsigned Param):PARAM(Param){}

up_data::up_data(const up_data &other):PARAM(other.PARAM){}

up_data::~up_data(){}

unsigned up_data::call(){
return PARAM;
}

unsigned up_data::get_type()
{
    return 3;
}

