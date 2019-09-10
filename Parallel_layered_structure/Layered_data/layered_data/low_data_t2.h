#ifndef LOW_DATA_T2_H
#define LOW_DATA_T2_H
#include "low_data.h"


class low_data_t2 : public low_data{
public:
    low_data_t2(unsigned const Param);
    virtual ~low_data_t2()override;
    virtual unsigned call()override;
    virtual unsigned get_param()override;
    virtual unsigned get_type()override;

private:
};
#endif // LOW_DATA_T2_H
