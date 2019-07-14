#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "binary_tree_item.hpp"

template <typename T>
class binarytree {
public:
using Item = binarytree_item<T>;

private:
    std::shared_ptr<Item> m_root;

public:
    binarytree(){}
    binarytree(std::vector<std::pair<unsigned, T>> &params);
    ~binarytree(){}
    binarytree<T> &add(binarytree<T> &other);
    binarytree<T> &add_unique(binarytree<T> &other);
    bool insert_unique(unsigned key, T value);
    bool insert_unique(std::pair<unsigned,T> element);
    bool insert(unsigned key, T value);
    bool insert(std::pair<unsigned,T> element);
    std::pair<unsigned,T> pop();
    T find(unsigned key);
    bool erase(unsigned key);
    void output();
    unsigned height()const;
    unsigned size()const;

};
#endif /* BINARYTREE_H */


template<typename T>
binarytree<T>::binarytree(std::vector<std::pair<unsigned, T> > &params){
    while(!params.empty()){
        std::pair<unsigned, T> param = params.back();
        params.pop_back();
        if(!m_root){
            m_root= std::make_shared<Item>(param.first,param.second);
        }else{
            m_root.get()->insert_unique(param);
        }
    }
}

template<typename T>
binarytree<T> &binarytree<T>::add(binarytree<T> &other){
    if(m_root&&other.m_root){
        m_root.get()->insert_branch(std::move(other.m_root));
    }
    return *this;
}

template<typename T>
binarytree<T> &binarytree<T>::add_unique(binarytree<T> &other){
    if(m_root&&other.m_root){
        m_root.get()->insert_branch_unique(std::move(other.m_root));
    }
    return *this;
}

template<typename T>
bool binarytree<T>::insert_unique(unsigned key, T value){
    bool result(false);
    if(m_root){
        std::pair<unsigned,T> element(key,value);
        result = m_root.get()->insert_unique(element);
    }else{
        m_root= std::make_shared<Item>(key,value);
        result=true;
    }
    return result;
}

template<typename T>
bool binarytree<T>::insert_unique(std::pair<unsigned, T> element){
    bool result(false);
    if(m_root){
        result = m_root.get()->insert_unique(element);
    }else{
        m_root = std::make_shared<Item>(element.first,element.second);
        result=true;
    }
    return result;
}

template<typename T>
bool binarytree<T>::insert(unsigned key, T value){
    bool result(false);
    if(m_root){
        std::pair<unsigned,T> element(key,value);
        result = m_root.get()->insert(element);
    }else{
        m_root= std::make_shared<Item>(key,value);
        result=true;
    }
    return result;
}

template<typename T>
bool binarytree<T>::insert(std::pair<unsigned, T> element){
    bool result(false);
    if(m_root){
        result = m_root.get()->insert(element);
    }else{
        m_root= std::make_shared<Item>(element.first,element.second);
        result=true;
    }
    return result;
}

template<typename T>
std::pair<unsigned, T> binarytree<T>::pop(){
    if(m_root){
        return m_root.get()->pop().get()->get_key_value();
    }else{
        return std::pair<unsigned,T>(FAILURE_KEY,NULL);
    }
}

template<typename T>
T binarytree<T>::find(unsigned key){
    T res;
    if(m_root){
        auto result = m_root.get()->find(key);
        if(result){
            res=result.get()->get_key_value().second;
        }
    }
    return res;
}

template<typename T>
bool binarytree<T>::erase(unsigned key){
    bool result(false);
    if(m_root){
        result = m_root.get()->erase(key);
    }
    return result;
}

template<typename T>
void binarytree<T>::output(){
    if(m_root){
        m_root.get()->output();
    }
}

template<typename T>
unsigned binarytree<T>::height() const{
    if(m_root){
        return m_root.get()->get_height(0);
    }else{
        return 0;
    }
}

template<typename T>
unsigned binarytree<T>::size() const{
    unsigned result=0;
    if(m_root){
        m_root.get()->size(result);
    }
    return result;
}
