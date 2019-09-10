#ifndef LEVEL_SYSTEM_HPP
#define LEVEL_SYSTEM_HPP
#include<binary_tree.hpp>
#include <iostream>
#include <fstream>
#include<sstream>
#include<memory>
#include<set>
#include<element_types.hpp>
#include<routable_types.hpp>
#include<level_types.hpp>




template<size_t LEVELS_NUM, size_t ROUTABLES_NUM, size_t ELEMENTS_NUM, template<size_t,size_t,size_t>class Derived >
class Level_system{
public:
    using WORK_SYSTEM = Derived<LEVELS_NUM,ROUTABLES_NUM,ELEMENTS_NUM>;
    using ResultType = unsigned;

    static void on_routable_change(unsigned lvl, unsigned routable_id_absolute){
        //qDebug()<<"on_routable_change()"<<" lvl " << lvl<< " routable_id_absolute "<<routable_id_absolute <<endl;
        WORK_SYSTEM::try_push_routable(lvl,routable_id_absolute);
    }

class Low_wrapper{
    public:
        Low_wrapper():m_element(nullptr)
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
            if(m_element){
                delete m_element;
            }
            m_arrow_upper=nullptr;
            //m_work_system=nullptr;
        }
        unsigned call(){

            if(m_arrow_upper){
                m_arrow_upper->tickle();
            }
            return get_sum();
        }

        void move_arrow(unsigned element_id_absolute){
            Low_wrapper *res = &(m_elements.at(element_id_absolute));
            m_arrow_lower->set_arrow_to(res);
            on_routable_change(m_level_id,m_routable_id_absolute);
        }

        void init(unsigned element_id_absolute,unsigned TYPE_ID_, unsigned PARAM){
            m_element_id_absolute = element_id_absolute;
            if(TYPE_ID_ == 0){
                m_element = static_cast<low_data*>(new low_data_t1(PARAM));
            }else {
                m_element = static_cast<low_data*>(new low_data_t2(PARAM));
            }
        }
        void set_level_id(unsigned level_id){
            m_level_id = level_id;
        }
        void set_routable_id_absolute(unsigned routable_id_absolute){
            m_routable_id_absolute = routable_id_absolute;
        }
        void init_arrow(unsigned target_id_absolute){
            Low_wrapper *element_ = &(m_elements.at(target_id_absolute));
            m_arrow_lower->set_arrow_to(element_);
        }
        void set_arrow_upper(arrow *arrow_){
            m_arrow_upper = arrow_;
        }
        void remove_arrow_upper(){
            m_arrow_upper=nullptr;
        }

        void on_tickle(){
            on_routable_change(m_level_id,m_routable_id_absolute);
        }
        arrow *get_arrow_owned(){
            return m_arrow_lower;
        }
        unsigned get_parent_routable()const{
            return m_routable_id_absolute;
        }
        unsigned get_sum(){
            unsigned res(0);
            if(m_element){
                res = m_element->get_param();
                qDebug()<<"call()_element"<<m_element_id_absolute<<endl;
            }else{
                qDebug()<<"NO_ELEMENT .............................."<<m_element_id_absolute<<endl;
            }
            return res;
        }
        void get_neighbours_recursive(binarytree<unsigned> &touched_routables){
            unsigned routable_connected(0);
            if(m_arrow_upper){                
                routable_connected=m_arrow_upper->m_owner->get_parent_routable();                
                if(touched_routables.insert_unique(routable_connected,routable_connected)){
                    qDebug()<<"routable_connected"<<routable_connected<<endl;
                    m_routables.at(routable_connected).get_neighbours_recursive(touched_routables);
                }
            }
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

        unsigned m_routable_id_absolute;
        unsigned m_level_id;
        unsigned m_element_id_absolute;

        arrow *m_arrow_upper;//стрелка-хозяин
        arrow *m_arrow_lower;
        low_data *m_element;
    };

    template<typename T, size_t SIZE_T>
    static constexpr std::array<T,SIZE_T> get_array(){
        std::array<T,SIZE_T> result;
        for (size_t i=0;i<SIZE_T;i++) {
            unsigned id = static_cast<unsigned>(i);
            result.at(i)=T(id);
        }
        return result;
    }

