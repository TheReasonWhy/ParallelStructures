#ifndef FACTORY_ABSTRACT_H
#define FACTORY_ABSTRACT_H
#include"indexator.hpp"
#include<example.h>

template<typename Object,
         typename Object::Index_type MAX, typename... Args>
class Factory_abstract
{
public:
    using Index_type = typename Object::Index_type;
    using indexator = Indexator<Index_type, MAX>;

    Factory_abstract():m_indexator(new indexator){}
    ~Factory_abstract(){delete m_indexator;}
    std::unique_ptr<Object> create_object(Args... args);
    size_t indexator_capacity(){
        return indexator::INDEX_LIMIT;
    }
    Index_type indexator_height(){
        return indexator::LEVELS_NUM;
    }

    Index_type indexator_first_position(Index_type level){
        return indexator::first_position(level);
    }
    Index_type indexator_step_size(Index_type level){
        return indexator::step_size(level);
    }
    indexator *m_indexator;
};

template<typename Object,
         typename Object::Index_type MAX>
class Factory_abstract<Object,MAX>
{
public:
    using Index_type = typename Object::Index_type;
    using indexator = Indexator<Index_type, MAX>;

    Factory_abstract():m_indexator(new indexator){}
    ~Factory_abstract(){delete m_indexator;}
    std::unique_ptr<Object> create_object();
    size_t indexator_capacity(){
        return indexator::INDEX_LIMIT;
    }
    Index_type indexator_height(){
        return indexator::LEVELS_NUM;
    }
    Index_type indexator_first_position(Index_type A){
        return indexator::first_posiion(A);
    }
    Index_type indexator_step_size(Index_type level){
        return indexator::step_size(level);
    }
    indexator *m_indexator;
};



template<typename Object, typename Object::Index_type MAX, typename... Args>
std::unique_ptr<Object>
Factory_abstract<Object,MAX,Args...>::create_object(Args... args){
    using Type = typename Object::Index_type;
    Type index(0);
    std::unique_ptr<Object> obj;
    if(indexator::indexate(index)){
        obj = std::make_unique<Object>(index, args...);
    }
    return obj;
}

template<typename Object, typename Object::Index_type MAX>
std::unique_ptr<Object>
Factory_abstract<Object,MAX>::create_object(){
    using Type = typename Object::Index_type;
    Type index(0);
    std::unique_ptr<Object> obj;
    if(indexator::indexate(index)){
        obj = std::make_unique<Object>(index);
    }
    return obj;
}

#endif // FACTORY_ABSTRACT_H


