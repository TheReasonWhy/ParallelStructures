#ifndef THREADPOOL_BASE_HPP
#define THREADPOOL_BASE_HPP
#include<thread>
#include<vector>
#include<QDebug>
#include<future>
#include<chrono>

template<size_t NUM_THREADS, typename Work, template<typename> class Container, class Derived>
class threadpool_base{
private:
    inline static thread_local unsigned my_index = 0;
    inline static std::atomic_bool m_done = false;
    inline static std::array<std::thread, NUM_THREADS> m_threads = {};

protected:
    ~threadpool_base(){
        finish();
    }
    bool start(){
        //qDebug() << "start() " << endl;
        m_done.store(false);
        try {
            for(size_t i=0;i<NUM_THREADS;++i){
                m_threads.at(i)=std::move(std::thread(&threadpool_base::worker_thread,this, i));
            }
        } catch (...) {
            finish();
            throw;
        }
        return true;
    }
    void worker_thread(unsigned my_index_){
        my_index = my_index_; //локальная статическая переменная !!!
        qDebug() << "my_index " << my_index << endl;
        while(!m_done.load()==true){
            static_cast<Derived*>(this)->run_strategy(my_index);
        }
    }
    static bool finish(){
        m_done.store(true);
        for(size_t i=0;i<NUM_THREADS;++i){
            if(m_threads[i].joinable()){
                m_threads[i].join();
                qDebug() << i  << "joined " << endl;
            }
        }
        return true;
    }

};

#endif // THREADPOOL_BASE_HPP
