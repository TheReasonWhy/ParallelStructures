#ifndef MIDDLE_DATA_T2_H
#define MIDDLE_DATA_T2_H
#include "middle_data.h"

class middle_data_t2 : public middle_data{
public:
    middle_data_t2(unsigned const Width,
                    unsigned const Height);
    virtual ~middle_data_t2()override;
    virtual unsigned call()override;
    virtual unsigned get_type()override
    {
        return 1;
    }

private:
};
#endif // MIDDLE_DATA_T2_H
