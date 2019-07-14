#ifndef PARALLEL_CONTAINER_HPP
#define PARALLEL_CONTAINER_HPP
#include<atomic>
#include<type_traits>
#include<utility>
#include<functional>
#include <iostream>
#include <typeinfo>
#include<QDebug>
#include<memory>

template <typename T,typename ... Args>
class type_traits
{
    public:
    using T_cleared = std::remove_pointer_t<std::remove_reference_t<T>>;
    using T_pointer = T_cleared*;
    using T_reference = T_cleared&;
};

template <typename T,template<typename,typename ... Args>class container,typename ... Args>// T parallel_set parallel_queue Args
class Base
{
public:
    using parallel_container = container<T, Args...>;
    using T_point = typename type_traits<T, Args...>::T_pointer;
    using T_ref = typename type_traits<T, Args...>::T_reference;

    auto push(T& element){
        return static_cast<parallel_container*>(this)->push(element);
    }
    auto pop(){
        return static_cast<parallel_container*>(this)->pop();
    }
    auto try_pop(T_ref element){
        return static_cast<parallel_container*>(this)->try_pop(element);
    }
    bool is_empty(){
        return static_cast<parallel_container*>(this)->is_empty();
    }
    parallel_container& asDerived(){
        return *static_cast<parallel_container*>(this);
    }
};

template <typename T, template<typename>class container>//
class Base<T,container>
{
public:
    using parallel_container = container<T>;
    using T_point = typename type_traits<T>::T_pointer;
    using T_ref = typename type_traits<T>::T_reference;

    auto push(T& element){
        qDebug() << "parallel_set pushing" << endl;
        return static_cast<parallel_container*>(this)->push(element);
    }
    auto pop(){
        return static_cast<parallel_container*>(this)->pop();
    }
    auto try_pop(T_ref element){
        return static_cast<parallel_container*>(this)->try_pop(element);
    }
    bool is_empty(){
        return static_cast<parallel_container*>(this)->is_empty();
    }
    parallel_container& asDerived(){
        return *static_cast<parallel_container*>(this);
    }
};




#endif // PARALLEL_CONTAINER_HPP



















