#ifndef MIDDLE_DATA_H
#define MIDDLE_DATA_H
#include<QDebug>


class middle_data{
public:
    middle_data();
    middle_data(unsigned Width, unsigned Height);
    middle_data(middle_data const &other);
    virtual ~middle_data();
    virtual unsigned get_size();
    virtual unsigned call();
    virtual unsigned get_type();
    unsigned WIDTH;
    unsigned HEIGHT;
};






#endif // MIDDLE_DATA_H
