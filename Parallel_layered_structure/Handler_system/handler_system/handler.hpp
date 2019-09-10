#ifndef HANDLER_HPP
#define HANDLER_HPP
#include<work_system.hpp>

template<typename... Args>
class handler;



template<size_t UP_NUM,
        size_t MIDDLE_NUM,
        size_t LOW_NUM,
        size_t MOVABLE_NUM,
        template<size_t,size_t,size_t,size_t> class Derived>
class handler<Work_system<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>,Derived<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>>{
public:
    using WORK_SYSTEM = Work_system<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using LEVEL_SYSTEM = typename WORK_SYSTEM::LEVEL_SYSTEM;
};




template<size_t UP_NUM,
        size_t MIDDLE_NUM,
        size_t LOW_NUM,
        size_t MOVABLE_NUM>
class handler_low :
    public handler<Work_system<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>,handler_low<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>>{
public:
    using HANDLER_BASE = handler<Work_system<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>,handler_low>;
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
    public handler<Work_system<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>,handler_middle<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>>{
public:
    using HANDLER_BASE = handler<Work_system<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>,handler_middle<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>>;
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
    public handler<Work_system<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>,handler_move<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>>
    {
public:
    using HANDLER_BASE = handler<Work_system<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>,handler_move<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>>;
    using WORK_SYSTEM = typename HANDLER_BASE::WORK_SYSTEM;
    using LEVEL_SYSTEM = typename HANDLER_BASE::LEVEL_SYSTEM;

    handler_move():m_ws(nullptr){}

    handler_move(WORK_SYSTEM *ws,
                size_t lvl_,
                size_t movable_id_,
                size_t target_id_absolute_):m_ws(ws),
                    lvl(lvl_),
                    movable_id(movable_id_),
                    target_id_absolute(target_id_absolute_)
                    {}
    ~handler_move(){m_ws=nullptr;}
    void move(size_t target_id_absolute_){
        target_id_absolute = target_id_absolute_;
        call();
    }

private:
    void call(){
        m_ws->try_push_move(lvl, movable_id, target_id_absolute);
    }

private:
    WORK_SYSTEM *m_ws;
    size_t lvl;
    size_t movable_id;

    size_t target_id_absolute;
};
#endif // HANDLER_HPP
