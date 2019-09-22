#include "result_pad_widget.h"
#include "ui_result_pad_widget.h"

result_pad_widget::result_pad_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::result_pad_widget)
{
    ui->setupUi(this);
}

result_pad_widget::~result_pad_widget()
{
    delete ui;
}
