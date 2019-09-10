#ifndef LOCK_FREE_QUEUE_UNIQUE_LOCK_HPP
#define LOCK_FREE_QUEUE_UNIQUE_LOCK_HPP
#include"../../parallel_container/parallel_container.hpp"
#include<memory>
#include <mutex>

template<typename T>
class lock_free_queue_unique_lock{
public:
    lock_free_queue_unique_lock():m_params(new std::vector<T>())
    {}
    ~lock_free_queue_unique_lock(){
        while(pop());
        if(m_params){delete m_params;}
    }

    bool push(T&& value){
        std::unique_lock<std::mutex> lc(m_mutex);
        m_params->push_back(std::move(value));
        return true;
    }
    std::unique_ptr<T> pop(){
        std::unique_lock<std::mutex> lc(m_mutex);
        if(!m_params->empty()){            
            std::unique_ptr<T> res(std::make_unique<T>(std::move(m_params->back())));
            m_params->pop_back();
            return res;
        }
        return std::unique_ptr<T>();

    }
    bool try_pop(T &res){
        std::unique_ptr<T> result = pop();
        if(result){
            res=std::move(*result.get());
            return true;
        }else{
            return false;
        }
    }
    bool is_empty(){
        return m_params->empty();
    }
private:
    std::mutex m_mutex;
    std::vector<T> *m_params;

};


#endif // LOCK_FREE_QUEUE_UNIQUE_LOCK_HPP
