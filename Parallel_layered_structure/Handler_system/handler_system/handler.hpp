#ifndef HANDLER_HPP
#define HANDLER_HPP
#include<work_system.hpp>

template<size_t UP_NUM,
        size_t MIDDLE_NUM,
        size_t LOW_NUM,
        size_t MOVABLE_NUM>
class handler{
public:
    using WORK_SYSTEM = Work_system<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using LEVEL_SYSTEM = typename WORK_SYSTEM::LEVEL_SYSTEM;
};


template<size_t UP_NUM,
        size_t MIDDLE_NUM,
        size_t LOW_NUM,
        size_t MOVABLE_NUM>
class handler_low :
    public handler<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>{
public:
    using HANDLER_BASE = handler<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using WORK_SYSTEM = typename HANDLER_BASE::WORK_SYSTEM;
    using LEVEL_SYSTEM = typename HANDLER_BASE::LEVEL_SYSTEM;

    handler_low():m_ws(nullptr){}
    handler_low(WORK_SYSTEM *ws, size_t lvl_, size_t low_id_absolute_):m_ws(ws),lvl(lvl_),low_id_absolute(low_id_absolute_){}
    ~handler_low(){m_ws=nullptr;}
    void call(){
        m_ws->try_push_element(lvl, low_id_absolute);
    }

private:
    WORK_SYSTEM *m_ws;
    size_t lvl;
    size_t low_id_absolute;

};

template<size_t UP_NUM,
        size_t MIDDLE_NUM,
        size_t LOW_NUM,
        size_t MOVABLE_NUM>
class handler_middle :
    public handler<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>{
public:
    using HANDLER_BASE = handler<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using WORK_SYSTEM = typename HANDLER_BASE::WORK_SYSTEM;
    using LEVEL_SYSTEM = typename HANDLER_BASE::LEVEL_SYSTEM;

    handler_middle():m_ws(nullptr){}
    handler_middle(WORK_SYSTEM *ws,size_t lvl_, size_t middle_id_absolute_):m_ws(ws),lvl(lvl_),middle_id_absolute(middle_id_absolute_){}
    ~handler_middle(){m_ws=nullptr;}
    void call(){
        m_ws->try_push_routable(lvl, middle_id_absolute);
    }

private:
    WORK_SYSTEM *m_ws;
    size_t lvl;
    size_t middle_id_absolute;

};



template<size_t UP_NUM,
        size_t MIDDLE_NUM,
        size_t LOW_NUM,
        size_t MOVABLE_NUM>
class handler_move :
    public handler<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>{

public:
    using HANDLER_BASE = handler<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using WORK_SYSTEM = typename HANDLER_BASE::WORK_SYSTEM;
    using LEVEL_SYSTEM = typename HANDLER_BASE::LEVEL_SYSTEM;
    inline static const int TICKS_NUM = 1000;

struct movable_field_data{
    int WIDTH;
    int rad_x;
    int rad_y;

    int base_x;
    int base_y;
    int base_index;

    int cur_x;
    int cur_y;
    movable_field_data(int WIDTH_,int rad_x_,int rad_y_,int base_x_,int base_y_,size_t middle_zero_id):
    WIDTH(WIDTH_),
    rad_x(rad_x_),
    rad_y(rad_y_),
    base_x(base_x_),
    base_y(base_y_),
    cur_x(base_x_),
    cur_y(base_y_){
        base_index = static_cast<int>(middle_zero_id) + base_x_+(WIDTH_*base_y_);
    }

    size_t apply_ticks_x(int new_ticks_position){
        int res(0);
        if(rad_x!=0){
            res = (rad_x/TICKS_NUM)*new_ticks_position;
        }
        cur_x = base_x+res;
        return static_cast<size_t>(base_index+cur_x+(cur_y*WIDTH));
    }
    size_t apply_ticks_y(int new_ticks_position){
        int res(0);
        if(rad_y!=0){
            res = (rad_y/TICKS_NUM)*new_ticks_position;
        }
        cur_y = base_y+res;
        return static_cast<size_t>(base_index+cur_x+(cur_y*WIDTH));
    }
};
    handler_move(){}
    virtual ~handler_move(){}
    virtual void set_field(movable_field_data *field);
    virtual void on_ticks_change(int new_ticks_position);
};

template<size_t UP_NUM,
        size_t MIDDLE_NUM,
        size_t LOW_NUM,
        size_t MOVABLE_NUM>
class handler_move_x : public handler_move<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>
{
    using PARENT = handler_move<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using movable_field_data = typename PARENT::movable_field_data;
    using WORK_SYSTEM = typename PARENT::WORK_SYSTEM;
    handler_move_x():m_ws(nullptr),
                    m_field(nullptr){}
    handler_move_x(WORK_SYSTEM *ws, size_t lvl_, size_t movable_id_):
        m_ws(ws),
        lvl(lvl_),
        movable_id(movable_id_),
        m_field(nullptr),
        ticks_current(0){}
    virtual ~handler_move_x(){}
    virtual void set_field(movable_field_data *field)override{
        m_field = field;
    }
    virtual void on_ticks_change(int new_ticks_position)override{
        if(new_ticks_position>PARENT::TICKS_NUM){
            ticks_current=PARENT::TICKS_NUM;
        }else if (new_ticks_position<(-PARENT::TICKS_NUM)) {
            ticks_current=-PARENT::TICKS_NUM;
        }
        size_t target_id_absolute = m_field->apply_ticks_x(ticks_current);
        m_ws->try_push_move(lvl,movable_id,target_id_absolute);
    }
private:
    WORK_SYSTEM *m_ws;
    size_t lvl;
    size_t movable_id;
    movable_field_data *m_field;
    int ticks_current;
};

template<size_t UP_NUM,
        size_t MIDDLE_NUM,
        size_t LOW_NUM,
        size_t MOVABLE_NUM>
class handler_move_y : public handler_move<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>
{
    using PARENT = handler_move<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using movable_field_data = typename PARENT::movable_field_data;
    using WORK_SYSTEM = typename PARENT::WORK_SYSTEM;
    handler_move_y():m_ws(nullptr),
                    m_field(nullptr){}
    handler_move_y(WORK_SYSTEM *ws, size_t lvl_, size_t movable_id_):
        m_ws(ws),
        lvl(lvl_),
        movable_id(movable_id_),
        m_field(nullptr),
        ticks_current(0){}
    virtual ~handler_move_y(){}

    virtual void set_field(movable_field_data *field)override{
        m_field = field;
    }
    virtual void on_ticks_change(int new_ticks_position)override{
        if(new_ticks_position>PARENT::TICKS_NUM){
            ticks_current=PARENT::TICKS_NUM;
        }else if (new_ticks_position<(-PARENT::TICKS_NUM)) {
            ticks_current=-PARENT::TICKS_NUM;
        }
        size_t target_id_absolute = m_field->apply_ticks_x(ticks_current);
        m_ws->try_push_move(lvl,movable_id,target_id_absolute);
    }


private:
    WORK_SYSTEM *m_ws;
    size_t lvl;
    size_t movable_id;
    movable_field_data *m_field;
    int ticks_current;
};

#endif // HANDLER_HPP
