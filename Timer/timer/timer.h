#ifndef TIMER_H
#define TIMER_H
#include<functional>
#include<chrono>

class Timer{
private:
public:
    Timer(){}
    ~Timer(){}

    void start(){
        m_start = std::chrono::steady_clock::now();
    }

    void finish(){
        m_end = std::chrono::steady_clock::now();
    }
    void reset(){
        m_start=m_end;
    }
    double get_value()const{
        std::chrono::duration<double> dur = m_end-m_start;
        return dur.count()*1000.0;
    }

private:

    std::chrono::steady_clock::time_point m_start;
    std::chrono::steady_clock::time_point m_end;
};

#endif // TIMER_H
