#ifndef JOIN_THREADS_HPP
#define JOIN_THREADS_HPP

#include<vector>
#include<iostream>
#include<thread>

class join_threads{
    std::vector<std::thread>& threads;
public:
    explicit join_threads(std::vector<std::thread>& threads_):
        threads(threads_)
    {

    }
    ~join_threads(){
        for(unsigned long i=0;i<threads.size();++i){
            if(threads[i].joinable()){
                std::cout <<threads[i].get_id() << " joined"<<std::endl;
                threads[i].join();
            }
        }
    }
};

#endif // JOIN_THREADS_HPP