    inline static std::array<Low_wrapper,ELEMENTS_NUM> m_elements = {};

class Middle_wrapper{
    public:
    unsigned call(){
        unsigned res(0);
        for (size_t i = m_start_iterator;i<m_end_iterator;i++){
            res+=m_elements.at(i).call();
        }
        m_routable->call();
        return res;
    }
    Middle_wrapper(){}
    ~Middle_wrapper(){
        if(m_routable){
            delete m_routable;
        }
    }
    void init(unsigned const absolute_id,
                    unsigned const START,
                    unsigned const WIDTH_,
                    unsigned const HEIGHT_,
                    unsigned const TYPE_ID_){
                    m_absolute_id = absolute_id;
        m_start_iterator=START;
        m_end_iterator=m_start_iterator+(WIDTH_*HEIGHT_);
        if(TYPE_ID_ == 0){
            m_routable = static_cast<middle_data*>(new middle_data_t1(WIDTH_,HEIGHT_));
        }else {
            m_routable = static_cast<middle_data*>(new middle_data_t2(WIDTH_,HEIGHT_));
        }

    }
    unsigned get_element_absolute_id(unsigned element_id){
        return m_elements.at(m_start_iterator+element_id).get_element_absolute_id();
    }
    unsigned get_sum(){
        unsigned result(0);
        for (size_t i = m_start_iterator;i<m_end_iterator;++i) {
            result+=m_elements.at(i).get_sum();
        }
        return result;
    }
    void get_neighbours_recursive(binarytree<unsigned> &touched_routables){
        size_t iter = m_start_iterator;
        while (iter!=m_end_iterator) {
            m_elements.at(iter).get_neighbours_recursive(touched_routables);
            iter++;
        }
    }
    static std::shared_ptr<Low_wrapper> get_element(unsigned element_id){
            return std::make_shared<Low_wrapper>(m_elements.at(element_id));
    }
    void set_parent_lvl(unsigned lvl){
        m_lvl_id = lvl;
    }
    unsigned get_parant_lvl_id(){
        return m_lvl_id;
    }

    unsigned m_absolute_id;
    unsigned m_lvl_id;
    size_t m_start_iterator;
    size_t m_end_iterator;
    private:
    middle_data *m_routable;
};
inline static std::array<Middle_wrapper,ROUTABLES_NUM> m_routables  = {};

class Up_wrapper
{
    public:
    Up_wrapper(){

    }

    Up_wrapper(Up_wrapper const &other):
                            m_id(other.m_id),
                            m_start_iterator(other.m_start_iterator),
                            m_end_iterator(other.m_end_iterator)
                            {}
    ~Up_wrapper(){
        if (m_level) {
            delete m_level;
        }
    }

    Up_wrapper& operator = (Up_wrapper const &other){
        m_id=other.LVL_ID;
        m_start_iterator = other.m_start_iterator;
        m_end_iterator = other.m_end_iterator;
        return *this;
    }

    void init(unsigned const LVL_ID_,const unsigned TYPE_ID_, const unsigned PARAM){
        m_id = LVL_ID_;
        if(TYPE_ID_ == 0){
            m_level = static_cast<up_data*>(new up_data_t1(PARAM));
        }else {
            m_level = static_cast<up_data*>(new up_data_t2(PARAM));
        }
    }
    static std::shared_ptr<Low_wrapper> get_element(unsigned routable_id, unsigned element_id){
            return (m_routables.at(routable_id).get_element(element_id));
    }
    void init_level_borders(unsigned start, unsigned end){
        m_start_iterator = static_cast<size_t>(start);
        m_end_iterator = static_cast<size_t>(end);
        for (size_t i = start;i<end;i++) {
            m_routables.at(i).set_parent_lvl(static_cast<unsigned>(i));
        }
    }
    void init_arrow(unsigned wrapper_id, unsigned element_id,std::shared_ptr<Low_wrapper>element_){
        if((m_start_iterator+wrapper_id)<m_end_iterator){
            m_routables.at(m_start_iterator+wrapper_id).init_arrow(element_id, element_);
        }
    }
    unsigned get_size()const{
        return m_end_iterator-m_start_iterator;
    }
    std::shared_ptr<Middle_wrapper> get_worker(unsigned wrapper_id){
        std::shared_ptr<Middle_wrapper> result;
        if((m_start_iterator+wrapper_id)<m_end_iterator){
            result = std::make_shared<Middle_wrapper>(m_routables.at(m_start_iterator+wrapper_id));
        }
        return result;
    }

