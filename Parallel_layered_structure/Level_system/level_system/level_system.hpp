#ifndef LEVEL_SYSTEM_HPP
#define LEVEL_SYSTEM_HPP
#include<layered_data.h>

#include<binary_tree.hpp>
#include<set>

/**/
template<size_t UP_NUM, size_t MIDDLE_NUM, size_t LOW_NUM, size_t MOVABLE_NUM, template<size_t,size_t,size_t,size_t>class Derived >
class Level_system{
public:
    using WORK_SYSTEM = Derived<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using ResultType = unsigned;
    using INTERVAL_SYSTEM = Interval_system<size_t,UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using LAYERED_DATA = Layered_data<INTERVAL_SYSTEM>;

    INTERVAL_SYSTEM *m_interval_system;
    LAYERED_DATA *m_layered_data;

    static void on_middle_change(unsigned lvl, unsigned routable_id_absolute){
        //qDebug()<<"on_routable_change()"<<" lvl " << lvl<< " routable_id_absolute "<<routable_id_absolute <<endl;
        WORK_SYSTEM::try_push_middle(lvl,routable_id_absolute);
    }

class Low_wrapper{
    public:
        Low_wrapper():m_low_data(nullptr)
                {
                    m_arrow_lower = new arrow();
                    m_arrow_upper=nullptr;
                    m_arrow_lower->set_owner(this);
                }
        class arrow
        {
        public:
            arrow(){
                    m_element_low = nullptr;
                    m_owner = nullptr;
                }
            ~arrow(){
                m_element_low = nullptr;
                m_owner = nullptr;
            }
            void set_owner(Low_wrapper *owner){
                m_owner = owner;
            }
            void set_arrow_to(Low_wrapper *element_){
                if(m_element_low!=nullptr){
                    m_element_low->remove_arrow_upper();
                }
                m_element_low = element_;

                m_element_low->set_arrow_upper(this);
            }
            void tickle(){
                if(m_owner){
                    m_owner->on_tickle();
                }
            }

            Low_wrapper *m_element_low;
            Low_wrapper *m_owner;
        };

        ~Low_wrapper(){
            if(m_arrow_lower){
                delete m_arrow_lower;
            }
            m_arrow_upper=nullptr;
            m_low_data=nullptr;
            //m_work_system=nullptr;
        }
        unsigned call(){

            if(m_arrow_upper){
                m_arrow_upper->tickle();
            }
            return get_sum();
        }

        void move_arrow(Low_wrapper *target){
            m_arrow_lower->set_arrow_to(target);
            on_middle_change(m_up_id,m_middle_id_absolute);
        }

        void init(Level_system *LS_, low_data *data, unsigned element_id_absolute,unsigned level_id,unsigned routable_id_absolute){
            LS=LS_;
            m_low_data=data;
            m_element_id_absolute = element_id_absolute;
            m_up_id=level_id;
            m_middle_id_absolute=routable_id_absolute;
        }

        void set_arrow_lower(Low_wrapper *element){
            m_arrow_lower->set_arrow_to(element);
        }
        void set_arrow_upper(arrow *arrow_){
            m_arrow_upper = arrow_;
        }
        void remove_arrow_upper(){
            m_arrow_upper=nullptr;
        }

        void on_tickle(){
            on_middle_change(m_up_id,m_middle_id_absolute);
        }
        arrow *get_arrow_owned(){
            return m_arrow_lower;
        }
        unsigned get_parent_routable()const{
            return m_middle_id_absolute;
        }

        void get_neighbours_recursive(std::set<unsigned> &touched_routables){
            unsigned routable_connected(0);
            if(m_arrow_upper){
                routable_connected=m_arrow_upper->m_owner->get_parent_routable();
                touched_routables.insert(routable_connected);
                qDebug()<<"routable_connected"<<routable_connected<<" size "<<touched_routables.size()<< endl;
                LS->get_neighbours_recursive(routable_connected,touched_routables);
            }
        }
        unsigned get_sum(){
            unsigned res(0);
            if(m_low_data){
                res = m_low_data->get_param();
            }
            return 1;
        }
        unsigned get_element_absolute_id(){
            return m_element_id_absolute;
        }
        static void reset_control_sum(){
            CONTROL_SUM=0;
        }
        static unsigned get_control_sum(){
            return CONTROL_SUM;
        }

