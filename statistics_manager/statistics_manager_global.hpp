#ifndef STATISTICS_MANAGER_GLOBAL_HPP
#define STATISTICS_MANAGER_GLOBAL_HPP
#include<statistics_manager_middle.hpp>

class Staticstics_chunk_final
{
Staticstics_chunk_final(
    double min_time_,size_t thread_num_min_time_,std::string type_name_min_time_,
    double max_time_,size_t thread_num_max_time_, std::string type_name_max_time_
    ):
    min_time(min_time_),
    thread_num_min_time(thread_num_min_time_),
    type_name_min_time(type_name_min_time_),
    max_time(max_time_),
    thread_num_max_time(thread_num_max_time_),
    type_name_max_time(type_name_max_time_)
{}
    double min_time;size_t thread_num_min_time; std::string type_name_min_time;
    double max_time;size_t thread_num_max_time; std::string type_name_max_time;

    void output(std::ofstream &file){
        file<<min_time<<" - min_time" <<thread_num_min_time<<" - thread_num" <<type_name_min_time<<" - type"
        <<max_time<<" - min_time" <<thread_num_max_time<<" - thread_num" <<type_name_max_time<<" - type";
    }
};

template<size_t Level_num>
class Statistics_manager_global{
public:
using middle_manager = Statistics_manager_middle;
inline static unsigned const Thread_num = std::thread::hardware_concurrency();
    Statistics_manager_global():file("my_statistics.txt"){
        for (size_t  i = 0;i<Level_num;++i) {
             m_middle_managers.at(i)=std::make_shared<middle_manager>(static_cast<unsigned>(i));
        }
    }

    void start(unsigned thread_id, unsigned lvl){
        m_middle_managers.at(lvl).get()->start_timer(thread_id);
    }

    void finish(unsigned thread_id, size_t lvl){
        if(m_middle_managers.at(lvl).get()->finish_timer(thread_id)){
            Statictics_chunk_middle SCM = *m_middle_managers.at(lvl).get()->get_statistics().get();
            m_middle_maxes.at(lvl)=SCM.max_per_thread;
            m_middle_mins.at(lvl)=SCM.min_per_thread;
            m_middle_averages.at(lvl)=SCM.average_per_thread;
            m_middle_sums.at(lvl)=SCM.execution_time;
            m_middle_aggregated_sums.at(lvl)=SCM.agregated_execution_time;
            output_middle_statistics(lvl);
            if(lvl==Level_num-1){
                output_global_statistics();
            }
        }
    }

    void output_middle_statistics(size_t middle_index){
        file<< middle_index <<" - level_index" << std::endl
        <<m_middle_maxes.at(middle_index)<<" - max_time" << std::endl
        <<m_middle_mins.at(middle_index)<<" - min_time"  << std::endl
        <<m_middle_averages.at(middle_index)<<" - average_time" << std::endl
        <<m_middle_sums.at(middle_index)<<" - execution_time"  << std::endl
        <<m_middle_aggregated_sums.at(middle_index) <<" - aggregated_num" << std::endl;
    }
    void output_global_statistics(){
        double Middle_Max=m_middle_maxes.at(0);
        size_t Middle_Max_level(0);
        double Middle_Min=m_middle_mins.at(0);
        size_t Middle_Min_level(0);
        double Average = m_middle_averages.at(0);
        double Execution_time = m_middle_sums.at(0);
        double Aggregated_time=m_middle_aggregated_sums.at(0);
        for(size_t i=1;i<Level_num;++i){
            if(m_middle_maxes.at(i)>Middle_Max){
                Middle_Max=m_middle_maxes.at(i);
                Middle_Max_level=i;
            }
            if(m_middle_mins.at(i)<Middle_Min){
                Middle_Min=m_middle_mins.at(i);
                Middle_Min_level=i;
            }
            Average+=m_middle_averages.at(i);
            Execution_time+=m_middle_sums.at(i);
            Aggregated_time+=m_middle_aggregated_sums.at(i);
        }
        Average/=Level_num;
        file<< " - TOTAL - " << std::endl
        <<Middle_Max<<" - max_time at thread" << Middle_Max_level << std::endl
        <<Middle_Min<<" - min_time at thread" << Middle_Min_level << std::endl
        <<Average<<" - average_time" << std::endl
        <<Execution_time<<" - execution_time"  << std::endl
        <<Aggregated_time <<" - aggregated_num" << std::endl;
    }

private:
    std::array<double,Level_num> m_middle_maxes = {0};
    std::array<double,Level_num> m_middle_mins = {0};
    std::array<double,Level_num> m_middle_averages = {0};
    std::array<double,Level_num> m_middle_sums = {0};
    std::array<double,Level_num> m_middle_aggregated_sums = {0};
    std::array<std::shared_ptr<middle_manager>, Level_num> m_middle_managers;

    std::ofstream file;
};
#endif // STATISTICS_MANAGER_GLOBAL_HPP

















