#ifndef INDEXER_H
#define INDEXER_H
#include<array>
#include<cmath>
#include<QDebug>

template<unsigned MAX>
class indexer
{
public:
    static constexpr unsigned deg(unsigned val)
    {
        unsigned res=0;
        while((val = val/2)>=2){
            ++res;
        }
        return res;
    }
    static constexpr unsigned upper_val()
    {
        return DEGREE-1+DEGREE+1;
    }
    indexer(){init();}
    static unsigned get_offset(unsigned degree, unsigned current_index){
        if(degree == 0){return 1+current_index;}
        unsigned result=2;
        while(degree!=1){
            result*=2;
            --degree;
        }
        return result+current_index;
    }
    bool init(){
        qDebug()<< "init()" << endl;
        m_indexes.at(0)=UPPER_VAL;
        qDebug()<< "UPPER_VAL" << UPPER_VAL << endl;
        qDebug()<< "DEGREE" << DEGREE << endl;
        qDebug()<< "indexate left" << UPPER_VAL << endl;
        indexate(1,1,UPPER_VAL-DEGREE+1);//left
        qDebug()<< "indexate right" << UPPER_VAL << endl;
        indexate(2,1,UPPER_VAL+DEGREE+1);//right
        return true;
    }
    unsigned indexate(unsigned my_index, unsigned degree, unsigned value){
        unsigned my_value=0;
        qDebug()<< "indexation my_index " << my_index << "degree " << degree<< "value " << value << endl;
        if(degree==DEGREE){//мы на нижнем уровне
            my_value = value;
        }else{


            unsigned child_degree = degree+1;
            unsigned offset_for_child = get_offset(child_degree,my_index);
            qDebug()<< "offset_for_child "<< offset_for_child<<endl;
            my_value = indexate(offset_for_child,child_degree,value-1);//left
            offset_for_child++;
            unsigned right_val = my_value-(degree-(DEGREE+1));
            qDebug()<< "right_val "<< right_val<<endl;

            while((right_val>MAX)&&(right_val!=my_value)){
                --right_val;
            }
            if((!(right_val>MAX))&&(right_val!=my_value)){

                indexate(offset_for_child,child_degree,right_val);//right
            }else{

                throw "shit!";
            }
        }

        m_indexes.at(my_index)=my_value;

        if(degree==1){

            return my_value+DEGREE+1;
        }else{
            return my_value+1;
        }
    }
    unsigned get_next_index(){
        if(CURRENT_INDEX<m_indexes.size()){
            return m_indexes.at(CURRENT_INDEX);
            ++CURRENT_INDEX;
        }else{
            return 0;
        }
    }
    bool check_sum(){
        unsigned sum_of_elems=0;
        unsigned control_sum=0;
        unsigned i=0;
        for (auto& n : m_indexes){
            sum_of_elems += n;
            control_sum +=i;
            ++i;
        }
        return control_sum == sum_of_elems;
    }
private:
    inline static const unsigned DEGREE = deg(MAX);
    inline static const unsigned UPPER_VAL = upper_val();
    inline static unsigned CURRENT_INDEX = 0;
    std::array<unsigned ,MAX> m_indexes;
    //static_assert ((INITED),"check_sum() failed" );
};

#endif // INDEXER_H
