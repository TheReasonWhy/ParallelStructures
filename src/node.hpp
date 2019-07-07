#ifndef NODE_H
#define NODE_H
#include<atomic>
#include<type_traits>
#include<utility>
#include<functional>
#include <iostream>
#include <typeinfo>
#include<QDebug>
/*
template<typename T>struct node{};


template<typename T>//Т должно иметь копирующий конструктор!!!
struct node<T*>
{
    using Node = node<T*>;

    node():m_value(nullptr),counter(0){
        qDebug() << "node constructor ()" << endl;
    }
    node(T &value):m_value(value),counter(0){
        qDebug() << "node constructor T &val" << endl;
    }
    node(T *value):m_value(value),counter(0){
        qDebug() << "node constructor T *val" << endl;
    }
    node(Node &other):m_value(other.m_value),counter(0){other.m_value = nullptr;}
    node(Node &&other):m_value(other.m_value),counter(0){other.m_value = nullptr;}
    node(Node *other):m_value(other->m_value),counter(0){other->m_value = nullptr;}
    ~node(){if(m_value){
            delete m_value;
        }
    }
    T *value(){
        return m_value;
    }
    void free(){
        m_value = nullptr;
    }
    node& operator = (node& other){
        this->m_value = other.m_value;
        this->counter = other.counter;
        other.m_value=nullptr;
        return *this;
    }
    node& operator = (node* other){
        this->m_value = other->m_value;
        this->counter = other->counter;
        other->m_value=nullptr;
        return *this;
    }
    node& operator = (node&& other){
        this->m_value = other.m_value;
        this->counter = other.counter;
        other.m_value=nullptr;
        return *this;
    }
    friend bool operator ==(node const &left, node const &right){
        return(left.m_value == right.m_value);
    }
    friend bool operator !=(node const &left, node const &right){
        return !(left == right);
    }
private:
    T *m_value;
    unsigned counter;
};


*/
#endif // NODE_H
