#include "middle_data.h"
middle_data::middle_data(){}

middle_data::middle_data(unsigned Width, unsigned Height):WIDTH(Width),HEIGHT(Height){

}

middle_data::middle_data(const middle_data &other):WIDTH(other.WIDTH),HEIGHT(other.HEIGHT){}

middle_data::~middle_data(){}

unsigned middle_data::get_size(){
    return WIDTH*HEIGHT;
}

unsigned middle_data::call(){
    return WIDTH*HEIGHT;
}

unsigned middle_data::get_type()
{
    return 3;
}
