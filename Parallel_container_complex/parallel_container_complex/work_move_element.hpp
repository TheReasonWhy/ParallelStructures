#ifndef WORK_MOVE_ELEMENT_HPP
#define WORK_MOVE_ELEMENT_HPP
#include<level_system.hpp>

template <size_t LEVELS_NUM, size_t ROUTABLES_NUM, size_t ELEMENTS_NUM,typename... Args>
class work_move_element;

template<size_t LEVELS_NUM, size_t ROUTABLES_NUM, size_t ELEMENTS_NUM, template<size_t,size_t,size_t>class Derived >
class work_move_element<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM,Level_system<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM,Derived>>{
    public:
    using LS = Level_system<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM,Derived>;
    work_move_element(){}
    work_move_element(unsigned From, unsigned To):m_From(From),m_To(To){}
    //work(std::unique_ptr<Callee> callee):m_callee(callee.get()){}
    work_move_element(work_move_element &other):m_From(other.m_From),m_To(other.m_To){}
    work_move_element(work_move_element &&other):m_From(other.m_From),m_To(other.m_To){
    }
    work_move_element& operator = (work_move_element &&other){
        m_From=other.m_From;
        m_To=other.m_To;
        return *this;
    }

    unsigned m_From;
    unsigned m_To;

    ~work_move_element(){
    }
    work_move_element& operator = (work_move_element& other){
        this->m_From = other.m_From;
        this->m_To = other.m_To;
        return *this;
    }
    work_move_element& operator = (work_move_element const &other){
        this->m_From = other.m_From;
        this->m_To=other.m_To;
        return *this;
    }
    work_move_element& operator = (work_move_element* other){
        this->m_From = other->m_From;
        this->m_To=other->m_To;
        return *this;
    }
    void operator () (){
        return LS::call_move(m_From,m_To);
    }
    void call (){
        return LS::call_move(m_From,m_To);
    }
    unsigned index(){
        return m_From;
    }
};

#endif // WORK_MOVE_ELEMENT_HPP
