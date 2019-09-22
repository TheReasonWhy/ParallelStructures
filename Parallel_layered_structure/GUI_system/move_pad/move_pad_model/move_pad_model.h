#ifndef MOVE_PAD_MODEL_H
#define MOVE_PAD_MODEL_H
#include<QAbstractTableModel>
#include<handler_system.hpp>


template<size_t UP_NUM,
        size_t MIDDLE_NUM,
        size_t LOW_NUM,
        size_t MOVABLE_NUM>
class Move_pad_model : public QAbstractTableModel
{

public:
    using Work_system = Work_system<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using HS = handler_system<Work_system>;
    using move_handler_wrapper = typename HS::move_handler_wrapper;
    Move_pad_model(HS *handlers):m_movables(handlers->get_movables()){

    }
    ~Move_pad_model(){
        if(m_movables){
            delete m_movables;
        }
    }

private:
    std::array<move_handler_wrapper,MOVABLE_NUM> *m_movables;
};

#endif // MOVE_PAD_MODEL_H
