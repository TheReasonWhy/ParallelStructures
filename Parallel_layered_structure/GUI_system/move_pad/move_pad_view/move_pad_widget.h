#ifndef MOVE_PAD_WIDGET_H
#define MOVE_PAD_WIDGET_H

#include <QWidget>

namespace Ui {
class move_pad_widget;
}

class move_pad_widget : public QWidget
{
    Q_OBJECT

public:
    explicit move_pad_widget(QWidget *parent = nullptr);
    ~move_pad_widget();

private:
    Ui::move_pad_widget *ui;
};

#endif // MOVE_PAD_WIDGET_H
