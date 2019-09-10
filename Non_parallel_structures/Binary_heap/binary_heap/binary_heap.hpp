#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H
#include <iterator>
#include <vector>
#include <memory>
#include<stack>

template<typename T,
         size_t MAXSIZE,
         typename Enable = void>class binary_heap;

template<typename T,
         size_t MAXSIZE>//template<typename, size_t...>class INPUT_CONTAINER
class binary_heap<T, MAXSIZE, typename std::enable_if_t<std::is_arithmetic_v<T>>>
{//вектор или массив
    using Array = std::array<T, MAXSIZE>;
    using Vector = std::vector<T>;
public:
    binary_heap():
        m_size(0){
    }
    binary_heap(std::unique_ptr<Array> numbers_to_sort):
        m_elements(std::move(numbers_to_sort)),
        m_size(0)
    {
        size_t i = (heap_size()/2);
        while(i!=0){
            heapify(i);
            --i;
        }
        heapify(i);
    }
    binary_heap(Array *numbers_to_sort):
        m_size(0)
    {
        for(size_t i = 0;i<MAXSIZE;++i){
            add_element(numbers_to_sort->at(i));
        }
    }
    binary_heap(Array &numbers_to_sort):
        m_size(0)
    {
        for(size_t i = 0;i<MAXSIZE;++i){
            add_element(numbers_to_sort.at(i));
        }
    }
    binary_heap(Vector &numbers_to_sort):
        m_size(0)
    {
        for(size_t i = 0;i<MAXSIZE;++i){
            add_element(numbers_to_sort.at(i));
        }
    }

    ~binary_heap(){}

    T pop_max(){
        T result = m_elements.at(0);
        m_elements.at(0)=(m_elements.at(m_size-1));
        --m_size;
        heapify(0);
        return result;
    }

    size_t heap_size(){
        return m_size;
    }
    bool add_element(T value){
        if(m_size == MAXSIZE){return false;}
        m_elements.at(m_size)=value;
        ++m_size;
        size_t i = m_size-1;
        size_t parent = (i-1)/2;
        size_t tmp(0);
        while(i>0 && (m_elements.at(parent) < m_elements.at(i))){
            tmp = m_elements.at(parent);
            m_elements.at(parent)=m_elements.at(i);
            m_elements.at(i)=tmp;
            i=parent;
            parent = (i-1)/2;
        }
        return true;
    }
    void heapify(size_t i){
        size_t left_child;
        size_t right_child;
        size_t largest_child;
        for(;;){
            left_child=2*i+1;
            right_child=2*i+2;
            largest_child=i;
            if((left_child<heap_size()) && (m_elements.at(left_child)>m_elements.at(largest_child))){
                largest_child = left_child;
            }
            if((right_child<heap_size()) && (m_elements.at(right_child)>m_elements.at(largest_child))){
                largest_child = right_child;
            }
            if(largest_child==i){
                break;
            }
            T temp = m_elements.at(i);
            m_elements.at(i)=m_elements.at(largest_child);
            m_elements.at(largest_child)=temp;
            i=largest_child;
        }
    }

    Array m_elements;
    size_t m_size;
    private:
};

template<typename T, size_t _SIZE>
std::unique_ptr<std::array<T,_SIZE>> get_array(){
    std::unique_ptr<std::array<T,_SIZE>> res=std::make_unique<std::array<T,_SIZE>>();
    binary_heap BH(res);
    return res;
}

#endif // BINARY_HEAP_H
