#ifndef STAGE_PROCESSOR_HPP
#define STAGE_PROCESSOR_HPP
#include<parallel_binary_tree.hpp>
#include<threadpool_base.hpp>
#include<parallel_stack.hpp>
#include<stack>
#include<work_generator.hpp>



//#include<array>

template<size_t NUM_THREADS,
    size_t MAX_NUM_WORKS,
    typename Memfunc,
    Memfunc memfunc,
    typename Callee,
    template<typename>class Container_For_Works,
    template<typename>class Container_Future,
    template<typename>class Container_for_Set>
class stage_processor //: public threadpool_base<NUM_THREADS, Work,Container,threadpool_binary_tree<NUM_THREADS, Work,Container>>
{
    using Generator = work_generator<Memfunc,memfunc,Callee,MAX_NUM_WORKS,Container_For_Works>;
    using Work = work_static_element<Memfunc,memfunc,Callee>;
    using ResultType = decltype (std::declval<Work>()());
    using Packaged_type = std::packaged_task<ResultType()>;
    using Future_type = std::future<ResultType>;

    using Binary_tree = parallel_binary_tree<Work>;
    using Task_Container = std::stack<Packaged_type>;
    using Future_Container = Container_Future<Future_type>;

    inline static thread_local size_t thread_local_index = 0;
    public:

    bool get_local_thread_index(){
    size_t old_counter, new_counter;
    do{
        old_counter = thread_counter.load();
        new_counter = old_counter+1;
        thread_local_index = old_counter;
    }while(!thread_counter.compare_exchange_strong(old_counter,new_counter));
        m_future_container_indices.push(thread_local_index);
        return true;
    }

    void run(){
        get_local_thread_index();
        Packaged_type task;
        while(m_tasks.at(thread_local_index).try_pop(task)){
            task();
        }
        get_futures();
        --thread_counter;//символически выходим из цикла процессора
        m_future_container_indices.pop();
    }

    void get_futures(){
        size_t index(0);
        while(m_future_container_indices.try_pop(index)){
            while(m_futures.at(index).pop().get()){}
        }
    }

    void submit(Work&& callee,unsigned index,unsigned thread_index){
        if(m_tree){
            if(m_tree->push(index)){
                Packaged_type task(std::move(callee));
                Future_type result(task.get_future());
                m_tasks.at(thread_index)->push_back(std::move(task));
                m_futures.at(thread_index)->push_back(std::move(result));
            }
        }
    }
    private:
    std::atomic_size_t thread_counter;
    inline static thread_local unsigned my_index = 0;
    inline static std::atomic_bool m_done = false;
    static Generator m_generator;
    Binary_tree m_tree;
    std::array<Task_Container,NUM_THREADS> m_tasks;
    std::array<Future_Container,NUM_THREADS> m_futures;
    parallel_stack<size_t> m_future_container_indices;


};
#endif // STAGE_PROCESSOR_HPP
