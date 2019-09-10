#ifndef UP_DATA_H
#define UP_DATA_H
#include<QDebug>

class up_data{
public:
    up_data();
    up_data(unsigned Param);
    up_data(up_data const &other);
    virtual ~up_data();
    virtual unsigned call();
    virtual unsigned get_type();
    unsigned PARAM;
};

#endif // UP_DATA_H