    private:
        inline static unsigned CONTROL_SUM = 0;

        unsigned m_middle_id_absolute;
        unsigned m_up_id;
        unsigned m_element_id_absolute;

        arrow *m_arrow_upper;//стрелка-хозяин
        arrow *m_arrow_lower;
        low_data *m_low_data;
        Level_system *LS;
    };



class Middle_wrapper{
    public:
    unsigned call(){

        unsigned res = LS->call_elements(m_start_iterator,m_end_iterator);
        m_mid_data->call();
        return res;
    }
    Middle_wrapper(){}
    ~Middle_wrapper(){
        m_mid_data = nullptr;
        LS = nullptr;
    }
    void init(size_t const ABS_ID_,size_t const LVL_ID_, middle_data *mid,size_t start_iterator,size_t size,Level_system *LS_){
        m_absolute_id = ABS_ID_;
        m_lvl_id = LVL_ID_;
        m_mid_data=mid;
        m_start_iterator = start_iterator;
        m_end_iterator = start_iterator+size;
        LS=LS_;
    }
    unsigned get_sum(){
        qDebug()<<"Middle_wrapper get_sum"<<" abs "<<m_absolute_id<<" lvl "<<m_lvl_id<<" res "<< endl;
        //unsigned result=(LS->get_sum(m_start_iterator,m_end_iterator));

        return LS->get_sum(m_start_iterator,m_end_iterator);
    }
    unsigned m_absolute_id;
    unsigned m_lvl_id;
    size_t m_start_iterator;
    size_t m_end_iterator;
    private:
    middle_data *m_mid_data;
    Level_system *LS;
};



class Up_wrapper
{
public:
    Up_wrapper(){}
    ~Up_wrapper(){

        m_up_data= nullptr;
    }

    Up_wrapper& operator = (Up_wrapper const &other){
        m_id=other.LVL_ID;
        m_start_iterator = other.m_start_iterator;
        m_end_iterator = other.m_end_iterator;
        return *this;
    }

    void init(size_t const LVL_ID_, up_data *lvl,size_t start_iterator,size_t end_iterator){
        m_id = LVL_ID_;
        m_up_data = lvl;
        m_start_iterator = start_iterator;
        m_end_iterator = end_iterator;
    }

    unsigned m_id;
    size_t m_start_iterator;
    size_t m_end_iterator;
    up_data *m_up_data;
};



    Level_system(std::string const intervals_file_,
                std::string const data_file_):
                m_interval_system(new INTERVAL_SYSTEM),
                m_layered_data(new LAYERED_DATA){

        m_interval_system->init(intervals_file_);
        m_layered_data->init(data_file_);

        for (size_t i = 0; i < UP_NUM; i++) {
            std::pair<size_t,size_t> res = m_interval_system->get_interval_up(i);
            m_ups.at(i).init(i, m_layered_data->get_up_data(i), res.first, res.second);
        }
        qDebug()<< "m_ups() initialized " << endl;
        for (size_t i = 0; i < MIDDLE_NUM; i++) {
            std::pair<size_t,size_t> res = m_interval_system->get_interval_middle(i);
            qDebug()<< "m_middles() " << i<< " first "  << res.first <<" second "<<  res.second << endl;
            m_middles.at(i).init(i,
                                m_interval_system->get_up_id_by_middle(i),
                                m_layered_data->get_middle_data(i),
                                res.first,
                                res.second,
                                this);

        }
        qDebug()<< "m_middles() initialized " << endl;
        for (size_t i = 0; i < LOW_NUM; i++) {
            m_lows.at(i).init(this, m_layered_data->get_low_data(i),i,m_interval_system->get_up_id_by_low(i), m_interval_system->get_middle_id_by_low(i));
        }
        qDebug()<< "m_lows() initialized " << endl;
        qDebug()<< "Level_system() initialized " << endl;
    }

