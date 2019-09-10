#ifndef STATISTICS_CHUNK_HPP
#define STATISTICS_CHUNK_HPP
#include<string>
#include <fstream>
#include <iostream>

struct Statictics_chunk_local{
Statictics_chunk_local(unsigned thread_index_, double average_, double min_, double max_, double sum_):
        thread_index(thread_index_),
        average_per_task(average_),
        min_per_task(min_),
        max_per_task(max_),
        total_time(sum_){}
    unsigned thread_index;
    double average_per_task;
    double min_per_task;
    double max_per_task;
    double total_time;
};





#endif // STATISTICS_CHUNK_HPP


















