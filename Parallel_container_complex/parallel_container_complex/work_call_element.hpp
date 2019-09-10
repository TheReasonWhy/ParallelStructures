#ifndef WORK_CALL_ELEMENT_HPP
#define WORK_CALL_ELEMENT_HPP
#include<level_system.hpp>

template <size_t LEVELS_NUM, size_t ROUTABLES_NUM, size_t ELEMENTS_NUM,typename... Args>
class work_call_element;

template<size_t LEVELS_NUM, size_t ROUTABLES_NUM, size_t ELEMENTS_NUM, template<size_t,size_t,size_t>class Derived >
class work_call_element<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM,Level_system<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM,Derived>>{
    public:
    using LS = Level_system<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM,Derived>;
    work_call_element(){}
    work_call_element(unsigned element_index_absolute):m_element_index_absolute(element_index_absolute){}
    //work(std::unique_ptr<Callee> callee):m_callee(callee.get()){}
    work_call_element(work_call_element &other):m_element_index_absolute(other.m_element_index_absolute){}
    work_call_element(work_call_element &&other):m_element_index_absolute(other.m_element_index_absolute){
    }
    work_call_element& operator = (work_call_element &&other){
        m_element_index_absolute=other.m_element_index_absolute;
        return *this;
    }

    unsigned m_element_index_absolute;

    ~work_call_element(){
    }
    work_call_element& operator = (work_call_element& other){
        this->m_element_index_absolute = other.m_element_index_absolute;
        return *this;
    }
    work_call_element& operator = (work_call_element const &other){
        this->m_element_index_absolute = other.m_element_index_absolute;
        return *this;
    }
    work_call_element& operator = (work_call_element* other){
        this->m_element_index_absolute = other->m_element_index_absolute;
        return *this;
    }
    unsigned operator () (){
        return LS::call_element(m_element_index_absolute);
    }
    unsigned call (){
        return LS::call_element(m_element_index_absolute);
    }
    unsigned index(){
        return m_element_index_absolute;
    }
};
#endif // WORK_CALL_ELEMENT_HPP
