#ifndef THREADPOOL_CLIENT_HPP
#define THREADPOOL_CLIENT_HPP


#include<work_generator.hpp>
#include<threadpool_binary_tree.hpp>
#include<timer.h>

template<typename Memfunc,
    Memfunc memfunc,
    typename Callee,
    typename Callee::Index_type MAX,
    template<typename>class Container_Work,
    template<typename>class Container_Future,
    template<typename>class Container_for_Set,
    size_t THREAD_NUM = 4>
class Threadpool_client
{
public:

    using Work_generator = work_generator<Memfunc,memfunc,Callee,MAX,Container_Work>;
    using Work = typename Work_generator::Work;
    using ResultType =  decltype (std::declval<Work>()());
    using Future = typename std::future<ResultType>;
    using Threadpool = threadpool_binary_tree<THREAD_NUM,Work,Container_for_Set>;//<Work,Container_For_Set>
    using CW = Container_Work<Work>;
    using CF = Container_Future<Future>;

    inline static unsigned control_sum = 0;
    inline static unsigned accumulated_sum = 0;
    CW *w_container;
    CF *f_container;
    Work_generator *WG;
    Threadpool *TP;
    Timer m_timer;

    Threadpool_client():w_container(new CW),f_container(new CF),WG(new Work_generator),TP(new Threadpool){}
    ~Threadpool_client(){
        while(!submit_everything());
        if(w_container){delete  w_container;}
        if(f_container){delete  f_container;}
        if(WG){delete  WG;}
        if(TP){delete  TP;}
    }
    bool create_random_test_works(size_t num){
        w_container = WG->create_random_works(num);
        return true;
    }
    bool create_test_works(size_t num){
        w_container = WG->create_works(0,num);
        return true;
    }
    bool submit_everything(){
        m_timer.start();
        unsigned index(0);
        while(!w_container->is_empty())
        {
            Work W = *w_container->pop().get();
            //unsigned index = W.get()->index();
            control_sum+=index;
            qDebug()<<"... index_thrown ..."<< index <<endl;
            std::future<ResultType> res = TP->submit(std::move(W),index);
            if(res.valid()){
                f_container->push(std::move(res));
                index++;
            }else{
                qDebug()<<"... res_invalid ..."<< index <<endl;
            }

        };
        TP->start();
        index=0;
        while(!f_container->is_empty())
        {
            index=f_container->pop().get()->get();
            qDebug()<<"... index_catched ..."<< index <<endl;
            accumulated_sum+=index;
        };
        m_timer.finish();
        qDebug()<<"... timer_result ..."<< m_timer.get_value() <<endl;
        return TP->finish();
    }

    static bool reset_control_sum(){
        control_sum = 0;
        accumulated_sum = 0;
        return true;
    }

    static unsigned get_control_sum(){
        return control_sum;
    }
    static unsigned get_accumulated_sum(){
        return accumulated_sum;
    }


};
#endif // THREADPOOL_CLIENT_HPP
