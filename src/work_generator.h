#ifndef WORK_GENERATOR_H
#define WORK_GENERATOR_H
#include"work.hpp"
#include<vector>
#include<memory>
#include"threadpool.h"


template<typename Memfunc, Memfunc memfunc, typename Callee, template<typename>class Container = parallel_stack>
class work_generator
{
public:
    using Work = work<Memfunc,memfunc,Callee>;
    using ResultType = typename Work::ResultType;
    using Future = std::future<ResultType>;
    using Threadpool = threadpool<Work,Container>;

    work_generator():m_container(new parallel_stack<Work>){}
    ~work_generator(){if(m_container){delete m_container;}}
    Work *create_work(){
        unsigned param = rand()%100;
        sum_accum+=param;
        Callee *callee = new Callee(param);
        Work* result = new Work(std::move(callee));
        return result;
    }
    bool create_test_works(int test_number){
        qDebug() << "Creating test works " << test_number<< endl;
        Work _w;
        for (int i=0;i<test_number;++i) {
            _w = *create_work();
            m_container->push(std::move(_w));
            //qDebug() << "m_container->size() == " << m_container->size()<< endl;
        }
        return true;
    }
    bool perform_test_works(){
        while (!m_container->is_empty()) {
            qDebug() << "Popped " << m_container->pop().get()->call();
        }
        return true;
    }
    static unsigned sum_accumulated(){
        return sum_accum;
    }
    //template<typename Callee, template<typename>class Container>

    bool submit_everything(){
        Threadpool TP;
        parallel_stack<Future> f_container;
        while(!m_container->is_empty())
        {
            std::unique_ptr<Work> W = m_container->pop();
            unsigned index = W.get()->index();
            Future res = TP.submit(std::move(*(W.get())),index);
            f_container.push(std::move(res));
        };

        while(!f_container.is_empty())
        {
            f_container.pop().get()->get();
        };
        return TP.finish();
    }
/**/
    inline static unsigned sum_accum = 0;
    inline static unsigned work_indexator = 0;
    parallel_stack<Work> *m_container;

};
/**/
#endif // WORK_GENERATOR_H
