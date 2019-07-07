#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>
#include<atomic>
#include<QDebug>
#include"parallel_container.hpp"
#include"has_function.hpp"
#include<typeinfo>

//template<typename T, typename Enable = void>class binary_tree;

template<typename T>
class binary_tree : public Base<T, binary_tree>//, typename std::enable_if_t<std::is_integral<T>::value>
{
    public:
    //static_assert(std::is_integral<T>::value, "Требуется целочисленный тип.");
    using Push_type = T;
    using Index_type = decltype(std::declval<T>().index());
    static_assert(std::is_same_v<Index_type,unsigned >,"Index_type is wrong");

    struct binary_tree_node{
        binary_tree_node(Index_type index, binary_tree_node *parent):
            m_parent(parent),
            m_left(nullptr),
            m_right(nullptr),
            m_index(index),
            m_left_bool(false),
            m_right_bool(false){
            Index_type p;
            unsigned pp;
            int ppp;
            qDebug() << "Index_type name " << typeid (p).name()<< endl;
            qDebug() << "Unsigned_type name " << typeid (pp).name()<< endl;
            qDebug() << "Int_type name " << typeid (ppp).name()<< endl;
        }
        ~binary_tree_node(){
            if(m_left){delete m_left;}
            if(m_right){delete m_right;}
            m_parent = nullptr;
            qDebug() << "bt_node destroyed " << endl;
        }
        bool push(Index_type index){
            if(index == m_index){
                return false;
            }else if(index < m_index){
                if(m_left){
                    return m_left->push(index);
                }else{
                    for(;;){
                        qDebug() << "left iteration " << endl;
                        if(try_left_insert(index)){
                            qDebug() << "breaking left " << endl;
                            break;
                        }else if(m_left){
                            return m_left->push(index);
                        }
                    }
                    return true;
                }
            }else{
                if(m_right){
                    return m_right->push(index);
                }else{
                    for(;;){
                        qDebug() << "right iteration " << index <<  endl;
                        if(try_right_insert(index)){
                            qDebug() << "breaking right " << endl;
                            break;
                        }else if(m_right){
                            qDebug() << "pushing " << endl;
                            return m_right->push(index);
                        }
                    }
                    return true;
                }
            }
        }
        Index_type get_value(){
            return m_index;
        }
        binary_tree_node *get_parent(){
            if(m_parent){
                return m_parent;
            }else {
                return nullptr;
            }
        }
        binary_tree_node *get_last(){
            if(m_right){
                return m_right->get_last();
            }else if(m_left){
                return m_left->get_last();
            }else{
                if(m_parent){
                    m_parent->free_child(this);
                }
                return this;
            }
        }
        void free_child(binary_tree_node *child){
            if(m_left == child){
                m_left=nullptr;
            }else if(m_right == child){
                m_right=nullptr;
            }
        }

        bool try_left_insert(Index_type index){
            bool result(false);
            if((m_left_bool.compare_exchange_strong(result,true))){
                m_left = new binary_tree_node(index, this);
                return true;
            }
            return false;
        }
        bool try_right_insert(Index_type index){
            bool result(false);
            bool newresult(true);
            if((m_right_bool.compare_exchange_strong(result,newresult))){
                m_right = new binary_tree_node(index, this);
                return true;
            }
            return false;
        }

        binary_tree_node *m_parent;
        binary_tree_node *m_left;
        binary_tree_node *m_right;
        Index_type m_index;
        std::atomic_bool m_left_bool;
        std::atomic_bool m_right_bool;
    };



    binary_tree():m_root(nullptr){}
    ~binary_tree(){        
        unsigned res;
        while(pop(res)){std::cout << res << " b_tree_node_destroyed_emergently!!!" << std::endl;}
    }
    bool push(Index_type index){
        if(m_root){
            return m_root->push(index);
        }else{
            m_root = new binary_tree_node(index,nullptr);
            return true;
        }
    }
    bool pop(Index_type &result){
        binary_tree_node *last_before;
        bool res(false);
        if(m_root){
            last_before = m_root->get_last();
            result = last_before->get_value();
            if(last_before == m_root){
                delete last_before;
                m_root = nullptr;
            }else{
                delete last_before;
            }
            res = true;
        }
        return res;
    }
    void clear(){
        Index_type res;
        while(pop(res)){
            std::cout << res << " cleared" << std::endl;
        }
    }
    bool is_empty(){
        return !m_root;
    }
private:
    binary_tree_node *m_root;
};
#endif // BINARY_TREE_H
