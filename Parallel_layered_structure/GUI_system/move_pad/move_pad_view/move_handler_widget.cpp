#include "move_handler_widget.h"
#include "ui_move_handler_widget.h"

move_handler_widget::move_handler_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::move_handler_widget)
{
    ui->setupUi(this);
}

move_handler_widget::~move_handler_widget()
{
    delete ui;
}
