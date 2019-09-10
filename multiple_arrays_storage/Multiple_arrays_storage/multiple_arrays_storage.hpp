#ifndef MULTIPLE_ARRAYS_STORAGE_HPP
#define MULTIPLE_ARRAYS_STORAGE_HPP

#include<array>
#include<iostream>

 //using S_T = long long unsigned int;

template<typename... Types>
class multiple_arrays_storage;
// Рекурсивный случай:
template<typename Head, size_t Size, typename... Tail>
class multiple_arrays_storage<std::array<Head,Size>, Tail...>
{
    private :
    std::array<Head,Size> head;
    multiple_arrays_storage<Tail ...> tail;
    public:
    // Конструкторы:
    multiple_arrays_storage (){}
    /**/
    multiple_arrays_storage(std::array<Head,Size> const& _head, multiple_arrays_storage<Tail ...> const& tail)
    : head(_head),tail(tail){}
    multiple_arrays_storage(std::array<Head,Size> const& _head, Tail const& ... tail)
    : head(_head),tail(tail...){}

    Head& getHead(){return head;}
    unsigned getVal(unsigned W){return head.at(W);}
    Head const& getHead() const{return head;}
    multiple_arrays_storage<Tail...>& getTail(){return tail;}
    multiple_arrays_storage<Tail...> const& getTail()const{return tail;}
};

// Базовый случай:
template<>
class multiple_arrays_storage<>
{
// Хранилище не требуется
};

// Рекурсивный случай:
template<unsigned N>
struct tuple_complex_get
{
    template<typename Head, typename... Tail>
    static auto apply_array(multiple_arrays_storage<Head, Tail...> const& t)
    {
        return tuple_complex_get<N-1>::apply_array(t.getTail());
    }

    template<typename Head, typename... Tail>
    static auto apply_array_value(multiple_arrays_storage<Head, Tail...> t,unsigned index)
    {
        return tuple_complex_get<N-1>::apply_array_value(t.getTail(),index);
    }
};
// Базовый случай:
template<>
struct tuple_complex_get<0>
{
    template<typename Head, typename... Tail>
    static Head const& apply_array(multiple_arrays_storage<Head, Tail...> const& t)
    {
        return t.getHead();
    }

    template<typename Head, typename... Tail>
    static auto apply_array_value(multiple_arrays_storage<Head, Tail...> t,unsigned index)
    {
        return t.getVal(index);
    }
};

template<unsigned N, typename... Types>
auto get_array_reference(multiple_arrays_storage<Types ...> const& t)
{
    return tuple_complex_get<N>::apply_array(t) ;
}

template<unsigned N, typename... Types>
auto get_value_by_index(multiple_arrays_storage<Types ...>& t,unsigned index)
{
    return tuple_complex_get<N>::apply_array_value(t,index) ;
}


#endif // MULTIPLE_ARRAYS_STORAGE_HPP
