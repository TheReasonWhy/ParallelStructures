#ifndef THREAD_SYSTEM_HPP
#define THREAD_SYSTEM_HPP
#include<work.hpp>
#include<chrono>
#include<parallel_stack_packaged.hpp>
#include<future>
#include<user_system.hpp>

//template<size_t LEVELS_NUM, size_t ROUTABLES_NUM, size_t ELEMENTS_NUM>
template<size_t UP_NUM, size_t MIDDLE_NUM, size_t LOW_NUM, size_t MOVABLE_NUM>
class thread_system{
public:
    struct join_threads{
    std::vector<std::thread> &m_threads;
    explicit join_threads(std::vector<std::thread> &threads):m_threads(threads){}
    ~join_threads(){
        for(size_t i=0;i<m_threads.size();++i){
            if(m_threads.at(i).joinable()){
                m_threads.at(i).join();
                qDebug() << i  << "joined " << endl;
            }
        }
    }
    };

    using WORK_SYSTEM = Work_system<UP_NUM, MIDDLE_NUM, LOW_NUM, MOVABLE_NUM>;
    using USER_SYSTEM = user_system<WORK_SYSTEM>;
    using WORK = work<decltype(&WORK_SYSTEM::process),&WORK_SYSTEM::process,WORK_SYSTEM,unsigned>;
    using ResultType = decltype (std::declval<WORK>()());
    using Packaged_type = typename std::packaged_task<ResultType()>;
    using Future_type = typename std::future<ResultType>;
    using Stack_task = parallel_stack_packaged<Packaged_type>;
    using Stack_future = parallel_stack_packaged<Future_type>;

    std::vector<Stack_task> m_tasks;
    Stack_future m_futures;
    inline static unsigned THREAD_NUM = std::thread::hardware_concurrency();
    inline static thread_local unsigned THREAD_ID;
    inline static unsigned CONTROL_SUM = 0;
    std::vector<std::thread> m_threads;
    join_threads m_joiner;
    bool m_done;
    WORK_SYSTEM *m_work_sys;
    USER_SYSTEM *m_usr_sys;

    thread_system():
                m_joiner(join_threads(m_threads)),
                m_done(false),
                m_work_sys(new WORK_SYSTEM(THREAD_NUM,"levels.txt","elements.txt","connections.txt")),
                m_usr_sys(new USER_SYSTEM(m_work_sys)){
                qDebug()<< "thread_system() " << endl;
                m_threads.resize(THREAD_NUM);

           /*
        try {
            for(size_t i=0;i<THREAD_NUM;++i){
                qDebug() << i  << "THREAD " << endl;
                m_threads.at(i)=std::move(std::thread(&thread_system::worker_thread,this, i));
                Stack_task st;
                m_tasks.push_back(st);
            }
        } catch (...) {
            throw;
        }
        */

    }

    ~thread_system(){
        m_done=true;
    }
    unsigned get_sum_recursive(unsigned lvl,unsigned routable, unsigned element){
        return WORK_SYSTEM::get_sum_recursive(lvl,routable,element);
    }
    void worker_thread(unsigned i){
        THREAD_ID = i;
        Packaged_type res;
        while (!m_done) {
            if(m_tasks.at(i).try_pop(res)){
                qDebug() << i  << "popped " << endl;
                res();
            }else {
                std::this_thread::yield();
            }
        }
    }
    void add_element_action(unsigned absolute_id){
        m_usr_sys->add_element_action(absolute_id);
    }
    void process(){
        while (!m_done) {
            Future_type res;
            while(m_usr_sys->process()){}
            for (unsigned i =0;i<THREAD_NUM;++i) {
                WORK w(m_work_sys,i,i);
                Packaged_type task(std::move(w));
                std::future<ResultType> res(task.get_future());
                m_tasks.at(i).push(std::move(task));
                m_futures.push(std::move(res));
            }
            for (unsigned i =0;i<THREAD_NUM;++i) {
                while(!m_futures.try_pop(res)){
                }
                qDebug() << "popped() "<< i << endl;
                CONTROL_SUM+=res.get();
                qDebug() << "CONTROL_SUM "<< CONTROL_SUM << endl;
            }
            stop();
        }
    }
    unsigned get_control_sum(){
        return CONTROL_SUM;
    }

    void stop(){
        m_done=true;
    }
    private:

};
#endif // THREAD_SYSTEM_HPP

















