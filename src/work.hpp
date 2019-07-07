#ifndef WORK_HPP
#define WORK_HPP
#include"mem_fun_traits.hpp"
#include"has_function.hpp"
#include <iostream>

template<typename Memfunc, Memfunc memfunc, typename Callee, typename Enable = void>class work{};

template<typename Memfunc, Memfunc memfunc, typename Callee>
class work<Memfunc, memfunc, Callee, typename std::enable_if_t<has_foo<Callee>::value>>
{
    public:
    using ResultType = typename MemFunTraits<Memfunc>::ResultType;

    work():m_callee(new Callee){}
    work(Callee *callee):m_callee(callee){}
    work(work &&other):m_callee(other.m_callee){other.m_callee=nullptr;}
    work& operator = (work &&other){
        m_callee=other.m_callee;
        other.m_callee=nullptr;
        return *this;
    }

    Callee *m_callee;
    ~work(){
        std::cout<<" work destructor called "<<std::endl;
        std::cout<< std::is_same<unsigned, ResultType>::value <<std::endl;
        if(m_callee){
            delete m_callee;
        }
    }
    work& operator = (work& other){
        this->m_callee = other.m_callee;
        return *this;
    }
    work& operator = (work* other){
        this->m_callee = other->m_callee;
        return *this;
    }
    //using Impl = std::decay_t<std::remove_pointer_t<std::remove_all_extents_t<T>>>;
    ResultType operator () (){
        return (m_callee->*memfunc)();
    }
    ResultType call (){
        return (m_callee->*memfunc)();
    }

    unsigned index(){
        return m_callee->index();
    }
};

#endif // WORK_HPP
