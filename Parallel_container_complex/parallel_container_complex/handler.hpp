#ifndef HANDLER_HPP
#define HANDLER_HPP
#include<work_system.hpp>

template<typename... Args>
class handler;



template<size_t LEVELS_NUM,
        size_t ROUTABLES_NUM,
        size_t ELEMENTS_NUM,
        template<size_t,size_t,size_t> class Derived>
class handler<Work_system<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM>,Derived<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM>>{
public:
    using WORK_SYSTEM = Work_system<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM>;
    using LEVEL_SYSTEM = typename WORK_SYSTEM::LEVEL_SYSTEM;
};


template<size_t LEVELS_NUM,
        size_t ROUTABLES_NUM,
        size_t ELEMENTS_NUM>
class handler_element :
    public handler<Work_system<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM>,handler_element<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM>>{
public:
    using HANDLER_BASE = handler<Work_system<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM>,handler_element>;
    using WORK_SYSTEM = typename HANDLER_BASE::WORK_SYSTEM;
    using LEVEL_SYSTEM = typename HANDLER_BASE::LEVEL_SYSTEM;

    handler_element():m_ws(nullptr){}
    handler_element(WORK_SYSTEM *ws, unsigned lvl_, unsigned element_id_absolute_):m_ws(ws),lvl(lvl_),element_id_absolute(element_id_absolute_){}
    ~handler_element(){m_ws=nullptr;}
    void call(){
        m_ws->try_push_element(lvl, element_id_absolute);
    }

private:
    WORK_SYSTEM *m_ws;
    unsigned lvl;
    unsigned element_id_absolute;

};

template<size_t LEVELS_NUM,
        size_t ROUTABLES_NUM,
        size_t ELEMENTS_NUM>
class handler_routable :
    public handler<Work_system<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM>,handler_routable<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM>>{
public:
    using HANDLER_BASE = handler<Work_system<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM>,handler_routable<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM>>;
    using WORK_SYSTEM = typename HANDLER_BASE::WORK_SYSTEM;
    using LEVEL_SYSTEM = typename HANDLER_BASE::LEVEL_SYSTEM;

    handler_routable():m_ws(nullptr){}
    handler_routable(WORK_SYSTEM *ws,unsigned lvl_, unsigned routable_id_absolute_):m_ws(ws),lvl(lvl_),routable_id_absolute(routable_id_absolute_){}
    ~handler_routable(){m_ws=nullptr;}
    void call(){
        m_ws->try_push_routable(lvl, routable_id_absolute);
    }

private:
    WORK_SYSTEM *m_ws;
    unsigned lvl;
    unsigned routable_id_absolute;

};

template<size_t LEVELS_NUM,
        size_t ROUTABLES_NUM,
        size_t ELEMENTS_NUM>
class handler_move :
    public handler<Work_system<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM>,handler_move<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM>>
    {
public:
    using HANDLER_BASE = handler<Work_system<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM>,handler_move<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM>>;
    using WORK_SYSTEM = typename HANDLER_BASE::WORK_SYSTEM;
    using LEVEL_SYSTEM = typename HANDLER_BASE::LEVEL_SYSTEM;

    handler_move():m_ws(nullptr){}
    /*
    (HANDLER_MOVE(ws,
                FIRST_MOVABLE+i,
                LEVEL_SYSTEM::get_lvl_id_by_element_id(absolute_id_iterator)

                LEVEL_SYSTEM::get_element_id_absolute(target_lvl,target_routable,target_element)
    */
    handler_move(WORK_SYSTEM *ws,unsigned element_id_absolute_,
                    unsigned lvl_):m_ws(ws),
                    element_id_absolute(element_id_absolute_),
                    lvl(lvl_)
                    {}
    ~handler_move(){m_ws=nullptr;}
    void move(unsigned target_lvl_,unsigned target_routable_,unsigned target_element_){
        target_lvl=target_lvl_;
        target_routable=target_routable_;
        target_element=target_element_;
        call();
    }

private:
    void call(){
        unsigned target_id_absolute = LEVEL_SYSTEM::get_element_absolute_id(target_lvl,target_routable,target_element);
        m_ws->try_push_move(lvl, element_id_absolute, target_id_absolute);
        //unsigned lvl, unsigned element_id_absolute, unsigned target_id_absolute
    }

private:
    WORK_SYSTEM *m_ws;
    unsigned element_id_absolute;
    unsigned lvl;

    unsigned target_lvl;
    unsigned target_routable;
    unsigned target_element;
};
/**/


#endif // HANDLER_HPP
