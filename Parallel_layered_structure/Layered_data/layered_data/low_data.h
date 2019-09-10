#ifndef LOW_DATA_H
#define LOW_DATA_H
#include<QDebug>

class low_data{
public:
    low_data();
    low_data(unsigned Param);
    low_data(low_data const &other);
    virtual ~low_data();
    virtual unsigned call();
    virtual unsigned get_param();
    virtual unsigned get_type();
    unsigned PARAM;
};

#endif // LOW_DATA_H
