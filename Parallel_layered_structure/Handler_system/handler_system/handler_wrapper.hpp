#ifndef HANDLER_WRAPPER_HPP
#define HANDLER_WRAPPER_HPP
#include<handler.hpp>

template<size_t UP_NUM,
        size_t MIDDLE_NUM,
        size_t LOW_NUM,
        size_t MOVABLE_NUM>
class handler_wrapper{
public:
using HANDLER = handler<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
using HANDLER_MOVE = handler_move<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
using movable_field_data = typename HANDLER_MOVE::movable_field_data;
    handler_wrapper(unsigned row):m_row(row),m_selected(false),m_added(false){

    }
    virtual ~handler_wrapper(){}
    virtual unsigned row(){return m_row;}
    virtual unsigned children_num(){
        return m_children.size();
    }

    virtual void add_child(unsigned up_id, unsigned mid_id, unsigned row, handler_wrapper *h_wrapper)override{
        m_children.at(up_id).add_child(mid_id,row,h_wrapper);
    }
    virtual void add_child(unsigned mid_id, unsigned row, handler_wrapper *h_wrapper)override{
        m_children.at(mid_id).add_child(row,h_wrapper);
    }
    virtual void add_child(unsigned row, handler_wrapper *h_wrapper)override{
        m_children.push_back(HANDLER_WRAPPER(row,h_wrapper));
    }
    void select(){
        m_selected = true;
    }
    void add(){
        m_added = true;
    }
    unsigned m_row;
    bool m_selected;
    bool m_added;
    std::vector<handler_wrapper> m_children;
private:
};

template<size_t UP_NUM,
        size_t MIDDLE_NUM,
        size_t LOW_NUM,
        size_t MOVABLE_NUM>
class callable_handler_wrapper : public handler_wrapper<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>{
public:
    using HANDLER_WRAPPER = handler_wrapper<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using HANDLER = typename HANDLER_WRAPPER::HANDLER;
    callable_handler_wrapper(unsigned row):HANDLER_WRAPPER(row),
                                        m_handler(nullptr){}
    callable_handler_wrapper(unsigned row, HANDLER *handler):
                                                    HANDLER_WRAPPER(row),
                                                    m_handler(handler){}
    ~callable_handler_wrapper(){
        if(m_handler){
            delete m_handler;
        }
    }
    std::vector<HANDLER_WRAPPER> m_children;
    HANDLER *m_handler;
private:
};

template<size_t UP_NUM,
        size_t MIDDLE_NUM,
        size_t LOW_NUM,
        size_t MOVABLE_NUM>
class movable_handler_wrapper : public handler_wrapper<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>{
public:
    using HANDLER_WRAPPER = handler_wrapper<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using HANDLER = typename HANDLER_WRAPPER::HANDLER;

    using HANDLER_MOVE_X = handler_move_x<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using HANDLER_MOVE_Y = handler_move_y<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using movable_field_data = typename HANDLER_WRAPPER::movable_field_data;
movable_handler_wrapper(unsigned row,
                        HANDLER *handler,
                        HANDLER_MOVE_X *move_x_handler,
                        HANDLER_MOVE_Y *move_y_handler,
                        movable_field_data *field):
                                                    HANDLER_WRAPPER(row),
                                                    m_handler(handler),
                                                    x_handler(move_x_handler),
                                                    y_handler(move_y_handler),
                                                    m_field(field)
    {
        x_handler->set_field(m_field);
        y_handler->set_field(m_field);
    }


    HANDLER *m_handler;
    HANDLER_MOVE_X *x_handler;
    HANDLER_MOVE_Y *y_handler;
    movable_field_data *m_field;
private:
};
#endif // HANDLER_WRAPPER_HPP
