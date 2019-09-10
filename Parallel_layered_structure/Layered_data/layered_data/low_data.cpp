#include "low_data.h"


low_data::low_data(){}

low_data::low_data(unsigned Param):PARAM(Param){}

low_data::low_data(const low_data &other):PARAM(other.PARAM){}

low_data::~low_data(){}

unsigned low_data::call(){return PARAM;}

unsigned low_data::get_param(){return PARAM;}

unsigned low_data::get_type()
{
    return 3;
}
