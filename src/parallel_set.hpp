#ifndef PARALLEL_SET_H
#define PARALLEL_SET_H
#include"binary_tree.h"
#include"parallel_stack.hpp"
#include"parallel_queue.hpp"
#include"work.hpp"
#include<future>
//template<typename T, typename U, typename R = std::invoke_result_t<decltype(&T::U)(int)>>

/*
template<typename T,
         template<typename>class Container,// = parallel_stack<T>
         typename Index_Type = decltype (std::declval<T>().index()),
         typename ResultType = decltype (std::declval<Container>().pop()),
         typename Parallel_container = Base<T,Container>>
         std::enable_if_t
*/
template<typename Callee,template<typename>class Container>
class parallel_set
{
    //using Index_Type = decltype (std::declval<T>().index());
    using Binary_tree = binary_tree<Callee>;
    using ResultType = decltype (std::declval<Callee>()());
    using Parallel_container = Container<Callee>;
    //using ResultType = decltype (std::declval<Parallel_container>().pop());
    //static_assert (std::is_same_v<ResultType,std::shared_ptr<T>>,"Result type Wrong" );
    //static_assert (std::is_convertible_v<std::shared_ptr<T>,bool>, "Can't convert this type to bool" );
    //using Work = work<Memfunc, memfunc, Callee>;

public:

    parallel_set():
        m_tree(new Binary_tree),
        m_container(new Parallel_container)
    {
        qDebug() << "parallel_set constructed" << endl;
    }
    ~parallel_set(){
        if(m_tree){
            delete m_tree;
        }
        if(m_container){
            delete m_container;
        }
        qDebug() << "parallel_set destroyed" << endl;
    }
    void push(Callee&& element){
        qDebug() << "element.index()"<< element.index() << endl;
        unsigned el = element.index();
        if(m_tree->push(el)){
            qDebug() << "pushing"<< endl;
            m_container->push(std::move(element));
        }else{
            qDebug() << "element.index() failed"<< element.index() << endl;
        }
    }

    bool try_pop(Callee& res){
        if(m_container->try_pop(res)){
            return true;
        }else{
            return false;
        }
    }

    void clear_tree(){
        m_tree->clear();
    }
    bool is_empty(){
        return (m_container->is_empty()&&m_tree->is_empty());
    }
private:
    Binary_tree *m_tree; //операция push распараллелена
    Parallel_container *m_container; //операция pop распараллелена

};


template<typename Callee,template<typename>class Container>
class parallel_set_packaged
{
    //using Index_Type = decltype (std::declval<T>().index());
    using Binary_tree = binary_tree<Callee>;
    using ResultType = decltype (std::declval<Callee>()());
    using Set_type = std::packaged_task<ResultType()>;
    using Parallel_container = Container<Set_type>;

public:

    parallel_set_packaged():
        m_tree(new Binary_tree),
        m_container(new Parallel_container)
    {
        qDebug() << "parallel_set constructed" << endl;
    }
    ~parallel_set_packaged(){
        if(m_tree){
            delete m_tree;
        }
        if(m_container){
            delete m_container;
        }
        qDebug() << "parallel_set destroyed" << endl;
    }

    void push(Set_type&& element, unsigned index){
        qDebug() << "element.index()"<< index << endl;
        if(m_tree->push(index)){
            qDebug() << "pushing"<< endl;
            m_container->push(std::move(element));
        }else{
            qDebug() << "insert to tree failed"<< index << endl;
        }
    }

    bool try_pop(Set_type& res){
        if(m_container->try_pop(res)){
            return true;
        }else{
            return false;
        }
    }
    void clear_tree(){
        m_tree->clear();
    }
    bool is_empty(){
        return (m_container->is_empty()&&m_tree->is_empty());
    }
private:
    Binary_tree *m_tree; //операция push распараллелена
    Parallel_container *m_container; //операция pop распараллелена

};


#endif // PARALLEL_SET_H
