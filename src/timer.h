#ifndef TIMER_H
#define TIMER_H
#include<functional>
#include<memory>
#include<chrono>
#include <iostream>

//template<class T>


class timer {
public:
    timer(){

    }
    virtual ~timer(){

    }

    void start(){
        m_start = std::chrono::high_resolution_clock::now();
    }

    void end(){
        m_end = std::chrono::high_resolution_clock::now();
    }

    double get_value(){
        std::chrono::duration<double> dur = m_end-m_start;
        return dur.count()*10000.0;
    }


private:
    std::chrono::high_resolution_clock::time_point m_start;
    std::chrono::high_resolution_clock::time_point m_end;
};

#endif /* TIMER_H */
