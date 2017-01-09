#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void display_register_values();
    void read_register_values();
    void read_UI_reg(QLineEdit *, int );
    void allow_reg_edit(bool);
    void reset_reg_values();

private slots:
    void on_next_instr_clicked();

    void on_pushButton_clicked();

    void on_begin_execution_clicked();

    void on_reset_reg_values_clicked();

    void on_stop_execution_clicked();

private:
    Ui::MainWindow *ui;
    QStringListModel *model;
};

#endif // MAINWINDOW_H
