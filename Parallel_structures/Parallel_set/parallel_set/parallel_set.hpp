#ifndef PARALLEL_SET_HPP
#define PARALLEL_SET_HPP
#include"parallel_binary_tree.hpp"
#include"../../parallel_container/parallel_container.hpp"
#include<lock_free_queue.hpp>

template<typename Callee,template<typename>class Container>
class parallel_set
{
    //using Index_Type = decltype (std::declval<T>().index());
    using Binary_tree = parallel_binary_tree<Callee>;
    using ResultType = decltype (std::declval<Callee>()());
    using P_container = lock_free_queue<Callee>;
    //using ResultType = decltype (std::declval<Parallel_container>().pop());
    //static_assert (std::is_same_v<ResultType,std::shared_ptr<T>>,"Result type Wrong" );
    //static_assert (std::is_convertible_v<std::shared_ptr<T>,bool>, "Can't convert this type to bool" );
    //using Work = work<Memfunc, memfunc, Callee>;

public:

    parallel_set()
    {
        qDebug() << "parallel_set constructed" << endl;
    }
    ~parallel_set(){
        qDebug() << "parallel_set destroyed" << endl;
    }
    void push(Callee&& element, unsigned const index){
        if(push_to_Binary_tree(index)){
            push_to_container(std::move(element));
        }

    }
    /**/
     void push(Callee& element, unsigned const index){
        if(push_to_Binary_tree(index)){
            m_container.push(std::move(element));
        }
    }

    bool try_pop(Callee& res){
        if(m_container.try_pop(res)){
            return true;
        }else{
            return false;
        }
    }

    void clear_tree(){
        m_tree.clear();

    }
    bool is_empty(){
        return (m_container.is_empty()&&m_tree.is_empty());
    }
    static constexpr Binary_tree get_bunary_tree(){
        return Binary_tree();
    }
    static constexpr P_container get_P_container(){
        return P_container();
    }
    static constexpr bool push_to_Binary_tree(unsigned element){
        return m_tree.push(element);
    }
    static constexpr bool push_to_container(Callee&& element){
        m_container.push(std::move(element));
        return true;
    }

private:
    inline static Binary_tree m_tree=get_bunary_tree(); //операция push распараллелена
    inline static P_container m_container=get_P_container(); //операция pop распараллелена

};



#endif // PARALLEL_SET_HPP
