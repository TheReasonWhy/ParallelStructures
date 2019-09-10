#ifndef INSERT_SORT_HPP
#define INSERT_SORT_HPP
#include<vector>

template<typename T>
class Insert_sort
{
public:
Insert_sort();
    static void sort(std::vector<T>& to_sort){
        unsigned Size = to_sort.size();
        for(unsigned i = 1; i<Size; ++i){
            for(unsigned j = i; (j!=0)&&to_sort.at(j-1)>to_sort.at(j); --j){
                swap(to_sort.at(j-1),to_sort.at(j));
            }
        }
    }
private:
    static void swap(T &left, T &right){
        T tmp = right;
        right = left;
        left = tmp;
    }
};
#endif // INSERT_SORT_HPP
