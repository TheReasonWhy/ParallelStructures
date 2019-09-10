#ifndef EXAMPLE_CLASS_H
#define EXAMPLE_CLASS_H

#include"workable.h"


template<typename Parameter_Pack_Type = initializer_type_example_class>
class WORKABLESSHARED_EXPORT example_class : public workable<Parameter_Pack_Type,example_class<>>
{

public:
using Index_type = unsigned;
using Param_type = Parameter_Pack_Type;
    example_class(Index_type value):m_value(value){}
    example_class(Parameter_Pack_Type P):m_value(P.first){}
    example_class(Index_type value,Parameter_Pack_Type P):m_value(value),m_index(P.first){}
    Index_type index(){
        return m_value;
    }
private:
Index_type m_value;
unsigned m_index;
};

#endif // EXAMPLE_CLASS_H
