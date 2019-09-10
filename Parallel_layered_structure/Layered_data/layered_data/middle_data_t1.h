#ifndef MIDDLE_DATA_T1_H
#define MIDDLE_DATA_T1_H
#include "middle_data.h"

class middle_data_t1 : public middle_data{
public:
    middle_data_t1(unsigned const Width,
                    unsigned const Height);
    virtual ~middle_data_t1()override;
    virtual unsigned call()override;
    virtual unsigned get_type()override
    {
        return 0;
    }

private:
};

#endif // MIDDLE_DATA_T1_H
