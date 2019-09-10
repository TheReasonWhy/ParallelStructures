#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP
#include<vector>

template<typename T>
class Quick_sort
{
public:
    static void swap(T &left, T &right){
        T tmp = right;
        right = left;
        left = tmp;
    }
    static void sort(std::vector<T>& to_sort, unsigned From, unsigned To){

        T pivot = to_sort.at((From+To)/2);
        unsigned f = From;
        unsigned t =To;
        while (f<=t) {
            while (to_sort.at(f)<pivot) {
                f++;
            }
            while (to_sort.at(t)>pivot) {
                t--;
            }
            if(f<=t){
                swap(to_sort.at(f++),to_sort.at(t--));
            }
        }
        if(From<t){
            sort(to_sort,From,t);
        }
        if(To>f){
            sort(to_sort,f,To);
        }
    }
public:
    Quick_sort();
};

#endif // QUICK_SORT_HPP

















