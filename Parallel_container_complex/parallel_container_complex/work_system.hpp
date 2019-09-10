#ifndef WORK_SYSTEM_HPP
#define WORK_SYSTEM_HPP
#include<parallel_binary_tree.hpp>
#include<parallel_stack_packaged.hpp>
#include<parallel_stack.hpp>
#include<work_call_element.hpp>
#include<work_call_routable.hpp>
#include<work_move_element.hpp>
#include<statistics_manager_global.hpp>

template<size_t LEVELS_NUM,
        size_t ROUTABLES_NUM,
        size_t ELEMENTS_NUM>
class Work_system : public Level_system<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM,Work_system>

{

public:

    using LEVEL_SYSTEM = Level_system<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM,Work_system>;
    using Middle_wrapper = typename LEVEL_SYSTEM::Middle_wrapper;
    using Low_wrapper = typename LEVEL_SYSTEM::Low_wrapper;

    using Work_E = work_call_element<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM,LEVEL_SYSTEM>;
    using ResultType_E = decltype (std::declval<Work_E>()());
    using Tree_E = parallel_binary_tree<Work_E>;
    using Stack_E = parallel_stack<Work_E>;

    using Work_R = work_call_routable<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM,LEVEL_SYSTEM>;
    using ResultType_R = decltype (std::declval<Work_R>()());
    using Tree_R = parallel_binary_tree<Work_R>;
    using Stack_R = parallel_stack<Work_R>;

    using Work_M = work_move_element<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM,LEVEL_SYSTEM>;
    using ResultType_M = decltype (std::declval<Work_M>()());
    using Tree_M = parallel_binary_tree<Work_M>;    
    using Stack_M = parallel_stack<Work_M>;

    inline static thread_local unsigned THREAD_ID = 0;
    inline static unsigned THREAD_NUM=std::thread::hardware_concurrency();
    inline static Statistics_manager_global<LEVELS_NUM> m_statistics;

struct stage{
private:

    Tree_E m_element_tree;
    Tree_R m_routable_tree;
    Tree_M m_move_tree;

    Stack_E m_element_works;
    Stack_R m_routable_works;
    Stack_M m_move_works;
    std::atomic_uint IN;
    std::atomic_bool open;
    unsigned LVL_ID;
public:
    stage():
        IN(0),
        open(false){
    }
    void try_push_element(unsigned element_id_absolute)
    {
        if(m_element_tree.push(element_id_absolute)){
            Work_E w(element_id_absolute);
            m_element_works.push(std::move(w));
        }
    }

    void try_push_routable(unsigned routable_id_absolute)
    {
        if(m_routable_tree.push(routable_id_absolute)){
            Work_R w(routable_id_absolute);
            m_routable_works.push(std::move(w));
        }
    }

    void try_push_move(unsigned element_id_absolute,unsigned target_id_absolute)
    {
        if(m_move_tree.push(element_id_absolute)){
            Work_M w(element_id_absolute,target_id_absolute);
            m_move_works.push(std::move(w));
        }
    }

    void process_moves(){
        while(!m_move_works.is_empty()){
            Work_M res;
            if(m_move_works.try_pop(res)){
                res();
            }
        }
    }
    unsigned process_elements(){
        unsigned control_sum(0);
        while(!m_element_works.is_empty()){            
            Work_E res;
            if(m_element_works.try_pop(res)){                
                control_sum+=res();
                qDebug()<<"PROCESS_ELEMENTS!!!!!! "<<control_sum<<endl;
            }
        }
        return control_sum;
    }
    unsigned process_routables(){
        unsigned control_sum(0);
        while(!m_routable_works.is_empty()){
            Work_R res;
            if(m_routable_works.try_pop(res)){
                control_sum+=res();
            }
        }
        return control_sum;
    }

    unsigned process(){
        unsigned control_sum(0);
        m_statistics.start(THREAD_ID, LVL_ID);
        IN.fetch_add(1);
        while(!(open.load()==true)){
            if(IN.load()==THREAD_NUM){
                open.store(true);
            }
        }
        process_moves();
        control_sum += process_elements();
        control_sum += process_routables();

        m_statistics.finish(THREAD_ID, LVL_ID);
        IN.fetch_sub(1);
        while(!(open.load()==true)){
            if(IN.load()==0){
                open.store(false);
            }
        }
        return control_sum;
    }
    void set_lvl(unsigned lvl){
        LVL_ID = lvl;
    }
};

inline static std::array<stage,LEVELS_NUM> m_stages;

    static unsigned get_sum_recursive(unsigned lvl, unsigned routable, unsigned element){
        return LEVEL_SYSTEM::get_sum_recursive(lvl,routable,element);
    }
    Work_system(unsigned const thread_num,
                std::string const lvl_filename,
                std::string const element_filename,
                std::string const connections_filename):
        LEVEL_SYSTEM(lvl_filename,element_filename,connections_filename)
    {
        THREAD_NUM = thread_num;
        for (size_t lvl=0;lvl<LEVELS_NUM;++lvl) {
            m_stages.at(lvl).set_lvl(lvl);
        }
    }
    ~Work_system(){
    }

    static void try_push_element(unsigned lvl, unsigned element_id_absolute)
    {
        m_stages.at(static_cast<size_t>(lvl)).try_push_element(element_id_absolute);
    }

    static void try_push_routable(unsigned lvl, unsigned routable_id_absolute)
    {
        m_stages.at(static_cast<size_t>(lvl)).try_push_routable(routable_id_absolute);
    }

    static void try_push_move(unsigned lvl, unsigned element_id_absolute, unsigned target_id_absolute)
    {
        m_stages.at(static_cast<size_t>(lvl)).try_push_move(element_id_absolute,target_id_absolute);
    }
    unsigned process(unsigned thread_id){
        THREAD_ID=thread_id;
        unsigned control_sum(0);
        unsigned lvl=0;
        while (!(lvl==LEVELS_NUM)) {
            control_sum+=m_stages.at(lvl).process();
            lvl++;
        }
        return control_sum;
    }

};

#endif // WORK_SYSTEM_HPP


















