#ifndef VICTIM_COMPLEX_HPP
#define VICTIM_COMPLEX_HPP
#include<QDebug>
#include"workable.h"

template<typename Parameter_Pack_Type = initializer_type_victim>
class WORKABLESSHARED_EXPORT victim_complex : public workable<Parameter_Pack_Type,victim_complex<>>
{
public:
    using Param_type = Parameter_Pack_Type;
    using Index_type = unsigned;
    victim_complex():
        m_value(0)
    {
        m_index=victim_complex::VICTIMINDEX;
        victim_complex::VICTIMINDEX++;
    }
    victim_complex(Parameter_Pack_Type P):m_value(P.first){
        m_index=victim_complex::VICTIMINDEX;
        victim_complex::VICTIMINDEX++;
    }

    victim_complex(unsigned value):
        m_value(value){
        m_index=victim_complex::VICTIMINDEX;
        victim_complex::VICTIMINDEX++;
    }
    victim_complex(victim_complex &&other):
        m_value(other.m_value),m_index(other.m_index)
    {
        other.m_value=0;
        other.m_index=0;
    }
    /**/
    victim_complex(const victim_complex &other){
        m_value=other.m_value;
        m_index=other.m_index;
    }
    victim_complex &operator =(victim_complex const& other){
        m_value=other.m_value;
        m_index=other.m_index;
        return *this;
    }
    victim_complex& operator = (victim_complex &&other)
    {
        m_value=other.m_value;
        m_index=other.m_index;
        other.m_index=0;
        other.m_value=0;
        return *this;
    }

    ~victim_complex(){}

    unsigned operator()(){
        return m_index;
    }
    unsigned get_value(){
        return m_value;
    }
    unsigned index()const{
        return m_index;
    }
    void add_neighbour(std::pair<unsigned,unsigned> neighbour){
        m_neighbours.push_back(neighbour);
    }
    std::vector<std::pair<unsigned,unsigned>> &get_neighbours()const{
        return m_neighbours;
    }
    unsigned m_value;
    unsigned m_index;
    std::vector<std::pair<unsigned,unsigned>> &m_neighbours;
    inline static unsigned VICTIMINDEX = 0;
};
#endif // VICTIM_COMPLEX_HPP
