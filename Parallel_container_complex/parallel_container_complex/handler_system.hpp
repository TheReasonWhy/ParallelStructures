#ifndef HANDLER_SYSTEM_HPP
#define HANDLER_SYSTEM_HPP
#include<handler.hpp>

template<typename... Args>
class handler_system;

template<size_t LEVELS_NUM,
        size_t ROUTABLES_NUM,
        size_t ELEMENTS_NUM>
class handler_system<Work_system<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM>>{
public:
    using WORK_SYSTEM = Work_system<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM>;
    using LEVEL_SYSTEM = typename WORK_SYSTEM::LEVEL_SYSTEM;
    using HANDLER_MOVE = handler_move_x<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM>;
    using HANDLER_ELEMENT = handler_element<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM>;
    using HANDLER_ROUTABLE = handler_routable<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM>;

    //get_routable_id_by_element_id
handler_system(WORK_SYSTEM *ws):
    FIRST_MOVABLE(LEVEL_SYSTEM::get_first_movable()),
    MOVABLE_SIZE(ELEMENTS_NUM-FIRST_MOVABLE){
    qDebug()<< "handler_system() " << endl;
    unsigned absolute_id_iterator(0);
    for (size_t i = 0;i<MOVABLE_SIZE;++i) {
        m_move_handlers.push_back(HANDLER_MOVE(ws,
                                                FIRST_MOVABLE+i,
                                                LEVEL_SYSTEM::get_lvl_id_by_element_id(absolute_id_iterator)));
    }
    for (size_t i = 0;i<ELEMENTS_NUM;++i) {
        m_element_handlers.at(i) = HANDLER_ELEMENT(ws,
                                LEVEL_SYSTEM::get_lvl_id_by_element_id(absolute_id_iterator),
                                absolute_id_iterator);
        absolute_id_iterator++;
    }
    absolute_id_iterator=0;
    for (size_t i = 0;i<ROUTABLES_NUM;++i) {
        m_routable_handlers.at(i) = HANDLER_ROUTABLE(ws,
                                    LEVEL_SYSTEM::get_lvl_id_by_routable_id(absolute_id_iterator),
                                    absolute_id_iterator);
    }


}

void move(unsigned element_id_absoltute,unsigned target_lvl,unsigned target_routable,unsigned target_element){
    m_move_handlers.at(element_id_absoltute-FIRST_MOVABLE).move(target_lvl,target_routable,target_element);
}
void call_element(unsigned element_id_absoltute){
    qDebug()<< "handler_system() call_element " <<element_id_absoltute<< endl;
    m_element_handlers.at(element_id_absoltute).call();
}
void call_routable(unsigned routable_id_absoltute){
    m_routable_handlers.at(routable_id_absoltute).call();
}

private:

const unsigned FIRST_MOVABLE;
const unsigned MOVABLE_SIZE;

std::vector<HANDLER_MOVE> m_move_handlers;
std::array<HANDLER_ELEMENT,ELEMENTS_NUM> m_element_handlers;
std::array<HANDLER_ROUTABLE,ROUTABLES_NUM> m_routable_handlers;

};

#endif // HANDLER_SYSTEM_HPP