    unsigned get_element_absolute_id(unsigned wrapper_id, unsigned element_id){
        return m_routables.at(m_start_iterator+wrapper_id).get_element_absolute_id(element_id);
    }

    unsigned get_sum(unsigned wrapper_id){
        unsigned res(0);
        if((m_start_iterator+wrapper_id)<m_end_iterator){
            res=m_routables.at(m_start_iterator+wrapper_id).get_sum();
        }
        return res;
    }

    unsigned m_id;
    size_t m_start_iterator;
    size_t m_end_iterator;
    up_data *m_level;
};

inline static std::array<Up_wrapper,LEVELS_NUM> m_levels = {};

    unsigned get_control_sum(unsigned lvl, unsigned routable_id,unsigned element_id){
        return m_levels.at(lvl).get_control_sum(routable_id,element_id);
    }



    Level_system(std::string const levels_file_,
                std::string const elements_file_,
                std::string const connections_file_){
                qDebug()<< "Level_system() " << endl;
        init_levels(levels_file_);
        init_elements(elements_file_);
        init_connections(connections_file_);
        qDebug()<< "Level_system() initialized " << endl;
    }

    ~Level_system(){
        qDebug()<< "~Level_system() " << endl;
    }

    static unsigned get_element_absolute_id(
                        unsigned target_lvl,
                        unsigned target_routable,
                        unsigned target_element){
        return m_levels.at(target_lvl).get_element_absolute_id(target_routable,target_element);
    }
    static void init_levels(std::string const levels_file_){
        qDebug()<< "init_levels()"<< endl;
        std::ifstream file = std::ifstream(levels_file_);
        if (!file.good()) {
            qDebug()<<levels_file_.data()<< "not found!"<< endl;
            throw std::exception();
        }
        unsigned level_id(0);
        unsigned level_type(0);
        unsigned level_param(0);
        unsigned routable_type(0);
        unsigned routable_width(0);
        unsigned routable_height(0);
        unsigned level_start_iterator(0);
        unsigned level_end_iterator(0);
        unsigned routable_start_iterator(0);
        unsigned routable_end_iterator(0);
        unsigned routable_id_absolute(0);
        std::string string_iter;
        while(!file.eof()){
            getline(file,string_iter,' ');
            if(string_iter == "lvl"){                
                level_start_iterator=level_end_iterator;
                file>>level_id;
                file>>level_type;
                file>>level_param;
                m_levels.at(level_id).init(level_id,level_type,level_param);
                getline(file,string_iter);
            }else if (string_iter == "b") {
                if(level_end_iterator!=0){
                    m_levels.at(level_id).init_level_borders(level_start_iterator,level_end_iterator);
                    getline(file,string_iter);
                }
            }else if (string_iter == "r") {
                level_end_iterator++;
                if(routable_end_iterator!=0){
                    m_levels.at(level_id).init_level_borders(level_start_iterator,level_end_iterator);
                }
                file>>routable_type;
                file>>routable_width;
                file>>routable_height;
                routable_start_iterator=routable_end_iterator;
                routable_end_iterator+=(routable_width*routable_height);
                m_routables.at(routable_id_absolute).init(routable_id_absolute,routable_start_iterator,routable_width,routable_height,routable_type);
                routable_id_absolute++;
                getline(file,string_iter);
            }
            qDebug()<< "lvl"<<level_id
                    << "lt"<<level_type
                    << "rt "<< routable_type
                    << "rw "<< routable_width
                    << "rh "<< routable_height << endl;
        }
    }
    static void init_elements(std::string const elements_file){
        qDebug()<< "init_elements()"<< endl;
        std::ifstream file = std::ifstream(elements_file);
        if (!file.good()) {
            qDebug()<<elements_file.data()<< "not found!"<< endl;
            throw std::exception();
        }
        unsigned element_id_absolute(0);
        unsigned element_type(0);
        unsigned param(0);
        std::string string_iter;
        while(!file.eof()){
            getline(file,string_iter,' ');
            if(string_iter == "e"){
                file>>element_type;
                file>>param;
                qDebug()<< "et "<< element_type
                        << "p "<< param << endl;
                m_elements.at(element_id_absolute).init(element_id_absolute,element_type,element_id_absolute);
                element_id_absolute++;
            }
            getline(file,string_iter);
        }
    }
    static void init_connections(std::string const connections_file){
        qDebug()<< "init_connections()"<< endl;
        std::ifstream file = std::ifstream(connections_file);
        if (!file.good()) {
            qDebug()<<connections_file.data()<< "not found!"<< endl;
            throw std::exception();
        }
        unsigned level_id(0);
        unsigned routable_id(0);
        unsigned routable_id_previous(0);
        unsigned element_id(0);
        unsigned target_level_id(0);
        unsigned target_routable_id(0);
        unsigned target_element_id(0);
        unsigned element_id_absolute(0);
        unsigned target_id_absolute(0);
        unsigned routable_id_absolute(0);


        std::string string_iter;
        while(!file.eof()){
        getline(file,string_iter, ' ');
            if(string_iter =="c"){
            qDebug()<< "lvl"<<level_id
                        << "r "<< routable_id
                        << "e "<< element_id
                        << "tl "<< target_level_id
                        << "tr "<< target_routable_id
                        << "te "<< target_element_id << endl;
                file>>level_id;
                file>>routable_id;
                file>>element_id;
                file>>target_level_id;
                file>>target_routable_id;
                file>>target_element_id;
                m_elements.at(element_id_absolute).set_level_id(level_id);
                if(routable_id!=routable_id_previous){
                    routable_id_previous = routable_id;
                    routable_id_absolute++;
                }
                m_elements.at(element_id_absolute).set_routable_id_absolute(routable_id_absolute);
                if(level_id!=0){
                        target_id_absolute = get_element_absolute_id(target_level_id,target_routable_id,target_element_id);
                        qDebug()<< "target_id_absolute"<<target_id_absolute<<endl;
                        qDebug()<< "element_id_absolute"<<element_id_absolute<<endl;
                        m_elements.at(element_id_absolute).init_arrow(target_id_absolute);
                }
                getline(file,string_iter);
                element_id_absolute++;
            }
        }
    }


