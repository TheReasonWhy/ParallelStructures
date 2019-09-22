#ifndef CALL_PAD_WIDGET_H
#define CALL_PAD_WIDGET_H

#include <QWidget>

namespace Ui {
class call_pad_widget;
}

class call_pad_widget : public QWidget
{
    Q_OBJECT

public:
    explicit call_pad_widget(QWidget *parent = nullptr);
    ~call_pad_widget();

private:
    Ui::call_pad_widget *ui;
};

#endif // CALL_PAD_WIDGET_H
