#ifndef USER_SYSTEM_HPP
#define USER_SYSTEM_HPP
#include<handler_system.hpp>

template<typename... Args>
class user_system;

template<size_t UP_NUM,
        size_t MIDDLE_NUM,
        size_t LOW_NUM,
        size_t MOVABLE_NUM>
class user_system<Work_system<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>>{
public:
using WORK_SYSTEM = Work_system<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
using HANDLER_SYSTEM = handler_system<WORK_SYSTEM>;
    inline static unsigned TICKS_TO_QUIT = 0;
    inline static unsigned COUNTER = 0;
    struct move_action{
    move_action(unsigned A,unsigned B,unsigned C,unsigned D):
                absolute_id(A),
                target_lvl(B),
                target_routable(C),
                target_absolute_id(D){}
        unsigned absolute_id;

        unsigned target_lvl;
        unsigned target_routable;
        unsigned target_absolute_id;

    };
    struct element_action{
        element_action(unsigned A):
                absolute_id(A){}
        unsigned absolute_id;
    };
    struct routable_action{
        routable_action(unsigned A):
                absolute_id(A){}
        unsigned absolute_id;
    };
    HANDLER_SYSTEM *hs;
    std::vector<move_action> m_move_actions;
    std::vector<element_action> m_element_actions;
    std::vector<routable_action> m_routable_actions;
    bool m_quit;

    user_system(WORK_SYSTEM *ws):hs(new HANDLER_SYSTEM(ws)),m_quit(false){
        qDebug()<< "user_system() " << endl;
    }
    ~user_system(){
        if(hs){
            delete hs;
        }
    }
    void add_move_action(unsigned absolute_id,unsigned target_lvl,unsigned target_routable,unsigned target_absolute_id){
        move_action m(absolute_id,target_lvl,target_routable,target_absolute_id);
        m_move_actions.push_back(m);
        TICKS_TO_QUIT++;
    }
    void add_element_action(unsigned absolute_id){
        element_action m(absolute_id);
        m_element_actions.push_back(m);
        TICKS_TO_QUIT++;
    }
    void add_routable_action(unsigned absolute_id){
        routable_action m(absolute_id);
        m_routable_actions.push_back(m);
        TICKS_TO_QUIT++;
    }
    static bool counter_to_quit(){
        if(COUNTER==TICKS_TO_QUIT){
            return true;
        }
        COUNTER++;
        return false;
    }
    bool process(){
        if(counter_to_quit()){
            return false;
        }
        while(!m_move_actions.empty()){
            move_action m = (m_move_actions.back());
            m_move_actions.pop_back();
            hs->move(m.absolute_id,m.target_lvl,m.target_routable,m.target_absolute_id);
        }
        while(!m_element_actions.empty()){
            element_action m = (m_element_actions.back());
            m_element_actions.pop_back();
            hs->call_element(m.absolute_id);
        }
        while(!m_routable_actions.empty()){
            routable_action m = (m_routable_actions.back());
            m_routable_actions.pop_back();
            hs->call_routable(m.absolute_id);
        }
        return true;
    }
private:

};
#endif // USER_SYSTEM_HPP