    static unsigned get_sum_recursive(unsigned lvl,unsigned routable, unsigned element){
        unsigned absolute_id = get_element_absolute_id(lvl,routable,element);
        unsigned result=m_elements.at(absolute_id).get_sum();
        if(lvl<LEVELS_NUM){
            binarytree<unsigned> touched_routables;
            m_elements.at(absolute_id).get_neighbours_recursive(touched_routables);
            while (touched_routables.size()!=0){
                unsigned res = touched_routables.pop().second;
                result+=m_routables.at(res).get_sum();
                qDebug()<< "result "<<result<<" += "<<m_routables.at(res).get_sum()<<endl;
                qDebug()<< "touched_routables.size()"<<touched_routables.size()<<endl;
            }
        }
        return result;
    }



    static unsigned call_element(unsigned element_id_absolute){
        return m_elements.at(element_id_absolute).call();
    }
    static unsigned call_middle(unsigned routable_id_absolute){
        return m_routables.at(routable_id_absolute).call();
    }
    static void call_move(unsigned element_id_absolute,unsigned target_absolute_id){
        m_elements.at(element_id_absolute).move_arrow(target_absolute_id);
    }

    static constexpr unsigned get_routable_id_by_element_id(unsigned element_id_absolute){
        return m_elements.at(element_id_absolute).get_parent_routable();
    }
    static constexpr unsigned get_lvl_id_by_routable_id(unsigned routable_id_absolute){
        return m_routables.at(routable_id_absolute).get_parant_lvl_id();
    }
    static constexpr unsigned get_lvl_id_by_element_id(unsigned element_id_absolute){
        size_t routable_id = static_cast<unsigned>(m_elements.at(element_id_absolute).get_parent_routable());
        return m_routables.at(routable_id).get_parant_lvl_id();
    }
    static constexpr unsigned get_first_movable(){
        qDebug()<< "get_first_movable() " << endl;
        size_t routable_id = m_levels.at(1).m_start_iterator;
        size_t element_id = m_routables.at(routable_id).m_start_iterator;
        qDebug()<< "routable_id " <<routable_id << " element_id " <<element_id<<endl;
        return static_cast<unsigned>(element_id);
    }
};


#endif // LEVEL_SYSTEM_HPP


