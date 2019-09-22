#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<call_pad_view.h>
#include<move_pad_view.h>
#include<result_pad_view.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
