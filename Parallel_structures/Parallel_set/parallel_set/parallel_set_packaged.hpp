#ifndef PARALLEL_SET_PACKAGED_HPP
#define PARALLEL_SET_PACKAGED_HPP
#include<future>
#include"parallel_binary_tree.hpp"
#include"lock_free_queue_packaged_task.hpp"


template<typename Callee,template<typename>class Container>
class parallel_set_packaged
{
    //using Index_Type = decltype (std::declval<T>().index());
    using Binary_tree = parallel_binary_tree<Callee>;
    using ResultType = decltype (std::declval<Callee>()());
    using Packaged_type = std::packaged_task<ResultType()>;
    using P_container = Container<Packaged_type>;

public:

    parallel_set_packaged():
        m_tree(new Binary_tree),
        m_container(new P_container)
    {
        qDebug() << "parallel_set_packaged constructed" << endl;
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

    bool push(Packaged_type&& element, unsigned index){
        bool res(false);
        if(m_tree->push(index)){
            res = m_container->push(std::move(element));
        }
        return res;
    }
    bool try_pop(Packaged_type& res){
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
    P_container *m_container; //операция pop распараллелена

};
#endif // PARALLEL_SET_PACKAGED_HPP
