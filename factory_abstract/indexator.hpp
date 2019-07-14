#ifndef INDEXATOR_HPP
#define INDEXATOR_HPP
#include <heap_sort.hpp>
#include <algorithm>

//template< typename T, T MAX, class Enable = void>class Indexator;

template< typename T, T MAX>
class Indexator
{
public:

    static constexpr T power(T val,T P) {
        T Val = val;
        while(P>1){
            --P;
            Val*=val;
        }
        return Val;
    }
    static constexpr T log(T base, size_t val){
        size_t Val = val;
        T Pow(1);
        if(Val<=base){
            return Pow;
        }
        while(Val>base){
            Val/=base;
            ++Pow;
        }
        return Pow;
    }
    static constexpr size_t index_limit(){
        size_t val = MAX;
        size_t P = log(2,val);
        size_t result = static_cast<size_t>(power(2, P));
        return result;
    }
    inline static const size_t INDEX_LIMIT = index_limit();



    static constexpr T levels_number(){
        if(INDEX_LIMIT==0){
            return 0;
        }else{
            return log(2,INDEX_LIMIT);
        }
    }
    inline static const T LEVELS_NUM = levels_number();

    static constexpr T first_posiion(T level){
        if(level == 0){
            return static_cast<T>(INDEX_LIMIT/2);
        }else if(level == LEVELS_NUM-1){
            return static_cast<T>(1);
        }else if(level == LEVELS_NUM){
            return static_cast<T>(0);
            }
        else{
            return static_cast<T>(INDEX_LIMIT/(level*2)/2);
        }
    }
    static constexpr T step_size(T level){
        if(level == 0){
            return static_cast<T>(0);
        }else if(level == LEVELS_NUM-1){
            return static_cast<T>(2);
        }else if(level == LEVELS_NUM){
            return static_cast<T>(0);//это ошибочный запрос
        }else{
            return static_cast<T>(INDEX_LIMIT/(level*2));
        }
    }
    static constexpr T step_number(T level){
        return INDEX_LIMIT/(step_size(level));
    }

    void generate_indices_heapifyed(){
        heap_sort<T,MAX,std::array>(INDEX_STORE);
    }

    static bool indexate(T &index){
        if(!(CURRENT_INDEX>INDEX_LIMIT-1)){
            index = INDEX_STORE[CURRENT_INDEX];
            ++CURRENT_INDEX;
            return true;
        }else{
            return false;//достигнут максимальный размер
        }
    }

private:
    static constexpr std::array<T, INDEX_LIMIT> fill_array() {
        std::array<T, INDEX_LIMIT> v{0};
        for(T i = 0; i < INDEX_LIMIT; ++i)
            {
                v[i] = i;
            }
        return v;
    }
    inline static T CURRENT_INDEX = 0;
    static constexpr std::array<T, INDEX_LIMIT> fill_array_as_binary_tree(){
        std::array<T, INDEX_LIMIT> result{0};
        size_t iterator(0);
        T value = static_cast<T>(INDEX_LIMIT);
        T level(0);
        T step_sz;
        T step_num;
        T start_pos;
        while(level < LEVELS_NUM){
            start_pos = first_posiion(level);
            step_sz = step_size(level);
            step_num = step_number(level);
            value = start_pos;

            while(step_num!=0 && iterator!=INDEX_LIMIT-1){
                --step_num;
                value+=step_sz;
                result[iterator]=value;
                ++iterator;
            }
            ++level;
        }
        return result;
    }
    inline static std::array<T, INDEX_LIMIT> INDEX_STORE=fill_array();

    public:
    Indexator(){
    T param = static_cast<T>(4);
    T answer = first_posiion(param);
    qDebug()<< answer << endl;
        //fill_array_as_binary_tree();
    }
};





#endif // INDEXATOR_HPP
