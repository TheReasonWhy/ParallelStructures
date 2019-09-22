#ifndef CALL_PAD_MODEL_H
#define CALL_PAD_MODEL_H
#include<QAbstractItemModel>
#include<handler_system.hpp>

template<size_t UP_NUM,
        size_t MIDDLE_NUM,
        size_t LOW_NUM,
        size_t MOVABLE_NUM>
class Call_pad_model : public QAbstractItemModel
{

public:
    using Work_system = Work_system<UP_NUM,MIDDLE_NUM,LOW_NUM,MOVABLE_NUM>;
    using HS = handler_system<Work_system>;
    using call_handler_wrapper = typename HS::call_handler_wrapper;

    Call_pad_model(HS *handlers):m_call_tree(handlers->get_call_tree()){

    }
    ~Call_pad_model(){
        if(m_call_tree){
            delete m_call_tree;
        }
    }
    virtual QModelIndex index(int row, int column, const QModelIndex &parent) const
    {
        return createIndex(row,column,parent);
    }
    virtual QModelIndex parent(const QModelIndex &child) const
    {

    }
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const
    {

    }
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const
    {

    }
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const
    {

    }
private:
    call_handler_wrapper *m_call_tree;
};


#endif // CALL_PAD_MODEL_H