    ~Level_system(){
        qDebug()<< "~Level_system() " << endl;
    }

    unsigned get_sum_recursive(unsigned up,unsigned mid, unsigned low){
        size_t absolute_id = m_interval_system->get_low_id(up,mid,low);
        unsigned result=m_lows.at(absolute_id).get_sum();
        if(up<UP_NUM){
        std::set<unsigned> TR;

            //binarytree<unsigned> touched_routables;
            m_lows.at(absolute_id).get_neighbours_recursive(TR);
            while (TR.size()!=0){
                qDebug()<< "touched_routables.size() " << TR.size()<< endl;
                unsigned res = *TR.begin();
                TR.extract(TR.begin());

                //unsigned res = touched_routables.pop().second;
                result+=m_middles.at(res).get_sum();
            }
        }
        return result;
    }
    Middle_wrapper *get_middle_wrapper(size_t middle_id_absolute){
        return &m_middles.at(middle_id_absolute);
    }
    Low_wrapper *get_low_wrapper(size_t low_id_absolute){
        return &m_lows.at(low_id_absolute);
    }
    unsigned call_element(size_t element_id_absolute){
        return m_lows.at(element_id_absolute).call();
    }
    unsigned call_elements(size_t From, size_t To){
        unsigned res(0);
        for (size_t i=From;i<To;i++) {
            res+=m_lows.at(i).call();
        }
        // qDebug()<< "call_elements " << " From " << From << " To "<< To << " res " << res <<endl;
        return res;
    }
    unsigned call_middle(size_t middle_id_absolute){
        return m_middles.at(middle_id_absolute).call();
    }
    void call_move(size_t movable_id, size_t target_absolute_id){
        size_t low_index = m_movables.at(movable_id);
        Low_wrapper *w = &(m_lows.at(target_absolute_id));
        m_lows.at(low_index).move_arrow(w);
    }
    unsigned get_sum(size_t From,size_t To){
        unsigned res(0);
        for (size_t i=From;i<To;i++) {
            res+=m_lows.at(i).get_sum();
        }
        return res;
    }
    void get_neighbours_recursive(size_t routable_id, std::set<unsigned> &touched_routables){
        size_t From = m_middles.at(routable_id).m_start_iterator;
        size_t To = m_middles.at(routable_id).m_end_iterator;
        for (size_t i=From;i<To;i++) {
            m_lows.at(i).get_neighbours_recursive(touched_routables);
        }
    }
    void init_arrow(unsigned element_id_source, unsigned element_id_target){
        Low_wrapper *w = &(m_lows.at(element_id_target));
        m_lows.at(element_id_source).set_arrow_to(w);
    }

    INTERVAL_SYSTEM *get_interval_system(){
        return m_interval_system;
    }
    void set_connection(unsigned up_id,unsigned mid_id,unsigned low_id,
                    unsigned target_up_id,unsigned target_mid_id,unsigned target_low_id){
          size_t movable = m_interval_system->get_low_id(up_id,mid_id,low_id);
          size_t movable_target = m_interval_system->get_low_id(target_up_id,target_mid_id,target_low_id);
          Low_wrapper *w = &m_lows.at(movable_target);
          m_lows.at(movable).set_arrow_lower(w);
    }
    std::array<Low_wrapper,LOW_NUM> m_lows;
    std::array<size_t,MOVABLE_NUM> m_movables;
    std::array<Middle_wrapper,MIDDLE_NUM> m_middles;
    std::array<Up_wrapper,UP_NUM> m_ups;
};

#endif // LEVEL_SYSTEM_HPP


















