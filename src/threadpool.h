#ifndef THREADPOOL_H
#define THREADPOOL_H
#include "parallel_set.hpp"
#include "lock_free_queue.hpp"
#include"join_threads.hpp"
#include <chrono>

template<typename Callee, template<typename>class Container>
class threadpool
{

    using ResultType = decltype (std::declval<Callee>()());
    using Set_type = std::packaged_task<ResultType()>;
    using Set = parallel_set_packaged<Callee, Container>;//parallel_set<victim, lock_free_queue>

    static_assert (std::is_same_v<ResultType,std::invoke_result_t<Callee> >,"sad but not true");

    inline static thread_local unsigned my_index = 0;

    void worker_thread(unsigned my_index_){
        my_index = my_index_; //локальная статическая переменная !!!
        qDebug() << "my_index " << my_index << endl;
        while(!done){
            run_pending_task();
        }
    }

    bool pop_task_from_set(Set_type &task){
        if(m_set){
            return m_set->try_pop(task);
        }else{
            qDebug() << "pop_task_from_set failed"<<endl;
            return false;
        }
    }
public:

    threadpool():
        done(false),
        m_set(new Set()),
        m_joiner(m_threads)
    {
        unsigned const thread_count = std::thread::hardware_concurrency();
        try {
            for(unsigned i=0;i<thread_count;++i){
                m_threads.push_back(std::thread(&threadpool::worker_thread,this, i));
            }
        } catch (...) {
            done = true;
            throw;
        }
    }
    ~threadpool(){if(m_set){delete m_set;}}
    void run_pending_task(){
        Set_type task;
        if(pop_task_from_set(task)){
            task();
        }else{
            std::this_thread::yield();
        }
    }

    bool finish(){
        std::chrono::seconds sec(2);
        std::this_thread::sleep_for(sec);
        done.store(true);
        return true;
    }
    std::future<ResultType> submit(Callee&& callee,unsigned index){
        Set_type task(std::move(callee));
        std::future<ResultType> res(task.get_future());
        if(m_set){
            m_set->push(std::move(task),index);
        }
        return res;
    }

private:
    std::atomic_bool done;
    Set *m_set;
    std::vector<std::thread> m_threads;
    join_threads m_joiner;
};


/*
template<typename T, template<typename>class set_container, template<typename>class queue_container>
class threadpool<T,set_container,queue_container,std::enable_if_t<is_callable<T>::value>>
{
public:
    using Set = set_container<T>;
    using Queue = queue_container<T>;
    using ResultType = decltype (std::declval<T>()());
    static_assert (std::is_same_v<ResultType,std::invoke_result_t<T> >,"sad but not true");

    threadpool(container *C):m_container(C){
    }
    ~threadpool(){if(m_container){delete m_container;}}
    void pop(){
        T result;
        if(m_container->pop(result)){
            std::cout << result() << "...result..." << std::endl;
        }
    }

    std::future<ResultType> submit(T callee){
        std::packaged_task<ResultType()> task(callee);
        std::future<ResultType> res(task.get_future());
        if(m_container){
            m_container->push(std::move(task));
        }
        return res;
    }
    container *m_container;

};






 *
template<typename Callee>class threadpool{
    using Type = Base_container<Callee>;
};

template<typename Callee>
class threadpool<Base_container<Callee*>>
{
public:
    class Parallel_container : public Base_container<Callee*>
    {
    public:
        using Base = Base_container<Callee*>;
        static auto pop(){
            return Base::pop();
        }
        static auto push(Callee callee){
            return Base::push(callee);
        }
    };
    threadpool() :
        m_container(new Parallel_container()){
    }
    ~threadpool(){
        delete m_container;
    }
    void pop(){
        std::cout <<" ...popping..." << m_container->pop()<< std::endl;
    }
    void push(Callee* callee){
        std::cout <<" ...pushing..." << m_container->push(callee)<< std::endl;

    }

    Parallel_container *m_container;
};





template<typename Callee, typename Parallel_container>
class threadpool
{
    using Container = typename Parallel_container<Callee>;


    void worker_thread(){
        std::cout << "thread "<<std::this_thread::get_id() << " created"<<std::endl;
        while(!m_done){
            function_wrapper task;
            if(m_queue.try_pop(task)){
                task();
            }else{
                std::this_thread::yield();
            }
        }
        std::cout<<"commit_profiler!!! "<< std::endl;
        commit_profiler();
        std::cout<<"OUT!!! "<< std::endl;
    }

    std::unique_ptr<timer>create_timer(){
        return std::make_unique<timer>();
    }

    void commit_profiler(){
        while(profiler::get_instance().write_portion_to_file()){;}
    }

private:
    std::atomic_bool m_done;

    work_queue m_queue;
    std::vector<std::thread> m_threads;
    join_threads m_joiner;

public:
    threadpool():
        m_done(false),
        m_queue(),
        m_joiner(m_threads)

    {


        const unsigned int thread_count=std::thread::hardware_concurrency();
        std::cout << "HARDWARE_CONCURRENCY "<< m_done.load() <<thread_count<<std::endl;
        unsigned int thread_count_test=1;
        try{
            for(unsigned i=0;i<thread_count_test;++i){
                m_threads.push_back(
                        std::thread(&threadpool::worker_thread,this));//
            }
        }
        catch(std::exception& e){
            m_done.store(true);
            std::cout << "ABOUT_TO_DESTROY" <<std::endl;
            throw;
        }
    }
    ~threadpool(){
        m_done.store(true);
        std::cout << "thread "<<std::this_thread::get_id() << " destroyed"<<std::endl;
    }
    template<typename FunctionType>
    std::future<typename std::result_of<FunctionType()>::type>
    submit(FunctionType f){
        typedef typename std::result_of<FunctionType()>::type result_type;
        std::packaged_task<result_type()> task(std::move(f));
        std::future<result_type> res(task.get_future());
        m_queue.push(std::move(task));
        return res;
        //worker<Return(binarytree<Param>::*)(Param)> Worker(&m_objec, &binarytree<Param>::find);
    }
};
*/
#endif // THREADPOOL_H
