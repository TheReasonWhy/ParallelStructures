#ifndef THREADPOOL_BINARY_TREE_HPP
#define THREADPOOL_BINARY_TREE_HPP
#include <threadpool_base.hpp>
#include <parallel_binary_tree.hpp>

template<size_t NUM_THREADS, typename Work, template<typename>class Container>
class threadpool_binary_tree : public threadpool_base<NUM_THREADS, Work,Container,threadpool_binary_tree<NUM_THREADS, Work,Container>>
{
    using Base = threadpool_base<NUM_THREADS, Work,Container,threadpool_binary_tree<NUM_THREADS,Work,Container>>;
    using ResultType = decltype (std::declval<Work>()());
    using Packaged_type = std::packaged_task<ResultType()>;
    using Binary_tree = parallel_binary_tree<Work>;
    using Queue = Container<Packaged_type>;
    static_assert (std::is_same_v<ResultType,std::invoke_result_t<Work> >,"sad but not true");

    bool pop_task_from_queue(Packaged_type &task){
        if(m_queue){
            return m_queue->try_pop(task);
        }else{
            return false;
        }
    }
public:

    threadpool_binary_tree():
        m_tree(new Binary_tree()),
        m_queue(new Queue()){}
    ~threadpool_binary_tree(){
        if(m_tree){delete m_tree;}
        if(m_queue){delete m_queue;}
    }
    void run_pending_task(){
        Packaged_type task;
        if(pop_task_from_queue(task)){
            task();
        }else{
            std::this_thread::yield();
        }
    }
    void run_strategy(unsigned thread_id){
        qDebug()<<thread_id<<endl;
        run_pending_task();
    }
    bool start(){
        return threadpool_binary_tree::Base::start();
    }
    bool finish(){
        return threadpool_binary_tree::Base::finish();
    }

    std::future<ResultType> submit(Work&& callee,unsigned index){
        Packaged_type task(std::move(callee));
        std::future<ResultType> res(task.get_future());
        bool answer(false);
        if(m_tree->push(index)){
            if(m_queue){
                answer = m_queue->push(std::move(task));
            }
        }
        if(answer){
            return res;
        }else{
            return std::future<ResultType>();//пустая фьюча
        }
    }
    /*
        try_submit(unsigned i);
        try_pop(unsigned i);
        try_get(unsigned i);
        generate_containers();
        generate_strategies();

    */

private:
    std::vector<Work> m_works;
    std::vector<std::future<ResultType>> m_futures;

    Binary_tree *m_tree;
    Queue *m_queue;
};
#endif // THREADPOOL_BINARY_TREE_HPP
