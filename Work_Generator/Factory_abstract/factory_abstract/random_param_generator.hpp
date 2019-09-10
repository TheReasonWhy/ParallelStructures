#ifndef RANDOM_PARAM_GENERATOR_HPP
#define RANDOM_PARAM_GENERATOR_HPP
#include<memory>
#include<stack>
#include<unordered_set>
#include<algorithm>

template<typename T>
T generate(T from, T to){
    if(to<=from){return from;}
    return from+(static_cast<T>(static_cast<T>(rand())%(to-from)));
}

template<typename T>
std::stack<T> generate_shuffled_repeat(T from, T to, T number){
    std::unordered_set<T> uset;
    std::stack<T> result;
    if(to<=from){return result;}
    size_t Number(static_cast<size_t>(number));
    if(number<(to-from)){
        Number = static_cast<size_t>(to-from);
    }
    while (result.size()!=Number) {
        result.push(generate(from,to));
    }
    return result;
}

template<typename T>
std::stack<T> generate_shuffled_non_repeat(T from, T to, T number){
    std::unordered_set<T> uset;
    std::stack<T> result;
    if(to<=from){return result;}
    size_t Number(static_cast<size_t>(number));
    if(number<(to-from)){
        Number = static_cast<size_t>(to-from);
    }
    while (result.size()!=Number) {
        T candidate = generate(from,to);
        if(!std::find(result.begin(), result.end(), candidate)){
            result.push(candidate);
        }
    }
    return result;
}

template<typename Object>
class random_param_generator
{
public:
    Object generate(Object from, Object to){
        if(to<=from){return from;}
        return from+(static_cast<Object>(static_cast<Object>(rand())%(to-from)));
    }
    using Border_type = typename Object::Border_type;

    Border_type generate(Border_type from, Border_type to){
        if(to<=from){return from;}
        return from+(static_cast<Border_type>(static_cast<Border_type>(rand())%(to-from)));
    }

    using Param_type = typename Object::Param_type;
    using Index_type = typename Object::Index_type;
    using Enlisted_type = typename Object::Param_enlisted_type;
    random_param_generator(){}
    ~random_param_generator(){}
    static std::unique_ptr<Object> create_object(Param_type param);
    static std::unique_ptr<Object> create_object_random(Border_type from, Border_type to);
    static std::unique_ptr<Object> create_object_complex_random(Border_type from, Border_type to, size_t Param_number);
    static std::unique_ptr<Object> create_object_complex_indexed_random(Index_type index, Border_type from, Border_type to, size_t Param_number);
    static std::stack<Object> generate_shuffled_random_indexed_non_repeat
    (Border_type from, Border_type to, Border_type param_from, Border_type param_to, size_t Obj_num, size_t References_max_num){
        std::unordered_set<Index_type> uset;
        std::stack<Object> result;
        std::stack<Enlisted_type> params;
        std::unordered_set<Index_type> puset;
        size_t Objects_num(Obj_num);
        if((to-from)<0){Objects_num=0;}
        if((to-from)<Objects_num){Objects_num=(to-from);}
        while (uset.size()<Objects_num) {
            uset.insert(from+(static_cast<Border_type>(static_cast<Border_type>(rand())%(to-from))));//индексы объектов
        }
        for(typename std::unordered_set<Index_type>::iterator it = uset.begin();it!=uset.end();++it){
            size_t Param_num = static_cast<Border_type>(static_cast<Border_type>(rand())%(References_max_num));
            while (puset.size()<Param_num){
                puset.insert(param_from+(static_cast<Border_type>(static_cast<Border_type>(rand())%(param_to-param_from))));//индексы параметров
            }
            for(typename std::unordered_set<Index_type>::iterator it = puset.begin();it!=puset.end();++it){
                Index_type T = *it;
                params.push(T);
                puset.erase(it);
            }
            Index_type index = *it;
            std::unique_ptr<Object> Obj = std::make_unique<Object>(index);
            uset.erase(it);
            while (!params.empty()) {
                Obj.get().add_param(params.top());
                params.pop();
            }
            result.push(*Obj.get());
        }
        return result;
    }
};

#endif // RANDOM_PARAM_GENERATOR_HPP
