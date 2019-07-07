#ifndef PARALLEL_QUEUE_H
#define PARALLEL_QUEUE_H

#include"node.hpp"
#include"parallel_container.hpp"


/*
параллельная очередь с ___одним производителем и одним потребителем____
*/
template<typename T>
class parallel_queue : public Base<T, parallel_queue>
{
public:
    struct node
    {
        node():m_value(),counter(1),m_next(nullptr){qDebug() << "CNP constructor1 ()" << endl;}
        ~node(){qDebug() << "parallel_queue node destroyed" << endl;}

        void release_ref(){
            int old_counter;
            do{
                old_counter = counter.load(std::memory_order_relaxed);
            }
            while (!counter.compare_exchange_strong(old_counter,old_counter-1));
            qDebug() << " release_ref()" << counter.load() << endl;
            if(counter.load()==0){
                qDebug() << " queue_delete_this()" << endl;
                delete this;
            }
        }
        void increase_counter(){
            int old_counter;
            int new_counter;
            do{
                old_counter = counter.load(std::memory_order_relaxed);
                new_counter = old_counter+1;
            }
            while (!counter.compare_exchange_strong(old_counter,new_counter));
            qDebug() << " increase_counter()" << endl;
        }
        std::unique_ptr<T> m_value;
        std::atomic<int> counter;
        node *m_next;
    };

    parallel_queue():
        m_head(new node),
        m_tail(m_head.load())
    {
        qDebug() << " parallel_queue constructed" << endl;
    }
    ~parallel_queue(){
        qDebug() << " parallel_queue destructor_called" << endl;
        while(pop());
        /*
        while(node const* old_head = m_head.load()){
            m_head.store(old_head->m_next);
            delete old_head;
        }
*/

        qDebug() << "queue empty now" << endl;
    }

    void push(T&& element){
        std::unique_ptr<T> new_data(std::make_unique<T>(std::move(element)));
        node* p = new node;
        node* const old_tail=m_tail.load();
        old_tail->m_value.swap(new_data);
        old_tail->m_next=p;
        m_tail.store(p);
        old_tail->increase_counter();
        qDebug() << "pushed into queue"<< endl;
    }

    std::unique_ptr<T> pop(){
        qDebug() << "try_pop" << endl;
        node* old_head = pop_front();
        if(!old_head){
            qDebug() << "nothing_to_pop" << endl;
            return std::unique_ptr<T>();
        }
        std::unique_ptr<T> res(std::move(old_head->m_value));
        old_head->release_ref();
        return res;
    }

    node* pop_front(){
        node* const old_head = m_head.load();
        if(old_head==m_tail.load()){
            return nullptr;
        }
        m_head.store(old_head->m_next);
        m_head.load()->release_ref();
        return old_head;
    }

    bool is_empty(){
        return (m_head==m_tail);
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
private:
    std::atomic<node*> m_head;
    std::atomic<node*> m_tail;
};

#endif // PARALLEL_QUEUE_H
