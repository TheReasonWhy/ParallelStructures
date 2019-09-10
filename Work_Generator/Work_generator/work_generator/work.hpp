#ifndef WORK_HPP
#define WORK_HPP
#include"mem_fun_traits.hpp"
#include"has_function.hpp"
#include<QDebug>
#include<thread>
#include<chrono>

template<typename Memfunc, Memfunc memfunc, typename Callee, typename... Params>class work;

template<typename Memfunc, Memfunc memfunc, typename Callee>
class work<Memfunc, memfunc, Callee>
{
    public:
    using ResultType = typename MemFunTraits<Memfunc>::ResultType;
    work(){}
    work(Callee *callee, unsigned index):m_callee(callee),m_index(index){    }
    work(Callee &callee, unsigned index):m_callee(&callee),m_index(index){}
    //work(std::unique_ptr<Callee> callee):m_callee(callee.get()){}
    work(work &other):m_callee(other.m_callee),m_index(other.m_index){}
    work(work &&other):m_callee(other.m_callee),m_index(other.m_index){
        other.m_callee=nullptr;
    }
    work& operator = (work &&other){
        m_callee=other.m_callee;
        m_index=other.m_index;
        other.m_callee=nullptr;
        return *this;
    }
    ~work(){
        m_callee=nullptr;
    }
    Callee *m_callee;
    unsigned m_index;


    work& operator = (work& other){
        this->m_callee = other.m_callee;
        this->m_index = other.m_index;
        return *this;
    }
    work& operator = (work const &other){
        this->m_callee = other.m_callee;
        this->m_index = other.m_index;
        return *this;
    }
    work& operator = (work* other){
        this->m_callee = other->m_callee;
        this->m_index = other->m_index;
        return *this;
    }
    //using Impl = std::decay_t<std::remove_pointer_t<std::remove_all_extents_t<T>>>;
    ResultType operator () (){
        std::chrono::milliseconds ms(10);
        std::this_thread::sleep_for(ms);
        return (m_callee->*memfunc)();
    }
    ResultType call (){
        return (m_callee->*memfunc)();
    }
    unsigned index()const{
        return m_index;
    }
};

template<typename Memfunc, Memfunc memfunc, typename Callee, typename Param>
class work<Memfunc, memfunc, Callee, Param>
{
    public:
    using ResultType = typename MemFunTraits<Memfunc>::ResultType;
    work(){}
    work(Callee *callee, unsigned index, Param param):m_callee(callee),m_param(param),m_index(index){}
    work(Callee &callee, unsigned index, Param param):m_callee(&callee),m_param(param),m_index(index){}
    //work(std::unique_ptr<Callee> callee):m_callee(callee.get()){}
    work(work &other):m_callee(other.m_callee),m_param(other.m_param),m_index(other.m_index){}
    work(work &&other):m_callee(other.m_callee),m_param(other.m_param),m_index(other.m_index){
        other.m_callee=nullptr;
    }
    work& operator = (work &&other){
        m_callee=other.m_callee;
        m_index=other.m_index;
        m_param=other.m_param;
        other.m_callee=nullptr;
        return *this;
    }

    Callee *m_callee;
    Param m_param;
    unsigned m_index;

