#ifndef PARALLEL_CONTAINER_H
#define PARALLEL_CONTAINER_H

#include<type_traits>
#include<utility>
#include <typeinfo>
#include<QDebug>
#include<atomic>

template <typename T,typename ... Args>
class type_traits
{
    public:
    using T_cleared = std::remove_pointer_t<std::remove_reference_t<T>>;
    using T_pointer = T_cleared*;
    using T_reference = T_cleared&;
};

template <typename T,template<typename,typename ... Args>class container,typename ... Args>// T parallel_set parallel_queue Args
class Parallel_container
{
public:
    using Container = container<T, Args...>;
    using T_point = typename type_traits<T, Args...>::T_pointer;
    using T_ref = typename type_traits<T, Args...>::T_reference;

    auto push(T& element){
        qDebug() << "push(T&& element)"<< endl;
        return static_cast<Container*>(this)->push(element);
    }
    auto push(T&& element){
        qDebug() << "push(T&& element)"<< endl;
        return static_cast<Container*>(this)->push(std::forward(element));
    }
    auto pop(){
        return static_cast<Container*>(this)->pop();
    }
    auto try_pop(T& element){
        return static_cast<Container*>(this)->try_pop(std::forward(element));
    }
    auto try_pop(T&& element){
        qDebug() << "try_pop(T&& element)"<< endl;
        return static_cast<Container*>(this)->try_pop(std::forward(element));
    }
    bool is_empty(){
        return static_cast<Container*>(this)->is_empty();
    }
    Container& asDerived(){
        return *static_cast<Container*>(this);
    }
};

template <typename T, template<typename>class container>//
class Parallel_container<T,container>
{
public:
    using Container = container<T>;
    using T_point = typename type_traits<T>::T_pointer;
    using T_ref = typename type_traits<T>::T_reference;

    auto push(T& element){
        return static_cast<Container*>(this)->push(element);
    }
    auto push(T&& element){
        qDebug() << "push(T&& element)"<< endl;
        return static_cast<Container*>(this)->push(std::forward(element));
    }
    auto pop(){
        return static_cast<Container*>(this)->pop();
    }
    auto try_pop(T& element){
        return static_cast<Container*>(this)->try_pop(std::forward(element));
    }
    auto try_pop(T&& element){
        qDebug() << "try_pop(T&& element)"<< endl;
        return static_cast<Container*>(this)->try_pop(std::forward(element));
    }
    bool is_empty(){
        return static_cast<Container*>(this)->is_empty();
    }
    Container& asDerived(){
        return *static_cast<Container*>(this);
    }
};


#endif // PARALLEL_CONTAINER_H
