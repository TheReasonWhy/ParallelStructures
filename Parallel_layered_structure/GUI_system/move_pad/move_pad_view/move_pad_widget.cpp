#include "move_pad_widget.h"
#include "ui_move_pad_widget.h"

move_pad_widget::move_pad_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::move_pad_widget)
{
    ui->setupUi(this);
}

move_pad_widget::~move_pad_widget()
{
    delete ui;
}
