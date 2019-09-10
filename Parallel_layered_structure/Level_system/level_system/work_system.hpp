#ifndef WORK_SYSTEM_HPP
#define WORK_SYSTEM_HPP
#include<level_system.hpp>
#include<work.hpp>
#include<parallel_binary_tree.hpp>
#include<parallel_stack_packaged.hpp>
#include<parallel_stack.hpp>
#include<statistics_manager_global.hpp>


template<size_t LEVELS_NUM,
        size_t ROUTABLES_NUM,
        size_t ELEMENTS_NUM,
        size_t MOVABLE_SIZE>
class Work_system : public Level_system<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM,MOVABLE_SIZE,Work_system>

{

public:

    using LEVEL_SYSTEM = Level_system<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM,MOVABLE_SIZE,Work_system>;
    using INTERVAL_SYSTEM = typename LEVEL_SYSTEM::INTERVAL_SYSTEM;
    using Middle_wrapper = typename LEVEL_SYSTEM::Middle_wrapper;
    using Low_wrapper = typename LEVEL_SYSTEM::Low_wrapper;

    using Work_E = work<decltype(&Low_wrapper::call),&Low_wrapper::call,Low_wrapper>;
    using ResultType_E = decltype (std::declval<Work_E>()());
    using Tree_E = parallel_binary_tree<Work_E>;
    using Stack_E = parallel_stack<Work_E>;

    using Work_R = work<decltype(&Middle_wrapper::call),&Middle_wrapper::call,Middle_wrapper>;
    using ResultType_R = decltype (std::declval<Work_R>()());
    using Tree_R = parallel_binary_tree<Work_R>;
    using Stack_R = parallel_stack<Work_R>;

    using Work_M = work<decltype(&LEVEL_SYSTEM::call_move),&LEVEL_SYSTEM::call_move,LEVEL_SYSTEM,size_t,size_t>;
    using ResultType_M = decltype (std::declval<Work_M>()());
    using Tree_M = parallel_binary_tree<Work_M>;
    using Stack_M = parallel_stack<Work_M>;

    inline static thread_local unsigned THREAD_ID = 0;
    inline static unsigned THREAD_NUM=1;//std::thread::hardware_concurrency();
    inline static Statistics_manager_global<LEVELS_NUM> m_statistics;

struct stage{
private:

    Tree_E m_low_tree;
    Tree_R m_middle_tree;
    Tree_M m_move_tree;

    Stack_E m_low_works;
    Stack_R m_middle_works;
    Stack_M m_move_works;
    std::atomic_uint IN;
    std::atomic_bool open;
    unsigned LVL_ID;
    LEVEL_SYSTEM *LS;
public:
    stage():
        IN(0),
        open(false){
    }
    void init(LEVEL_SYSTEM *LS_){
        LS=LS_;
    }
    void try_push_element(size_t low_id_absolute)
    {
        if(m_low_tree.push(low_id_absolute)){
            Work_E w(LS->get_low_wrapper(low_id_absolute),0);
            m_low_works.push(std::move(w));
        }
    }

    void try_push_middle(size_t middle_id_absolute)
    {
        if(m_middle_tree.push(middle_id_absolute)){
            Work_R w(LS->get_middle_wrapper(middle_id_absolute),0);
            m_middle_works.push(std::move(w));
        }
    }

    void try_push_move(size_t movable_id, size_t target_id_absolute)
    {
        if(m_move_tree.push(movable_id)){
            Work_M w(LS,0,movable_id,target_id_absolute);
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
        m_move_tree.clear();
    }
    unsigned process_lows(){
        unsigned control_sum(0);
        while(!m_low_works.is_empty()){
            Work_E res;
            if(m_low_works.try_pop(res)){
                control_sum+=res();
            }
        }
        qDebug()<<" process_lows "<<" control_sum "<<control_sum<<endl;
        return control_sum;
    }
    unsigned process_middles(){
        unsigned control_sum(0);
        while(!m_middle_works.is_empty()){
            Work_R res;
            if(m_middle_works.try_pop(res)){
            qDebug()<<" MIDDLE_WORK_POPPED "<< LVL_ID<<endl;
                control_sum+=res();
            }
        }
        qDebug()<<" process_middles "<<" control_sum "<<control_sum<<endl;
        return control_sum;
    }
    void clear_trees(){
        qDebug()<<" clear_trees() lvl"<< LVL_ID<<endl;
        m_move_tree.clear();
        m_low_tree.clear();
        m_middle_tree.clear();
    }

    unsigned process(){
    qDebug()<<" process STAGE "<< LVL_ID<<endl;
        unsigned control_sum(0);
        m_statistics.start(THREAD_ID, LVL_ID);
        IN.fetch_add(1);
        while(!(open.load()==true)){

            if(IN.load()==THREAD_NUM){
                open.store(true);
            }
        }
        process_moves();
        control_sum += process_lows();
        control_sum += process_middles();

        m_statistics.finish(THREAD_ID, LVL_ID);
        IN.fetch_sub(1);
        while(!(open.load()==true)){
            if(IN.load()==0){
                open.store(false);                
            }
        }
        clear_trees();
        return control_sum;
    }
    void set_lvl(unsigned lvl){
        LVL_ID = lvl;
    }


};

inline static std::array<stage,LEVELS_NUM> m_stages;

    unsigned get_sum_recursive(unsigned lvl, unsigned routable, unsigned element){
        return static_cast<LEVEL_SYSTEM*>(this)->get_sum_recursive(lvl,routable,element);
    }
    Work_system(unsigned const thread_num,
                std::string const intervals_file_,
                std::string const data_file_,
                std::string const connections_file_):
        LEVEL_SYSTEM(intervals_file_,data_file_,connections_file_)
    {
        THREAD_NUM = thread_num;
        for (size_t lvl=0;lvl<LEVELS_NUM;++lvl) {
            m_stages.at(lvl).init(static_cast<LEVEL_SYSTEM*>(this));
            m_stages.at(lvl).set_lvl(lvl);
        }
    }
    ~Work_system(){
    }

    static void try_push_element(size_t lvl, size_t low_id_absolute)
    {
    qDebug()<<" try_push_element "<<" lvl "<<lvl<<" low_id_absolute "<<low_id_absolute<<endl;
        m_stages.at(lvl).try_push_element(low_id_absolute);
    }

    static void try_push_middle(size_t lvl, size_t middle_id_absolute)
    {
    qDebug()<<" try_push_middle "<<" lvl "<<lvl<<" middle_id_absolute "<<middle_id_absolute<<endl;
        m_stages.at(lvl).try_push_middle(middle_id_absolute);
    }

    static void try_push_move(size_t lvl, size_t movable_id, size_t target_id_absolute)
    {
        m_stages.at(lvl).try_push_move(movable_id,target_id_absolute);
    }
    unsigned process(unsigned thread_id){
        THREAD_ID=thread_id;
        unsigned control_sum(0);
        unsigned lvl=0;
        while (!(lvl==LEVELS_NUM)) {
        qDebug()<<" control_sum "<<control_sum<<endl;
            control_sum+=m_stages.at(lvl).process();
            lvl++;
        }
        return control_sum;
    }
    INTERVAL_SYSTEM *get_interval_system(){
        return static_cast<LEVEL_SYSTEM*>(this)->get_interval_system();
    }
};

#endif // WORK_SYSTEM_HPP

