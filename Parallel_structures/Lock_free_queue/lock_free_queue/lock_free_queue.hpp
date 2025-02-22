#ifndef LOCK_FREE_QUEUE_H
#define LOCK_FREE_QUEUE_H
#include"../../parallel_container/parallel_container.hpp"
#include<memory>


template<typename T>
class lock_free_queue //: public Parallel_container<T, lock_free_queue>
{

public:
    struct node;
    struct node_counter{
        node_counter(){
            internal_count = 0;
            external_counters = 0;
        }
        node_counter(int inter):
            internal_count(0),
            external_counters(0){
            inter++;
        }//unsigned inter,unsigned exter
        unsigned internal_count : 30;
        unsigned external_counters : 2;
    };


    struct counted_node_ptr{

        counted_node_ptr():
            external_count(0),
            ptr(nullptr)
        {}
        counted_node_ptr(node*_ptr):
            external_count(0),
            ptr(_ptr)
        {}
        counted_node_ptr(int Count):
            external_count(Count),
            ptr(nullptr)
        {}

        int external_count;
        node *ptr;
    };

struct node{
    std::atomic<T*> data;
    std::atomic<node_counter> count;
    std::atomic<counted_node_ptr> next;

    node():
        data(nullptr),
        count(0),
        next(nullptr){
                node_counter new_count;
                new_count.internal_count=0;
                new_count.external_counters=2;
                count.store(new_count);
 /*
                next.load().ptr=nullptr;
                next.load().external_count=0;
*/
            }
    void release_ref(){
        qDebug() << "release_ref"<< endl;
        node_counter old_counter=count.load(std::memory_order_relaxed);
        node_counter new_counter;
        do{
            new_counter=old_counter;
            --new_counter.internal_count;
        }while(!count.compare_exchange_strong(old_counter,new_counter,std::memory_order_acquire,
                                              std::memory_order_relaxed));
        if(!new_counter.internal_count&&!new_counter.external_counters){
            delete this;
        }
    }
    };
    std::atomic<counted_node_ptr> head;
    std::atomic<counted_node_ptr> tail;

public:

    lock_free_queue():head(new node),tail(head.load()){
    //head.load().ptr->next = tail.load();
        //counted_node_ptr N={0};
        //head.store(N);
        //tail.store(head.load());
    }
    //lock_free_queue():head(nullptr),tail(head.load()){}
    lock_free_queue(const lock_free_queue &other)=delete;
    lock_free_queue& operator=(const lock_free_queue &other)=delete;

    ~lock_free_queue(){
        while(pop());
    }
    static void free_external_counter(counted_node_ptr &old_node_ptr){
    //qDebug() << "free_external_counter"<< endl;
        node* const ptr=old_node_ptr.ptr;
        int const count_increase=old_node_ptr.external_count-2;
        node_counter old_counter=ptr->count.load(std::memory_order_relaxed);
        node_counter new_counter;
        do{
            new_counter = old_counter;
            --new_counter.external_counters;
            new_counter.internal_count+=count_increase;
        }while(!ptr->count.compare_exchange_strong(old_counter,new_counter,std::memory_order_acquire,
                                                   std::memory_order_relaxed));
        if(!new_counter.internal_count&&
                !new_counter.external_counters){
            delete ptr;
        }
    }
    static void increase_external_count(std::atomic<counted_node_ptr>& counter,
                                        counted_node_ptr& old_counter){
                                        //qDebug() << "increase_external_count"<< endl;
        counted_node_ptr new_counter;
        do{
            new_counter=old_counter;
            ++new_counter.external_count;
            //qDebug() << "compare_exchange_strong"<< new_counter.external_count<<endl;
        }while(!counter.compare_exchange_strong(old_counter,new_counter,std::memory_order_acquire,
                                                std::memory_order_relaxed));
        old_counter.external_count=new_counter.external_count;
        //qDebug() << "out"<< endl;
    }
    void set_new_tail(counted_node_ptr &old_tail,
                      counted_node_ptr const &new_tail){
                      //qDebug() << "set_new_tail"<< endl;
        node* const current_tail_ptr=old_tail.ptr;
        while(!(tail.compare_exchange_weak(old_tail,new_tail)&&old_tail.ptr==current_tail_ptr));
        if(old_tail.ptr==current_tail_ptr)
            free_external_counter(old_tail);
        else{
            current_tail_ptr->release_ref();
        }

    }
    std::unique_ptr<T> pop(){
        counted_node_ptr old_head=head.load(std::memory_order_relaxed);
        for(;;){
            increase_external_count(head,old_head);
            node* const ptr=old_head.ptr;
            if(ptr==tail.load().ptr){
                //qDebug() << "here we are"<< endl;
                //ptr->release_ref();
                //qDebug() << "here we are not"<< endl;
                return std::unique_ptr<T>();
            }
            counted_node_ptr next = ptr->next.load();
            if(head.compare_exchange_strong(old_head,next)){

                T* const res=ptr->data.exchange(nullptr);
                free_external_counter(old_head);
                return std::unique_ptr<T>(res);
            }
            ptr->release_ref();
        }
    }

    bool push(T&& new_value){
       //qDebug() << sizeof (node_counter)<< endl;

       std::unique_ptr<T> new_data(std::make_unique<T>(std::move(new_value)));

       counted_node_ptr new_next;
       new_next.ptr=new node;
       //qDebug() << "s"<< endl;
       new_next.external_count=1;
       counted_node_ptr old_tail=tail.load();
       for(;;){
           increase_external_count(tail,old_tail);
           T* old_data(nullptr);
           //qDebug() << "here again"<< endl;
           if(old_tail.ptr->data.compare_exchange_strong(old_data,new_data.get())){
               counted_node_ptr old_next={0};
               if(!old_tail.ptr->next.compare_exchange_strong(old_next,new_next)){
                   delete new_next.ptr;
                   qDebug() << "case"<< endl;
                   new_next=old_next;
               }
               set_new_tail(old_tail,new_next);
               qDebug() << "pushed "<< endl;
               new_data.release();
               break;
           }else{
               //qDebug() << "pushed2 "<< endl;
               counted_node_ptr old_next={0};
               if(old_tail.ptr->next.compare_exchange_strong(old_next,new_next)){
                   old_next=new_next;
                   new_next.ptr=new node;
               }
               set_new_tail(old_tail,old_next);
           }
       }
       return true;
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
    bool is_empty(){
        return true;
    }
private:

};


#endif // LOCK_FREE_QUEUE_H
