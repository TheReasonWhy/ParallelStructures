#ifndef VICTIM_H
#define VICTIM_H
#include<QDebug>
#include"workable.h"

template<typename Parameter_Pack_Type = initializer_type_victim>
class WORKABLESSHARED_EXPORT victim : public workable<Parameter_Pack_Type,victim<>>
{
public:
    using Param_type = Parameter_Pack_Type;
    using Index_type = unsigned;
    victim():
        m_value(0)
    {
        m_index=victim::VICTIMINDEX;
        victim::VICTIMINDEX++;
    }
    victim(Parameter_Pack_Type P):m_value(P.first){
        m_index=victim::VICTIMINDEX;
        victim::VICTIMINDEX++;
    }

    victim(unsigned value):
        m_value(value){
        m_index=victim::VICTIMINDEX;
        victim::VICTIMINDEX++;
    }
    victim(victim &&other):
        m_value(other.m_value),m_index(other.m_index)
    {
        other.m_value=0;
        other.m_index=0;
    }
    /**/
    victim(const victim &other){
        m_value=other.m_value;
        m_index=other.m_index;
    }
    victim &operator =(victim const& other){
        m_value=other.m_value;
        m_index=other.m_index;
        return *this;
    }
    victim& operator = (victim &&other)
    {
        m_value=other.m_value;
        m_index=other.m_index;
        other.m_index=0;
        other.m_value=0;
        return *this;
    }

    ~victim(){}

    unsigned operator()(){
        return m_index;
    }
    unsigned get_value(){
        return m_value;
    }
    unsigned get_element_absolute_id(){
        return m_index;
    }
    unsigned index()const{
        return m_index;
    }
    unsigned m_value;
    unsigned m_index;
    inline static unsigned VICTIMINDEX = 0;
};

#endif // VICTIM_H
