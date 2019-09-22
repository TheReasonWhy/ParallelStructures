#ifndef INTERVAL_SYSTEM_HPP
#define INTERVAL_SYSTEM_HPP
#include<forward_list>
#include<array>
#include<string>
#include <iostream>
#include <fstream>
#include<sstream>
#include<QDebug>

/*
helper-класс для инициализации трехуровневой системы константных интервалов-соотношений.
вызовы get-методов переводят относительное положение элемента в абсолютное.
и выдают индекс этого элемента для одномерного массива.
данные о соотношениях вынесены в отдельный файл, загружаются методом init().
класс предполагается использовать только на этапе инициализации сложной многоуровневой системы.

*/
template<typename T, size_t UP_NUM,size_t MIDDLE_NUM,size_t LOW_NUM,size_t MOVABLE_NUM>
class Interval_system
{
    struct up_struct{
        up_struct(){}
        void init(size_t start_iter, size_t size){
            m_start_iter= start_iter;
            m_size = size;
        }
        size_t m_start_iter;
        size_t m_size;
    };

    struct middle_2d_interval{
        unsigned up_id;
        unsigned middle_id;
        unsigned x;
        unsigned y;
        unsigned radius_x;
        unsigned radius_y;
        middle_2d_interval(unsigned up_id_,
                            unsigned middle_id_,
                            unsigned movable_pos_x_,
                            unsigned movable_pos_y_,
                            unsigned movable_rad_x_,
                            unsigned movable_rad_y_):
                            up_id(up_id_),
                            middle_id(middle_id_),
                            x(movable_pos_x_),
                            y(movable_pos_y_),
                            radius_x(movable_rad_x_),
                            radius_y(movable_rad_y_)
        {}
        bool check(middle_2d_interval const &other){
            return !(((other.x+other.radius_x)>=(x-radius_x))||
                    ((other.x-other.radius_x)<=(x+radius_x))||
                    ((other.y+other.radius_y)>=(y-radius_y))||
                    ((other.y-other.radius_y)<=(y+radius_y)));
        }
    };
    struct middle_2d_interval_block{
        unsigned middle_id;
        std::forward_list<middle_2d_interval> m_list;

        bool try_insert(middle_2d_interval candidate){
            auto iter = m_list.begin();
            bool checked(true);
            while (iter!=m_list.end() || !checked) {

                checked = candidate.check(*iter);
                iter++;
            }
            if(checked){
                m_list.push_front(candidate);
            }
            return checked;
        }
        bool try_get_interval(unsigned id, middle_2d_interval &interval){
            auto iter = m_list.begin();
            bool found(false);
            while (!(iter==m_list.end()||found==true)) {
                if((*iter).id==id){
                    interval = *iter;
                    found=true;
                }
                iter++;
            }
            return found;
        }


    };
    struct middle_struct{
        middle_struct(){}
        void init(size_t start_iter,size_t size,size_t width,size_t height){
            m_start_iter= start_iter;
            m_size = size;
            m_width=width;
            m_height=height;
        }
        size_t m_start_iter;
        size_t m_size;
        size_t m_width;
        size_t m_height;
    };
    inline static std::array<up_struct, UP_NUM> UP={};
    inline static std::array<middle_struct, MIDDLE_NUM> MIDDLE={};
    inline static std::array<size_t, LOW_NUM> LOW={};
    std::array<middle_2d_interval_block,MIDDLE_NUM> m_intervals={};

public:
    Interval_system(){}
    void init(std::string const filename){
        qDebug()<< "init_intervals()"<< endl;
        std::ifstream file = std::ifstream(filename);
        if (!file.good()) {
            qDebug()<<filename.data()<< "not found!"<< endl;
            throw std::exception();
        }
        unsigned up_id(0);
        unsigned up_interval(0);
        unsigned middle_id(0);
        unsigned movable_pos_x(0);
        unsigned movable_pos_y(0);
        unsigned movable_rad_x(0);
        unsigned movable_rad_y(0);
        unsigned middle_interval(0);
        unsigned movable_id(0);
        size_t iterator_up(0);
        size_t iterator_middle(0);
        size_t middle_width;
        size_t middle_height;
        std::string string_iter;
        while(!file.eof()||iterator_middle>LOW_NUM){
            getline(file,string_iter,' ');
            if(string_iter == "up"){
                file>>up_id;
                file>>up_interval;
                if((iterator_up+up_interval)>=MIDDLE_NUM){
                    up_interval=MIDDLE_NUM-iterator_up;//было -1
                }
                UP.at(up_id).init(iterator_up,up_interval);
                getline(file,string_iter);
                iterator_up+=up_interval;
            }else if (string_iter == "mid") {
                file>>middle_id;
                file>>middle_width;
                file>>middle_height;
                middle_interval+=(middle_width*middle_height);
                if((iterator_middle+middle_interval)>=LOW_NUM){
                    middle_interval=LOW_NUM-iterator_middle;//было -1
                }
                MIDDLE.at(middle_id).init(iterator_middle,middle_interval,middle_width,middle_height);
                getline(file,string_iter);
                iterator_middle+=middle_interval;

            }else if (string_iter == "f") {
                file>>movable_pos_x;
                file>>movable_pos_y;
                file>>movable_rad_x;
                file>>movable_rad_y;
                middle_2d_interval candidate(up_id, middle_id, movable_pos_x,movable_pos_y,movable_rad_x,movable_rad_y);
                if(m_intervals.at(middle_id).try_insert(candidate)){
                    movable_id++;
                }else{
                    qDebug()<< "INVALID_INTERVAL movable_pos_x"
                    << movable_pos_x
                    << "movable_pos_y "<< movable_pos_y
                    << "movable_rad_x "<< movable_rad_x
                    << "movable_rad_y "<< movable_rad_y<< endl;
                }
            }
        }
        qDebug()<< "Interval_system() initialized " << endl;
    }
    static T get_middle_id_by_low(size_t const low_id){
        size_t left_iter, right_iter;
        size_t iter(0);
        left_iter = MIDDLE.at(iter).m_start_iter;
        right_iter = left_iter+MIDDLE.at(iter).m_size;
        while (!(low_id>=left_iter && low_id<right_iter)){
            iter++;
            left_iter = MIDDLE.at(iter).m_start_iter;
            right_iter = left_iter+MIDDLE.at(iter).m_size;
        }
        return iter;
    }

