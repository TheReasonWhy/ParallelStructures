#ifndef UP_DATA_T2_H
#define UP_DATA_T2_H
#include "up_data.h"
class up_data_t2 : public up_data{
public:
    up_data_t2(unsigned const Param);
    virtual ~up_data_t2()override;
    virtual unsigned call()override;
    virtual unsigned get_type()override
    {
        return 1;
    }
private:
};

#endif // UP_DATA_T2_H
