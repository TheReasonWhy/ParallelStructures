#include <QCoreApplication>
#include<QDebug>
#include "parallel_set.hpp"
#include "parallel_queue.hpp"
#include"threadpool.h"
#include"parallel_container.hpp"
#include<indexer.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    indexer<16> ix;

    if(ix.check_sum()){
        qDebug()<< "SECTOR PRIZ !! !! !!" << endl;
    }else{
        qDebug()<< "NOPE !! !! !!" << endl;
    }

/*
    unsigned param = 7;
    auto V1 = std::make_unique<victim>(param);
    qDebug() << V1.get()->func()<<endl;


    parallel_stack<victim> stack;
    victim test_victim(8);
    victim *test_victim_ptr = &test_victim;
    threadpool tp(&stack);
    tp.submit(test_victim_ptr);
    tp.pop();


    //parallel_stack<victim*> *PS;
    binary_tree<victim> tree;
    victim test_victim(8);
    victim *test_victim_ptr = &test_victim;
    threadpool tp(&tree);
    tp.push(test_victim);
    tp.pop();
  */
    return a.exec();
}
