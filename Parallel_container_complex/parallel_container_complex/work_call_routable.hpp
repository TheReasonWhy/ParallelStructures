#ifndef WORK_CALL_ROUTABLE_HPP
#define WORK_CALL_ROUTABLE_HPP

#include<level_system.hpp>

template <size_t LEVELS_NUM, size_t ROUTABLES_NUM, size_t ELEMENTS_NUM,typename... Args>
class work_call_routable;

template<size_t LEVELS_NUM, size_t ROUTABLES_NUM, size_t ELEMENTS_NUM, template<size_t,size_t,size_t>class Derived >
class work_call_routable<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM,Level_system<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM,Derived>>{
    public:
    using LS = Level_system<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM,Derived>;
    work_call_routable(){}
    work_call_routable(unsigned routable_index_absolute):m_routable_index_absolute(routable_index_absolute){}
    //work(std::unique_ptr<Callee> callee):m_callee(callee.get()){}
    work_call_routable(work_call_routable &other):m_routable_index_absolute(other.m_routable_index_absolute){}
    work_call_routable(work_call_routable &&other):m_routable_index_absolute(other.m_routable_index_absolute){
    }
    work_call_routable& operator = (work_call_routable &&other){
        m_routable_index_absolute=other.m_routable_index_absolute;
        return *this;
    }

    unsigned m_routable_index_absolute;

    ~work_call_routable(){
    }
    work_call_routable& operator = (work_call_routable& other){
        this->m_routable_index_absolute = other.m_routable_index_absolute;
        return *this;
    }
    work_call_routable& operator = (work_call_routable const &other){
        this->m_routable_index_absolute = other.m_routable_index_absolute;
        return *this;
    }
    work_call_routable& operator = (work_call_routable* other){
        this->m_routable_index_absolute = other->m_routable_index_absolute;
        return *this;
    }
    unsigned operator () (){
        return LS::call_middle(m_routable_index_absolute);
    }
    unsigned call (){
        return LS::call_middle(m_routable_index_absolute);
    }
    unsigned index(){
        return m_routable_index_absolute;
    }
};
#endif // WORK_CALL_ROUTABLE_HPP
