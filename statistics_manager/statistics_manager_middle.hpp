#ifndef STATISTICS_MANAGER_MIDDLE_HPP
#define STATISTICS_MANAGER_MIDDLE_HPP
#include<statistics_manager_local.hpp>
/*

класс собирает статистику времени выполнения по нескольким потокам, выполняющим один тип функций
под управлением объекта threadpool

*/
struct Statictics_chunk_middle{
Statictics_chunk_middle(double average_, double min_, double max_, double sum_, double agregated_sum_):
        average_per_thread(average_),
        min_per_thread(min_),
        max_per_thread(max_),
        execution_time(sum_),
        agregated_execution_time(agregated_sum_)
        {}
    double average_per_thread;
    double min_per_thread;
    double max_per_thread;
    double execution_time;
    double agregated_execution_time;
};


class Statistics_manager_middle{

public:
inline static unsigned const Thread_num = std::thread::hardware_concurrency();
Statistics_manager_middle(unsigned measurable_id_):
                    measurable_id(measurable_id_),
                    m_counter(0),
                    m_timer_started(false){

                    m_local_maxes.resize(Thread_num);
                    m_local_mins.resize(Thread_num);
                    m_local_averages.resize(Thread_num);
                    m_local_sums.resize(Thread_num);
          for (size_t i = 0;i<Thread_num;++i) {
            std::shared_ptr<Statistics_manager_local> new_local =
                std::make_shared<Statistics_manager_local>(static_cast<unsigned>(i));
             m_local_managers.push_back(new_local);
          }
          m_local_managers.shrink_to_fit();
    }

    std::unique_ptr<Statictics_chunk_middle>get_statistics(){
        std::unique_ptr<Statictics_chunk_middle> result = std::make_unique<Statictics_chunk_middle>(
        get_average_per_thread(),
        get_min_per_thread(),
        get_max_per_thread(),
        m_timer.get_value(),
        get_agregated_execution_time());
        return result;
    }

    unsigned get_type_id(){
        return measurable_id;
    }

    void start_timer(unsigned thread_id){
        std::atomic_bool new_bool(true);
        bool old_bool(false);
        if(m_timer_started.compare_exchange_strong(old_bool,new_bool)){
            m_timer.reset();
            m_timer.start();
        }
        m_local_managers.at(thread_id).get()->start_timer();
    }

    bool finish_timer(unsigned thread_id){
        m_counter.fetch_add(1);
        Statictics_chunk_local SCL = *m_local_managers.at(thread_id).get()->get_statistics().get();
        m_local_maxes.at(thread_id)=SCL.max_per_task;
        m_local_mins.at(thread_id)=SCL.min_per_task;
        m_local_averages.at(thread_id)=SCL.average_per_task;
        m_local_sums.at(thread_id)=SCL.total_time;
        m_local_managers.at(thread_id).get()->finish_timer();
        if(m_counter.load()==(static_cast<int>(Thread_num))){
            m_timer.finish();
            m_counter.store(0);
            return true;
        }
        return false;
    }
private:
    double get_average_per_thread(){
        double result(0.0);
        for (size_t i=0;i<Thread_num;i++) {
            result+=m_local_sums.at(i);
        }
        return result/static_cast<double>(Thread_num);
    }
    double get_min_per_thread(){
        double result=m_local_maxes.at(0);
        for (size_t i=1;i<Thread_num;i++) {
            if(m_local_maxes.at(i)>result){
                result=m_local_maxes.at(i);
            }
        }
        return result;
    }
    double get_max_per_thread(){
        double result(0.0);
        for (size_t i=0;i<Thread_num;i++) {
            if(m_local_maxes.at(i)>result){
                result=m_local_maxes.at(i);
            }
        }
        return result;
    }
    double get_agregated_execution_time(){
        double result(0.0);
        for (size_t i=0;i<Thread_num;i++) {
            result+=m_local_sums.at(i);
        }
        return result;
    }
    unsigned get_thread_num()const{
        return Thread_num;
    }
    std::shared_ptr<Statistics_manager_local> get_local_manager(unsigned i){
        return m_local_managers.at(i);
    }

private:
    const unsigned measurable_id;
    std::atomic_int m_counter;
    std::atomic_bool m_timer_started;
    Timer m_timer;
    std::vector<double> m_local_maxes = {0};
    std::vector<double> m_local_mins = {0};
    std::vector<double> m_local_averages = {0};
    std::vector<double> m_local_sums = {0};
    std::vector<std::shared_ptr<Statistics_manager_local>> m_local_managers;

};
#endif // STATISTICS_MANAGER_MIDDLE_HPP
