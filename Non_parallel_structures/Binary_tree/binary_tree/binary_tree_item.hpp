#ifndef BINARY_TREE_ITEM_HPP
#define BINARY_TREE_ITEM_HPP
#include<QDebug>
#include <iterator>
#include <vector>
#include <memory>
#include <iostream>
#include <string>


const unsigned FAILURE_KEY = 999999999;

template <typename T>
class binarytree_item : public std::enable_shared_from_this<binarytree_item<T>>{
    using item = binarytree_item<T>;

    public:
    binarytree_item():
        m_key(0),
        m_value(0),
        m_left(nullptr),
        m_right(nullptr),
        m_parent(std::shared_ptr<item>()){
    }
    binarytree_item(unsigned key, T value):
        m_key(key),
        m_value(value),
        m_left(nullptr),
        m_right(nullptr),
        m_parent(std::shared_ptr<item>())

    {
    }
    binarytree_item(std::shared_ptr<item> parent, unsigned key, T value):
        m_key(key),
        m_value(value),
        m_left(nullptr),
        m_right(nullptr),
        m_parent(parent)
    {
    }
    binarytree_item(const binarytree_item<T> &other)=delete;
    binarytree_item &operator=(const binarytree_item<T> &other)=delete;
    ~binarytree_item(){
        qDebug()<<"~binarytree_item() "<<m_key<<endl;
    }

    std::shared_ptr<item> getptr();

    void set_parent(std::shared_ptr<item> parent);
    void reset_parent();
    void remove_child(std::shared_ptr<item> &child);
    void append_child(std::shared_ptr<item> &child);
    std::shared_ptr<item> cut();
    std::shared_ptr<item> pop();
    bool insert_unique(std::pair<unsigned,T> element);
    bool insert(std::pair<unsigned,T> element);

    std::shared_ptr<item> find(unsigned key);
    void set_value(T val);
    std::pair<unsigned, T> get_key_value()const;
    std::shared_ptr<item> get_parent()const;
    std::shared_ptr<item> get_left()const;
    std::shared_ptr<item> get_right()const;
    std::shared_ptr<item> get_most_left();
    std::shared_ptr<item> get_most_right();

    unsigned get_height(unsigned counter);

    void merge_trees();
    void insert_branch(std::shared_ptr<item> &branch);
    void insert_branch(std::shared_ptr<item> &&branch);
    void insert_branch_unique(std::shared_ptr<item> &&branch);
    bool erase(unsigned key);

    bool has_child();
    void output(); //обход дерева с выводом
    void size(unsigned &counter);

private:
    unsigned m_key;
    T m_value;
    std::shared_ptr<item> m_left;
    std::shared_ptr<item> m_right;
    std::weak_ptr<item> m_parent;
};

template<typename T>
std::shared_ptr<typename binarytree_item<T>::item> binarytree_item<T>::getptr() {
    return this->shared_from_this();
}

template<typename T>
void binarytree_item<T>::set_parent(std::shared_ptr<typename binarytree_item<T>::item> parent){
    m_parent = parent;
}

template<typename T>
void binarytree_item<T>::reset_parent(){
    m_parent.reset();
}

template<typename T>
void binarytree_item<T>::remove_child(std::shared_ptr<typename binarytree_item<T>::item> &child){
    try {
        if(child==m_left){
            qDebug()<<"remove_left"<<endl;
            m_left.reset();
        }else if(child==m_right){
            qDebug()<<"remove_right"<<endl;
            m_right.reset();
        }else{
            throw std::exception();
        }
    } catch (std::exception &exception) {
        std::cerr <<"No such child to remove" << exception.what() << std::endl;
    }

}

template<typename T>
void binarytree_item<T>::append_child(std::shared_ptr<typename binarytree_item<T>::item> &child){
    if(child.get()->get_key_value().first<m_key){
        m_left=child;
    }else{
        m_right=child;
    }
    child.get()->set_parent(getptr());
}

