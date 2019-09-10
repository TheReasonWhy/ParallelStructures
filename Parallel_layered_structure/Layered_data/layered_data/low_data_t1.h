#ifndef LOW_DATA_T1_H
#define LOW_DATA_T1_H
#include "low_data.h"

class low_data_t1 : public low_data{
public:
    low_data_t1(unsigned const Param);
    virtual ~low_data_t1()override;
    virtual unsigned call()override;
    virtual unsigned get_param()override;
    virtual unsigned get_type()override;
private:
};

#endif // LOW_DATA_T1_H
