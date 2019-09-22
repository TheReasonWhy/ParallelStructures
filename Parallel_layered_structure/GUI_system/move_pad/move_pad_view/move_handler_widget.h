#ifndef MOVE_HANDLER_WIDGET_H
#define MOVE_HANDLER_WIDGET_H

#include <QWidget>

namespace Ui {
class move_handler_widget;
}

class move_handler_widget : public QWidget
{
    Q_OBJECT

public:
    explicit move_handler_widget(QWidget *parent = nullptr);
    ~move_handler_widget();

private:
    Ui::move_handler_widget *ui;
};

#endif // MOVE_HANDLER_WIDGET_H