template<typename T>
std::shared_ptr<typename binarytree_item<T>::item> binarytree_item<T>::cut(){
    std::shared_ptr<item> res = getptr();
    std::shared_ptr<item> parent = res.get()->get_parent();
    if(parent){
        parent.get()->remove_child(res);
        parent.reset();
    }
    //m_parent.reset();
    return res;
}

template<typename T>
std::shared_ptr<typename binarytree_item<T>::item> binarytree_item<T>::pop(){
    std::shared_ptr<item> res=getptr();
    while(res.get()->has_child()){
        qDebug()<<"has_child"<<endl;
        if(res.get()->get_left()){
        qDebug()<<"get_left"<<endl;
            res = res.get()->get_left();
        }
        else if(res.get()->get_right()){
        qDebug()<<"get_right"<<endl;
            res = res.get()->get_right();
        }
    }
    return res.get()->cut();
}

template<typename T>
bool binarytree_item<T>::insert_unique(std::pair<unsigned, T> item){
    unsigned key =item.first;
    T val =item.second;
    bool result(true);
    if(key>m_key){
        if(m_right){
            result = m_right.get()->insert_unique(item);
        }else{
            m_right = std::make_shared<binarytree_item>(getptr(), key, val);
        }
    }else if(key<m_key){
        if(m_left){
            result = m_left.get()->insert_unique(item);
        }else{
            m_left = std::make_shared<binarytree_item>(getptr(), key, val);
        }
    }else{
        result = false;
    }
    return result;
}

template<typename T>
bool binarytree_item<T>::insert(std::pair<unsigned, T> item)
{
    unsigned key =item.first;
    T val =item.second;
    bool result(true);
    if(key>=m_key){
        if(m_right){
            result = m_right.get()->insert(item);
        }else{
            m_right = std::make_shared<binarytree_item>(getptr(), key, val);
        }
    }else if(key<m_key){
        if(m_left){
            result = m_left.get()->insert(item);
        }else{
            m_left = std::make_shared<binarytree_item>(getptr(), key, val);
        }
    }else{
        result = false;
    }
    return result;
}

template<typename T>
std::shared_ptr<typename binarytree_item<T>::item> binarytree_item<T>::find(unsigned key){
    if(key>m_key){
        if(m_right){
            return get_right()->find(key);
        }else{
            return std::shared_ptr<item>();
        }
    }else if(key<m_key){
        if(m_left){
            return get_left()->find(key);
        }else{
            return std::shared_ptr<item>();
        }
    }else{
        return getptr();
    }
}

template<typename T>
void binarytree_item<T>::set_value(T val){
    m_value=val;
}

template<typename T>
std::pair<unsigned, T> binarytree_item<T>::get_key_value() const{
    return std::make_pair(m_key,m_value);
}

template<typename T>
std::shared_ptr<typename binarytree_item<T>::item> binarytree_item<T>::get_parent() const{
    return m_parent.lock();
}
template<typename T>
std::shared_ptr<typename binarytree_item<T>::item> binarytree_item<T>::get_left() const{
    return m_left;
}
template<typename T>
std::shared_ptr<typename binarytree_item<T>::item> binarytree_item<T>::get_right() const{
    return m_right;
}

template<typename T>
std::shared_ptr<typename binarytree_item<T>::item>  binarytree_item<T>::get_most_left(){
    std::shared_ptr<item> most_left = m_left;;
    while(most_left.get()->get_left()){
        most_left = most_left.get()->get_left();
    }
    return most_left;
}

template<typename T>
std::shared_ptr<typename binarytree_item<T>::item> binarytree_item<T>::get_most_right(){
    std::shared_ptr<item> most_right = m_right;
    while(most_right.get()->get_right()){
        most_right = most_right.get()->get_right();
    }
    return most_right;
}


