#ifndef LAYERED_DATA_H
#define LAYERED_DATA_H
#include<array>
#include<string>
#include <iostream>
#include <fstream>
#include<sstream>
#include<QDebug>
#include<up_data_t1.h>
#include<up_data_t2.h>
#include<middle_data_t1.h>
#include<middle_data_t2.h>
#include<low_data_t1.h>
#include<low_data_t2.h>
#include<interval_system.hpp>
/*
тестовый класс,имитирующий иерархическую структуру.
в него вынесена логика программы, не связанная с параллелизмом и/или вызовом подчиненных структур

*/
template<typename... Args>
class Layered_data;

template<typename T, size_t UP_SIZE,size_t MIDDLE_SIZE,size_t LOW_SIZE>
class Layered_data<Interval_system<T,UP_SIZE,MIDDLE_SIZE,LOW_SIZE>>
{
    using INTERVAL_SYSTEM = Interval_system<T,UP_SIZE,MIDDLE_SIZE,LOW_SIZE>;
    std::array<up_data, UP_SIZE> UP;
    std::array<middle_data, MIDDLE_SIZE> MIDDLE;
    std::array<low_data, LOW_SIZE> LOW;
public:
    Layered_data(){}
    void init(std::string const filename,INTERVAL_SYSTEM *IS){
        qDebug()<< "init_layered_data()"<< endl;
        std::ifstream file = std::ifstream(filename);
        if (!file.good()) {
            qDebug()<<filename.data()<< "not found!"<< endl;
            throw std::exception();
        }
        unsigned item_id(0);
        unsigned item_type(0);
        unsigned item_param1(0);
        size_t width;
        size_t height;
        std::string string_iter;
        while(!file.eof()){
            getline(file,string_iter,' ');
            if(string_iter == "u"){
                file>>item_id;
                file>>item_type;
                file>>item_param1;
                if(item_type==0){
                    UP.at(item_id)=static_cast<up_data>(up_data_t1(item_param1));
                }else if (item_type==1) {
                    UP.at(item_id)=static_cast<up_data>(up_data_t2(item_param1));
                }
                getline(file,string_iter);
            }else if (string_iter == "m") {
                file>>item_id;
                file>>item_type;
                width = IS->get_width_for(item_id);
                height = IS->get_height_for(item_id);
                if(item_type==0){
                    MIDDLE.at(item_id)=static_cast<middle_data>(middle_data_t1(width,height));
                }else if (item_type==1) {
                    MIDDLE.at(item_id)=static_cast<middle_data>(middle_data_t2(width,height));
                }
                getline(file,string_iter);

            }else if (string_iter == "e") {
                file>>item_id;
                file>>item_type;
                file>>item_param1;
                if(item_type==0){
                    LOW.at(item_id)=static_cast<low_data>(low_data_t1(item_param1));
                }else if (item_type==1) {
                    LOW.at(item_id)=static_cast<low_data>(low_data_t2(item_param1));
                }
                getline(file,string_iter);

            }
        }
        qDebug()<< "Layered_data() initialized " << endl;
    }
    up_data *get_up_data(size_t const index){
        return &UP.at(index);
    }
    middle_data *get_middle_data(size_t const index){
        return &MIDDLE.at(index);
    }
    low_data *get_low_data(size_t const index){
        return &LOW.at(index);
    }

};

#endif // LAYERED_DATA_H