    static size_t get_up_id_by_middle(size_t const middle_id){
        size_t left_iter, right_iter;
        size_t iter(0);
        left_iter = UP.at(iter).m_start_iter;
        right_iter = left_iter+UP.at(iter).m_size;
        while (!(middle_id>=left_iter && middle_id<right_iter)){
            iter++;
            left_iter = UP.at(iter).m_start_iter;
            right_iter = left_iter+UP.at(iter).m_size;
        }
        return iter;
    }

    static size_t get_up_id_by_low(size_t const low_id){
        size_t middle_id = get_middle_id_by_low(low_id);
        return get_up_id_by_middle(middle_id);
    }

    static T get_middle_id(size_t const up_id, size_t const mid_id){
        return static_cast<T>((UP.at(up_id).m_start_iter+mid_id));
    }
    static T get_low_id(size_t const up_id, size_t const mid_id, size_t const low_id){
        return static_cast<T>((MIDDLE.at(UP.at(up_id).m_start_iter+mid_id).m_start_iter+low_id));
    }
    static T get_low_id(size_t const mid_id, size_t const low_id){
        return static_cast<T>((MIDDLE.at(mid_id).m_start_iter+low_id));
    }
    static std::pair<size_t,size_t> get_interval_up(unsigned up_id){
        return std::pair<size_t,size_t>(UP.at(up_id).m_start_iter,UP.at(up_id).m_size);
    }
    static std::pair<size_t,size_t> get_interval_middle(unsigned mid_id){
        return std::pair<size_t,size_t>(MIDDLE.at(mid_id).m_start_iter,MIDDLE.at(mid_id).m_size);
    }
    static size_t get_width_for(size_t middle_id){
        return MIDDLE.at(middle_id).m_width;
    }

    static size_t get_height_for(size_t middle_id){
        return MIDDLE.at(middle_id).m_height;
    }

    static std::vector<size_t> get_movable_range_1D_for(size_t const low_id, size_t const size_){
        std::vector<size_t> result;
        if(((size_%2)!=0)&&size_!=1){
            for (size_t start = low_id-((size_-1)/2); start<start+size_; start++) {
                result.push_back(start);
            }
        }else {
            result.push_back(low_id);
        }

        return result;
    }

    bool try_get_movable(unsigned middle_id_iterator,unsigned movable_id_iterator,middle_2d_interval &interval_data){
        bool result(false);
        result = m_intervals.at(middle_id_iterator).try_get_interval(movable_id_iterator,interval_data);
        return result;
    }
};

#endif // INTERVAL_SYSTEM_HPP