template<typename T>
unsigned binarytree_item<T>::get_height(unsigned counter)
{
    unsigned left_val=counter;
    unsigned right_val=counter;
    if(m_left){
        left_val = m_left.get()->get_height(++left_val);
    }
    if(m_right){
        right_val = m_right.get()->get_height(++right_val);
    }
    if(left_val>=right_val){
        return left_val;
    }else{
        return right_val;
    }
}


template<typename T>
void binarytree_item<T>::merge_trees(){
    std::shared_ptr<item> res(nullptr);
    if(m_left && m_right){
        unsigned left_count=0;
        unsigned right_count=0;
        unsigned left_height=m_left.get()->get_height(left_count);
        unsigned right_height=m_right.get()->get_height(right_count);
        if(left_height>=right_height){
            res = m_left.get()->get_most_right().get()->cut();
        }else{
            res = m_right.get()->get_most_left().get()->cut();
        }
    }else if(m_left){
        res = m_left.get()->cut();

    }else if(m_right){
        res = m_right.get()->cut();
    }
    m_left=res.get()->m_left;
    m_right=res.get()->m_right;
    m_key=res.get()->m_key;
    m_value=res.get()->m_value;
}


template<typename T>
void binarytree_item<T>::insert_branch(std::shared_ptr<typename binarytree_item<T>::item> &branch)
{
    std::pair<unsigned,T> to_insert;
    std::shared_ptr<item> iter = branch.get()->pop();
    if(iter){
        do{
            to_insert = iter.get()->get_key_value();
            insert(to_insert);
            iter = branch.get()->pop();
        }while(branch!=iter);
        to_insert = iter.get()->get_key_value();
        insert(to_insert);
    }
}
template<typename T>
void binarytree_item<T>::insert_branch(std::shared_ptr<typename binarytree_item<T>::item> &&branch)
{
    std::pair<unsigned,T> to_insert;
    std::shared_ptr<item> iter = branch.get()->pop();
    if(iter){
        do{
            to_insert = iter.get()->get_key_value();
            insert(to_insert);
            iter = branch.get()->pop();
        }while(branch!=iter);
        to_insert = iter.get()->get_key_value();
        insert(to_insert);
    }
}

template<typename T>
void binarytree_item<T>::insert_branch_unique(std::shared_ptr<typename binarytree_item<T>::item> &&branch)
{
    std::pair<unsigned,T> to_insert;
    std::shared_ptr<item> iter = branch.get()->pop();
    if(iter){
        do{
            to_insert = iter.get()->get_key_value();
            insert_unique(to_insert);
            iter = branch.get()->pop();
        }while(branch!=iter);
        to_insert = iter.get()->get_key_value();
        insert_unique(to_insert);
    }
}

template<typename T>
bool binarytree_item<T>::erase(unsigned key){
    bool result(false);
    if(key<m_key){
        if(m_left){
            result = m_left.get()->erase(key);
        }
    }else if(key>m_key){
        if(m_right){
            result = m_right.get()->erase(key);
        }
    }else{
        merge_trees();
        result=true;
    }
    return result;
}

template<typename T>
bool binarytree_item<T>::has_child(){
    return (m_left || m_right);
}

template<typename T>
void binarytree_item<T>::output(){
    if(m_right){
        m_right.get()->output();
    }

    unsigned parent = FAILURE_KEY;
    unsigned left = FAILURE_KEY;
    unsigned right = FAILURE_KEY;
    if(get_parent()){parent = get_parent().get()->get_key_value().first;}
    if(m_left){left = m_left.get()->get_key_value().first;}
    if(m_right){right = m_right.get()->get_key_value().first;}
    std::cout<<"k_"<<m_key<<"v_"<<m_value<<"p_"<<parent<<"l_"<<left<<"r_"<<right<<std::endl;

    if(m_left){
        m_left.get()->output();
    }
}

template<typename T>
void binarytree_item<T>::size(unsigned &counter)
{
    if(m_right){
        m_right.get()->size(counter);
    }
    ++counter;
    if(m_left){
        m_left.get()->size(counter);
    }
}
#endif // BINARY_TREE_ITEM_HPP
