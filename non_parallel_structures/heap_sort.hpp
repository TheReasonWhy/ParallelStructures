#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP
#include"binary_heap.hpp"

template<typename T,
         size_t _SIZE,
         template<typename, size_t>class INPUT_CONTAINER,
         template<typename, size_t>class OUTPUT_CONTAINER>
std::unique_ptr<OUTPUT_CONTAINER<T,_SIZE>> heap_sort(INPUT_CONTAINER<T,_SIZE> &ic){
    using OC = OUTPUT_CONTAINER<T,_SIZE>;

    binary_heap<T,_SIZE> BH(ic);
    std::unique_ptr<OC> res=std::make_unique<OC>();
    while(BH.heap_size()!=0){
        T tmp = BH.pop_max();
        res.get()->at(BH.heap_size()) = tmp;
    }
    return res;
}

template<typename T,
         size_t _SIZE,
         template<typename...>class INPUT_CONTAINER,
         template<typename, size_t>class OUTPUT_CONTAINER>
std::unique_ptr<OUTPUT_CONTAINER<T,_SIZE>> heap_sort(INPUT_CONTAINER<T> &ic){
    //using IC = INPUT_CONTAINER<T>;
    using OC = OUTPUT_CONTAINER<T,_SIZE>;

    binary_heap<T,_SIZE> BH(ic);
    std::unique_ptr<OC> res=std::make_unique<OC>();
    while(BH.heap_size()!=0){
        T tmp = BH.pop_max();
        res.get()->at(BH.heap_size()) = tmp;
    }
    return res;
}


//специализация для векторов
template<typename T,
         size_t _SIZE,
         template<typename...>class INPUT_OUTPUT_CONTAINER>
std::unique_ptr<INPUT_OUTPUT_CONTAINER<T>> heap_sort(INPUT_OUTPUT_CONTAINER<T> &ic){
    using OC = INPUT_OUTPUT_CONTAINER<T>;

    binary_heap<T,_SIZE> BH(ic);
    std::unique_ptr<OC> res=std::make_unique<OC>(_SIZE);
    while(BH.heap_size()!=0){
        T tmp = BH.pop_max();
        res.get()->at(BH.heap_size()) = tmp;
    }
    return res;
}
//специализация для массивов
template<typename T,
         size_t _SIZE,
         template<typename,size_t>class INPUT_OUTPUT_CONTAINER>
bool heap_sort(INPUT_OUTPUT_CONTAINER<T,_SIZE> &ic){
    binary_heap<T,_SIZE> BH(ic);
    T i(0);
    while(BH.heap_size()!=0){
        T tmp = BH.pop_max();
        ic.at(i) = tmp;
        ++i;
    }
    return true;
}
#endif // HEAP_SORT_HPP
