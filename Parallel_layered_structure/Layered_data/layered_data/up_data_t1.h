#ifndef UP_DATA_T1_H
#define UP_DATA_T1_H
#include "up_data.h"

class up_data_t1 : public up_data{
public:
    up_data_t1(unsigned const Param);
    virtual ~up_data_t1()override;
    virtual unsigned call()override;
    virtual unsigned get_type()override
    {
        return 0;
    }
private:
};

#endif // UP_DATA_T1_H
