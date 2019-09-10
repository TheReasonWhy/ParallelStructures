#ifndef ROUTABLE_HPP
#define ROUTABLE_HPP
#include<QDebug>


class middle_data{
public:
    middle_data(unsigned Width, unsigned Height);
    middle_data(middle_data const &other);
    virtual ~middle_data();
    virtual unsigned get_size();
    virtual void call();
    unsigned const WIDTH;
    unsigned const HEIGHT;
};

#endif // ROUTABLE_HPP



middle_data::middle_data(unsigned Width, unsigned Height):WIDTH(Width),HEIGHT(Height){

}

middle_data::middle_data(const middle_data &other):WIDTH(other.WIDTH),HEIGHT(other.HEIGHT){}

middle_data::~middle_data(){}

unsigned middle_data::get_size(){
    return WIDTH*HEIGHT;
}

void middle_data::call(){
}
