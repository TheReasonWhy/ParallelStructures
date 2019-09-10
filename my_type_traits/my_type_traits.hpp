#ifndef MY_TYPE_TRAITS_HPP
#define MY_TYPE_TRAITS_HPP
#include<string>

class threadpool_binary_heap;
class threadpool_parallel_set;


template<typename Type>struct My_type_traits;

template<>
struct My_type_traits<threadpool_binary_heap>
{
    inline static const std::string TYPE_NAME = "threadpool_binary_heap";
    inline static const unsigned MEASURABLE_ID = 0;
};


template<>
struct My_type_traits<threadpool_parallel_set>
{
    inline static const  std::string TYPE_NAME = "threadpool_parallel_set";
    inline static const unsigned MEASURABLE_ID = 1;
};
#endif // MY_TYPE_TRAITS_HPP
