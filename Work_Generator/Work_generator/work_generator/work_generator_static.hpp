#ifndef WORK_GENERATOR_STATIC_HPP
#define WORK_GENERATOR_STATIC_HPP
#include"work.hpp"
#include<array>


template<size_t SIZE,
        typename Memfunc,
        Memfunc memfunc,
        typename Callee>
class work_generator_static{
public:
    using Work = work<Memfunc,memfunc,Callee>;
    work_generator_static(std::array<Callee,SIZE> &callees){
        for (size_t i = 0;i<callees.size();++i) {
            std::shared_ptr<Callee> C = std::make_shared<Callee>(callees.at(i));
            Work w(C.get(),static_cast<unsigned>(i));
            WORK_POOL.at(i)=std::move(w);
        }
    }
    ~work_generator_static(){}

    Work generate_work(unsigned index){
        return WORK_POOL.at(index);
    }
    std::unique_ptr<Work> create_work(unsigned index){
        std::unique_ptr<Work> result;
        if(index < WORK_POOL.size()){
            Work W = WORK_POOL.at(index);//копирование
            result = std::make_unique<Work>(W);
        }
        return result;
    }
private:
    std::array<Work,SIZE> WORK_POOL;
};


template<typename Memfunc,
    Memfunc memfunc,
    typename Callee,
    typename... Params>
class work_generator_dynamic{
public:
    using Work = work<Memfunc, memfunc, Callee, Params...>;
    work_generator_dynamic(){

    }
    ~work_generator_dynamic(){}

    static Work generate_work(Callee *callee, unsigned index, Params... params){
        Work result(callee,index,params...);
        return result;
    }

};







#endif // WORK_GENERATOR_STATIC_HPP
