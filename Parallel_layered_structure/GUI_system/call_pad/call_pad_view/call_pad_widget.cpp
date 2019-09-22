#include "call_pad_widget.h"
#include "ui_call_pad_widget.h"

call_pad_widget::call_pad_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::call_pad_widget)
{
    ui->setupUi(this);
}

call_pad_widget::~call_pad_widget()
{
    delete ui;
}
