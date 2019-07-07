#include <atomic>
#include<memory>
#include<iostream>

template<typename T>
class parallel_stack
{
    struct stack_node;

    struct CNPS
    {
        int external_count;
        stack_node *m_ptr;
    };

    struct stack_node
    {
        std::shared_ptr<T> data;
        std::atomic<int> internal_count;
        CNPS next;
        stack_node(T const& data_):
            data(std::make_shared<T>(data_)),
            internal_count(0){
            std::cout << "stack_node constructor ()" << std::endl;
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

public:
    parallel_stack()
    {
    }
    ~parallel_stack(){
        std::cout << " parallel_stack destroying" << std::endl;
        while(pop());
        std::cout << " parallel_stack destroyed" << std::endl;
    }
    void push(T const& element){
        CNPS new_node;
        new_node.m_ptr=new stack_node(element);
        new_node.external_count=1;
        new_node.m_ptr->next=m_head.load(std::memory_order_relaxed);
        while(!(m_head.compare_exchange_weak(new_node.m_ptr->next,new_node,
                                             std::memory_order_release,
                                             std::memory_order_relaxed)));
    }

    std::shared_ptr<T> pop(){
        CNPS old_head = m_head.load(std::memory_order_relaxed);
        for (;;) {
            increase_head_count(old_head);
            stack_node* const ptr = old_head.m_ptr;
            if(!ptr){
                return std::shared_ptr<T>();
            }
            if(m_head.compare_exchange_strong(old_head,ptr->next,
                                              std::memory_order_relaxed)){
                std::shared_ptr<T> res;
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
};

int main(int argc, char *argv[])
{
    parallel_stack<int> PS;
    PS.push(7);
    PS.push(5);
    PS.push(6);
    std::cout<<*PS.pop().get()<<std::endl;
    std::cout<<*PS.pop().get()<<std::endl;
    std::cout<<*PS.pop().get()<<std::endl;
    return  1;
}
