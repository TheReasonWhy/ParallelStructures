#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP
#include<vector>
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>

template<typename T>
class Merge_sort
{
    using Iter = typename std::vector<T>::iterator;
public:
    static void sort(std::vector<T> &vec){

        unsigned const size = vec.size();
        T arr[size];
        unsigned i=0;
        Iter iter = vec.begin();
        while (iter!=vec.end()) {
            arr[i]=*iter;
            iter++;
            i++;
        }
        sort(&arr[0],size);
        iter = vec.begin();
        i=0;
        while (iter!=vec.end()) {
            *iter=arr[i];
            iter++;
            i++;
        }
    }
    static void sort(T to_sort[], unsigned size) noexcept{
        if(size>1){
        unsigned const left_size = size/2;
        unsigned const right_size = size-left_size;
        sort(&to_sort[0], left_size);
        sort(&to_sort[left_size], right_size);
        std::size_t lidx = 0, ridx = left_size, idx = 0;
        std::unique_ptr<T[]> tmp_array(new T[size]);

        while (lidx < left_size || ridx < size)
        {
            if (to_sort[lidx] < to_sort[ridx])
            {
                tmp_array[idx++] = std::move(to_sort[lidx]);
                lidx++;
            }
            else
            {
                tmp_array[idx++] = std::move(to_sort[ridx]);
                ridx++;
            }

            if (lidx == left_size)
            {
                std::copy(std::make_move_iterator(&to_sort[ridx]),
                          std::make_move_iterator(&to_sort[size]),
                          &tmp_array[idx]);
                break;
            }
            if (ridx == size)
            {
                std::copy(std::make_move_iterator(&to_sort[lidx]),
                          std::make_move_iterator(&to_sort[left_size]),
                          &tmp_array[idx]);
                break;
            }
        }

        std::copy(std::make_move_iterator(&tmp_array[0]),
                  std::make_move_iterator(&tmp_array[size]),
                  to_sort);

        }
    }

public:
    Merge_sort();
};


#endif // MERGE_SORT_HPP

















