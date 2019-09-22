#ifndef RESULT_PAD_WIDGET_H
#define RESULT_PAD_WIDGET_H

#include <QWidget>

namespace Ui {
class result_pad_widget;
}

class result_pad_widget : public QWidget
{
    Q_OBJECT

public:
    explicit result_pad_widget(QWidget *parent = nullptr);
    ~result_pad_widget();

private:
    Ui::result_pad_widget *ui;
};

#endif // RESULT_PAD_WIDGET_H
