#ifndef WORKABLE_H
#define WORKABLE_H

#include "workables_global.h"

struct WORKABLESSHARED_EXPORT initializer_type_example_class{
initializer_type_example_class():first(0),second(0){}
initializer_type_example_class(unsigned F):first(F){}
    unsigned first;
    char second;
};

struct WORKABLESSHARED_EXPORT initializer_type_victim{
initializer_type_victim():first(0),second(0){}
initializer_type_victim(unsigned F):first(F){}
    unsigned first;
    char second;
};

template<typename Parameter_Pack_Type,typename Derived>
class WORKABLESSHARED_EXPORT workable
{
public:
};



#endif // WORKABLE_H
