#ifndef HANDLER_SYSTEM_HPP
#define HANDLER_SYSTEM_HPP
#include<QColor>
#include<handler_wrapper.hpp>


template<typename... Args>
class handler_system;

template<size_t UP_NUM,
        size_t MIDDLE_NUM,
        size_t LOW_NUM,
        size_t MOVABLE_NUM>
class handler_system<Work_system<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>>{
public:
    using HANDLER = handler<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using WORK_SYSTEM = Work_system<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using LEVEL_SYSTEM = typename WORK_SYSTEM::LEVEL_SYSTEM;
    using INTERVAL_SYSTEM = typename LEVEL_SYSTEM::INTERVAL_SYSTEM;
    using HANDLER_MOVE = handler_move<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using HANDLER_MOVE_X = handler_move_x<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using HANDLER_MOVE_Y = handler_move_y<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using HANDLER_LOW = handler_low<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using HANDLER_MIDDLE = handler_middle<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using movable_field_data = typename HANDLER_MOVE::movable_field_data;
    using middle_2d_interval = typename INTERVAL_SYSTEM::middle_2d_interval;
    using HANDLER_WRAPPER = handler_wrapper<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using MOVABLE_HANDLER_WRAPPER = movable_handler_wrapper<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using CALLABLE_HANDLER_WRAPPER = callable_handler_wrapper<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    //get_routable_id_by_element_id

handler_system(WORK_SYSTEM *ws,
                std::string const connections_file_){
    qDebug()<< "handler_system() " << endl;
    INTERVAL_SYSTEM *m_interval_system = ws->get_interval_system();
    LEVEL_SYSTEM *m_level_system = ws->get_level_system();
    std::ifstream file = std::ifstream(connections_file_);
        if (!file.good()) {
            qDebug()<<connections_file_.data()<< "not found!"<< endl;
            throw std::exception();
        }
        unsigned up_id(0);
        unsigned mid_id(0);
        unsigned mid_id_previous(1);//чтобы при первой итерации условие сработало
        unsigned up_id_previous(1);//чтобы при первой итерации условие сработало
        unsigned low_id(0);
        unsigned movable_iter(0);

        unsigned middle_id_iterator(0);

        unsigned target_up_id(0);
        unsigned target_mid_id(0);
        unsigned target_low_id(0);

        std::string string_iter;
        while(!(file.eof()||movable_iter>=MOVABLE_NUM)){
            getline(file,string_iter, ' ');
            if(string_iter =="nc"){
                file>>up_id;
                if(up_id_previous!=up_id){
                    up_id_previous=up_id;
                    HANDLER_WRAPPER *w = new CALLABLE_HANDLER_WRAPPER(up_id);
                    m_tree->add_child(up_id,w);
                }
                file>>mid_id;
                if(mid_id_previous!=mid_id){
                    mid_id_previous=mid_id;
                    middle_id_iterator++;
                    HANDLER *handler = static_cast<HANDLER*>(new HANDLER_MIDDLE(ws,
                                        up_id,
                                        middle_id_iterator));
                    HANDLER_WRAPPER *w = new CALLABLE_HANDLER_WRAPPER(mid_id,handler);
                    m_tree->add_child(up_id,mid_id,w);
                }
                file>>low_id;
                HANDLER *handler = new HANDLER_LOW(ws,
                                        up_id,
                                        middle_id_iterator);
                HANDLER_WRAPPER *w = new CALLABLE_HANDLER_WRAPPER(low_id,handler);
                m_tree->add_child(up_id,mid_id,low_id,w);
            }
            else if(string_iter =="c"){
                file>>up_id;
                file>>mid_id;
                if(mid_id_previous!=mid_id){
                    mid_id_previous=mid_id;
                    middle_id_iterator++;
                }
                file>>low_id;
                file>>target_up_id;
                file>>target_mid_id;
                file>>target_low_id;

                m_level_system->set_connection(up_id, mid_id, low_id,target_up_id, target_mid_id, target_low_id);
                HANDLER *handler = new HANDLER_LOW(ws,
                                        up_id,
                                        middle_id_iterator);
                HANDLER_MOVE_X *handler_x = new HANDLER_MOVE_X(ws,
                                        up_id,
                                        middle_id_iterator);
                HANDLER_MOVE_Y *handler_y = new HANDLER_MOVE_Y(ws,
                                        up_id,
                                        middle_id_iterator);

                middle_2d_interval interval_data;
                if(m_interval_system->try_get_movable(middle_id_iterator,movable_iter,interval_data)){
                    movable_field_data *field = new movable_field_data(m_interval_system->get_width_for(middle_id_iterator),
                                                    interval_data.radius_x,
                                                    interval_data.radius_y,
                                                    interval_data.x,
                                                    interval_data.y,
                                                    m_interval_system->get_low_id(middle_id_iterator,0));
                    HANDLER_WRAPPER *w = new MOVABLE_HANDLER_WRAPPER(low_id,handler,handler_x,handler_y,field);
                    m_tree->add_child(up_id,mid_id,low_id,w);
                    movable_iter++;
                }
                getline(file,string_iter);
            }
        }
}
~handler_system(){
    if(m_tree){
        delete m_tree;
    }
}

private:

HANDLER_WRAPPER *m_tree;

};

#endif // HANDLER_SYSTEM_HPP