    ~work(){
        m_callee=nullptr;
    }
    work& operator = (work& other){
        this->m_callee = other.m_callee;
        this->m_index = other.m_index;
        this->m_param=other.m_param;
        return *this;
    }
    work& operator = (work const &other){
        this->m_callee = other.m_callee;
        this->m_index = other.m_index;
        this->m_param=other.m_param;
        return *this;
    }
    work& operator = (work* other){
        this->m_callee = other->m_callee;
        this->m_index = other->m_index;
        this->m_param=other->m_param;
        return *this;
    }
    //using Impl = std::decay_t<std::remove_pointer_t<std::remove_all_extents_t<T>>>;
    ResultType operator () (){
        //std::chrono::milliseconds ms(300);
        //std::this_thread::sleep_for(ms);
        return (m_callee->*memfunc)(m_param);
    }
    ResultType call(){
        return (m_callee->*memfunc)(m_param);
    }
    unsigned index()const{
        return m_index;
    }
};
template<typename Memfunc, Memfunc memfunc, typename Callee, typename Param1, typename Param2>
class work<Memfunc, memfunc, Callee, Param1, Param2>
{
    public:
    using ResultType = typename MemFunTraits<Memfunc>::ResultType;
    work(){}
    work(Callee *callee, unsigned index, Param1 param1, Param2 param2):m_callee(callee),m_param1(param1),m_param2(param2),m_index(index){}
    work(Callee &callee, unsigned index, Param1 param1, Param2 param2):m_callee(&callee),m_param1(param1),m_param2(param2),m_index(index){}
    //work(std::unique_ptr<Callee> callee):m_callee(callee.get()){}
    work(work &other):m_callee(other.m_callee),m_param1(other.m_param1),m_param2(other.m_param2),m_index(other.m_index){}
    work(work &&other):m_callee(other.m_callee),m_param1(other.m_param1),m_param2(other.m_param2),m_index(other.m_index){
        other.m_callee=nullptr;
    }
    work& operator = (work &&other){
        m_callee=other.m_callee;
        m_index=other.m_index;
        m_param1=other.m_param1;
        m_param2=other.m_param2;
        other.m_callee=nullptr;
        return *this;
    }

    Callee *m_callee;
    Param1 m_param1;
    Param2 m_param2;
    unsigned m_index;

    ~work(){
        m_callee=nullptr;
    }
    work& operator = (work& other){
        this->m_callee = other.m_callee;
        this->m_index = other.m_index;
        this->m_param1=other.m_param1;
        this->m_param2=other.m_param2;
        return *this;
    }
    work& operator = (work const &other){
        this->m_callee = other.m_callee;
        this->m_index = other.m_index;
        this->m_param1=other.m_param1;
        this->m_param2=other.m_param2;
        return *this;
    }
    work& operator = (work* other){
        this->m_callee = other->m_callee;
        this->m_index = other->m_index;
        this->m_param1=other->m_param1;
        this->m_param2=other->m_param2;
        return *this;
    }
    //using Impl = std::decay_t<std::remove_pointer_t<std::remove_all_extents_t<T>>>;
    ResultType operator () (){
        std::chrono::milliseconds ms(300);
        std::this_thread::sleep_for(ms);
        return (m_callee->*memfunc)(m_param1,m_param2);
    }
    ResultType call (){
        return (m_callee->*memfunc)(m_param1,m_param2);
    }
    unsigned index()const{
        return m_index;
    }
};

template<typename Type, typename Param>
class work_static_element
{
    public:
    using ResultType = typename Type::ResultType;
    work_static_element(){}
    work_static_element(unsigned index, Param param):m_param(param),m_index(index){}
    //work(std::unique_ptr<Callee> callee):m_callee(callee.get()){}
    work_static_element(work_static_element &other):m_param(other.m_param),m_index(other.m_index){}
    work_static_element(work_static_element &&other):m_param(other.m_param),m_index(other.m_index){
    }
    work_static_element& operator = (work_static_element &&other){
        m_index=other.m_index;
        m_param=other.m_param;
        return *this;
    }

    Param m_param;
    unsigned m_index;

    ~work_static_element(){
    }
    work_static_element& operator = (work_static_element& other){
        this->m_param = other.m_param;
        this->m_index = other.m_index;
        return *this;
    }
    work_static_element& operator = (work_static_element const &other){
        this->m_index = other.m_index;
        this->m_param=other.m_param;
        return *this;
    }
    work_static_element& operator = (work_static_element* other){
        this->m_index = other->m_index;
        this->m_param=other->m_param;
        return *this;
    }
    //using Impl = std::decay_t<std::remove_pointer_t<std::remove_all_extents_t<T>>>;
    ResultType operator () (){
        std::chrono::milliseconds ms(300);
        std::this_thread::sleep_for(ms);
        return Type::call_element(m_param);
    }
    ResultType call (){
        return Type::call_element(m_param);
    }
    unsigned index()const{
        return m_index;
    }
};


#endif // WORK_HPP













