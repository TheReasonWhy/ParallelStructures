#ifndef PARALLEL_STACK_H
#define PARALLEL_STACK_H
#include"../../parallel_container/parallel_container.hpp"
#include<memory>


//#include<stdatomic.h>

template<typename T>
class parallel_stack : public Parallel_container<T, parallel_stack>
{
public:
    using T_point = typename type_traits<T>::T_pointer;
    using T_ref = typename type_traits<T>::T_reference;
    using Push_type = T_point;
    struct stack_node;

    struct CNPS
    {
        int external_count;
        stack_node *m_ptr = nullptr;
    };

    struct stack_node
    {
        std::unique_ptr<T> data;
        std::atomic<int> internal_count;
        CNPS next;
        stack_node(T const& data_):
            data(std::make_unique<T>(data_)),
            internal_count(0){
        }
        stack_node(T &&data_):
            data(std::make_unique<T>(std::move(data_))),
            internal_count(0){
        }
    };

    std::atomic<CNPS> m_head;

void increase_head_count(CNPS& old_counter){
    CNPS new_counter;
    do{
        new_counter=old_counter;
        ++new_counter.external_count;
    }while(!m_head.compare_exchange_strong(old_counter,new_counter,
                                           std::memory_order_acquire,std::memory_order_relaxed));
    old_counter.external_count=new_counter.external_count;

}


    parallel_stack()
    {
    }
    parallel_stack& operator = (parallel_stack* other)
    {
        m_head.store(other->m_head);
        return *this;
    }
    ~parallel_stack(){
        while(pop());
    }
    bool push(T&& element){
        CNPS new_node;
        new_node.m_ptr=new stack_node(std::move(element));
        new_node.external_count=1;
        new_node.m_ptr->next=m_head.load(std::memory_order_relaxed);
        while(!(m_head.compare_exchange_weak(new_node.m_ptr->next,new_node,
                                             std::memory_order_release,
                                             std::memory_order_relaxed))){};
        return true;

    }
    bool push(T const &element){
        CNPS new_node;
        new_node.m_ptr=new stack_node(element);
        new_node.external_count=1;
        new_node.m_ptr->next=m_head.load(std::memory_order_relaxed);
        while(!(m_head.compare_exchange_weak(new_node.m_ptr->next,new_node,
                                             std::memory_order_release,
                                             std::memory_order_relaxed))){};
        return true;

    }

    std::unique_ptr<T> pop(){
        CNPS old_head = m_head.load(std::memory_order_relaxed);
        for (;;) {
            increase_head_count(old_head);
            stack_node* const ptr = old_head.m_ptr;
            if(!ptr){
                return std::unique_ptr<T>();
            }
            if(m_head.compare_exchange_strong(old_head,ptr->next,
                                              std::memory_order_relaxed)){
                std::unique_ptr<T> res;
                res.swap(ptr->data);
                int const count_increase = old_head.external_count-2;
                if(ptr->internal_count.fetch_add(count_increase,
                                                 std::memory_order_release)==-count_increase){
                    delete ptr;
                }
                return res;
            }else if(ptr->internal_count.fetch_add(-1,
                                                   std::memory_order_relaxed)==1){
                ptr->internal_count.load(std::memory_order_acquire);
                delete ptr;
            }

        }
    }
    bool is_empty(){
        CNPS head = m_head.load();
        stack_node* const ptr = head.m_ptr;
        if(!ptr){
            return true;
        }
        return false;
    }

    bool try_pop(T &res){
        std::unique_ptr<T> result = pop();
        if(result){
            res=*result.get();//res=std::move(*result.get());
            return true;
        }else{
            return false;
        }
    }
};
#endif // PARALLEL_STACK_H
