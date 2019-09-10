#ifndef HANDLER_SYSTEM_HPP
#define HANDLER_SYSTEM_HPP
#include<handler.hpp>

template<typename... Args>
class handler_system;

template<size_t UP_NUM,
        size_t MIDDLE_NUM,
        size_t LOW_NUM,
        size_t MOVABLE_NUM>
class handler_system<Work_system<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>>{
public:
    using WORK_SYSTEM = Work_system<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using LEVEL_SYSTEM = typename WORK_SYSTEM::LEVEL_SYSTEM;
    using INTERVAL_SYSTEM = typename LEVEL_SYSTEM::INTERVAL_SYSTEM;
    using HANDLER_MOVE = handler_move<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using HANDLER_LOW = handler_low<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using HANDLER_MIDDLE = handler_middle<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;

    //get_routable_id_by_element_id
handler_system(WORK_SYSTEM *ws){
    qDebug()<< "handler_system() " << endl;
    INTERVAL_SYSTEM *m_interval_system = ws->get_interval_system();

    size_t absolute_id_iterator(0);
    for (size_t i = 0;i<MOVABLE_NUM;++i) {
        m_move_handlers.at(i) = HANDLER_MOVE(ws,i);
    }
    /*
    handler_move(WORK_SYSTEM *ws,
                size_t lvl_,
                size_t movable_id_,
                size_t target_id_absolute_)
    */
    for (size_t i = 0;i<LOW_NUM;++i) {
        m_low_handlers.at(i) = HANDLER_LOW(ws,
                                LEVEL_SYSTEM::get_lvl_id_by_element_id(absolute_id_iterator),
                                absolute_id_iterator);
        absolute_id_iterator++;
    }
    absolute_id_iterator=0;
    for (size_t i = 0;i<MIDDLE_NUM;++i) {
        m_middle_handlers.at(i) = HANDLER_MIDDLE(ws,
                                    LEVEL_SYSTEM::get_lvl_id_by_routable_id(absolute_id_iterator),
                                    absolute_id_iterator);
    }


}

void move(unsigned element_id_absoltute,unsigned target_lvl,unsigned target_routable,unsigned target_element){
    m_move_handlers.at(element_id_absoltute-FIRST_MOVABLE).move(target_lvl,target_routable,target_element);
}
void call_element(unsigned element_id_absoltute){
    qDebug()<< "handler_system() call_element " <<element_id_absoltute<< endl;
    m_low_handlers.at(element_id_absoltute).call();
}
void call_routable(unsigned routable_id_absoltute){
    m_middle_handlers.at(routable_id_absoltute).call();
}

private:
std::array<HANDLER_MOVE,MOVABLE_NUM> m_move_handlers;
std::array<HANDLER_LOW,LOW_NUM> m_low_handlers;
std::array<HANDLER_MIDDLE,MIDDLE_NUM> m_middle_handlers;

};

#endif // HANDLER_SYSTEM_HPP
