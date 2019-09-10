#ifndef STATISTICS_MANAGER_HPP
#define STATISTICS_MANAGER_HPP
#include<map>
#include<vector>
#include<statistics_chunk.hpp>
#include<timer.h>
#include<memory>
#include<atomic>
#include<thread>
/*

класс собирает статистику времени выполнения по одному потоку, выполняющему один тип функций
под управлением объекта threadpool

*/

class Statistics_manager_local{

public:
Statistics_manager_local(unsigned thread_index_):
                    thread_index(thread_index_),
                    m_data(0.0),
                    m_timer(std::make_unique<Timer>()){}


    std::unique_ptr<Statictics_chunk_local> get_statistics(){
        std::unique_ptr<Statictics_chunk_local> result =
            std::make_unique<Statictics_chunk_local>(thread_index,get_average(),get_min(),get_max(),get_sum());
            return result;
    }

    void start_timer(){
        m_timer.get()->start();
    }
    void finish_timer(){
        m_timer.get()->finish();
        m_data = m_timer.get()->get_value();
        m_timer.get()->reset();
    }

private:
    double get_average(){
        return m_data;
    }
    double get_min(){
        return m_data;
    }
    double get_max(){
        return m_data;
    }
    double get_sum(){
        return m_data;
    }

private:
    const unsigned thread_index;
    double m_data;
    std::unique_ptr<Timer> m_timer;

};

#endif // STATISTICS_MANAGER_HPP
