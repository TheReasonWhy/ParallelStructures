#ifndef FACTORY_ABSTRACT_H
#define FACTORY_ABSTRACT_H
#include<random_param_generator.hpp>

template<typename Object>
class Factory_abstract
{
public:
    using Param_type = typename Object::Param_type;
    Factory_abstract(){}
    ~Factory_abstract(){}
    static std::unique_ptr<Object> create_object(Param_type param);

};


template<typename Object>
std::unique_ptr<Object>
Factory_abstract<Object>::create_object(typename Object::Param_type param){
    std::unique_ptr<Object> obj= std::make_unique<Object>(param);
    return obj;
}


#endif // FACTORY_ABSTRACT_H



