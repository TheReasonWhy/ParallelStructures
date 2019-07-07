#ifndef VICTIM_H
#define VICTIM_H
#include<QDebug>


class victim{
public:
    victim():
        m_value(10000)
    {
        m_index=victim::VICTIMINDEX;
        victim::VICTIMINDEX++;
    }

    victim(unsigned value):
        m_value(value){
        qDebug() << "created with value" << m_value << endl;
        m_index=victim::VICTIMINDEX;
        victim::VICTIMINDEX++;
    }
    victim(victim &&other):
        m_value(other.m_value),m_index(other.m_index)
    {
        other.m_value=0;
        other.m_index=0;
    }
    victim(const victim &other):
        m_value(other.m_value),m_index(other.m_index)
    {}
    victim& operator = (victim const& other){
        m_value=other.m_value;
        m_index=other.m_index;
        return *this;
    }
    victim& operator = (victim &&other){
        m_value=other.m_value;
        m_index=other.m_index;
        other.m_value=0;
        other.m_index=0;
        return *this;
    }



    ~victim(){}

    unsigned operator()(){
        return m_index;
    }
    unsigned get_value(){
        return m_value;
    }
    unsigned get_value_c(){
        qDebug() << "I was called sum_accumulated" << sum_accumulated <<"m_value" <<m_value << endl;
        sum_accumulated+=m_value;
        return m_value;
    }
    unsigned index() {
        return m_index;
    }
    static unsigned get_sum_accumulated()
    {
        return sum_accumulated;
    }
    static void reset_sum()
    {
        sum_accumulated = 0;
    }
    unsigned m_value;
    unsigned m_index;    
    inline static unsigned sum_accumulated = 0;
    inline static unsigned VICTIMINDEX = 0;
};

#endif // VICTIM_H
