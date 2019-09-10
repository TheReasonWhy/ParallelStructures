#ifndef WORK_GENERATOR_H
#define WORK_GENERATOR_H
#include"factory_abstract.hpp"
#include"work.hpp"
#include"indexator.hpp"


template<typename Memfunc,
    Memfunc memfunc,
    typename Callee,
    size_t MAX,
    template<typename>class Container>//template<typename>class Container = parallel_stack
class work_generator
{
public:
    using Work = work<Memfunc,memfunc,Callee>;
    using Factory = Factory_abstract<Callee>;
    using Container_type = Container<Work>;
    using Parameter_Pack_Type = typename Callee::Param_type;
    using Index_type = unsigned;
    using indexator = Indexator<Index_type, MAX>;


    work_generator(){}
    ~work_generator(){
        //for(unsigned i=0;i<WORK_POOL.size();i++){
        //    qDebug()<<WORK_POOL.at(i).call()<<endl;
        //}
    }
    std::unique_ptr<Work> create_work(size_t index){
        std::unique_ptr<Work> result;
        if(index<MAX){
            Work W = WORK_POOL.at(index);//копирование
            result = std::make_unique<Work>(W);
        }
        return result;
    }

    //работы в результирующем контейнере могут повторяться
    Container_type *create_random_works(size_t number){
        Container_type *m_container = new Container_type;
        size_t R;
        for (size_t i=0;i<number;++i) {
            R = static_cast<size_t>(static_cast<size_t>(rand())%MAX);
            std::unique_ptr<Work> W=create_work(R);
            if(W){
                m_container->push(std::move(*W.get()));
            }
        }
        return m_container;
    }

    Container_type *create_works(size_t from, size_t to){
        size_t To(to);
        if(To>MAX){To=MAX;}
        Container_type *m_container = new Container_type;
        for (size_t i=from;i<To;++i) {
            std::unique_ptr<Work> W=create_work(i);
            if(W){
                m_container->push(std::move(*W.get()));
            }
        }
        return m_container;
    }

    static constexpr std::array<Parameter_Pack_Type,MAX> generate_random_params(){
       std::array<Parameter_Pack_Type,MAX> result;
       for (size_t i=0;i<MAX;++i) {
            Parameter_Pack_Type PPT(i);
            result.at(i)=PPT;
            }
       return  result;
    }
    static constexpr std::array<Callee,MAX> init_callees(){
        std::array<Callee,MAX> result;
        for (size_t i=0;i<MAX;++i) {
            result.at(i)=std::move(*(Factory::create_object(PARAMS.at(i)).get()));
        }
        return result;
    }
    static constexpr std::array<Work,MAX> init_pool(){
        std::array<Work,MAX> result;
        for (size_t i=0;i<MAX;++i) {//using Type = typename Object::Index_type;
            Index_type index(0);
            if(indexator::indexate(index)){
                Work W(CALLEES.at(i),index);
                result.at(i)=std::move(W);
            }
        }
        return result;
    }
    void commit_all_works(){
        for(size_t i=0;i<WORK_POOL.size();i++){
            qDebug()<<PARAMS.at(i).first<<"  "<<WORK_POOL.at(i).call()<<"  "<<WORK_POOL.at(i).index()<<endl;
        }
    }

    static size_t indexator_capacity(){
        return indexator::INDEX_LIMIT;
    }
    static size_t capacity_remain(){
        return indexator::INDEX_LIMIT - indexator::CURRENT_INDEX;
    }
    static Index_type indexator_height(){
        return indexator::LEVELS_NUM;
    }
    static Index_type indexator_first_position(Index_type level){
        return indexator::first_position(level);
    }
    static Index_type indexator_step_size(Index_type level){
        return indexator::step_size(level);
    }
private:
    inline static std::array<Parameter_Pack_Type,MAX> PARAMS=generate_random_params();  //временная заглушка. в будущем будет инициализироваться из файла.
    inline static std::array<Callee,MAX> CALLEES=init_callees();
    inline static std::array<Work,MAX> WORK_POOL=init_pool();

};

#endif // WORK_GENERATOR_H
