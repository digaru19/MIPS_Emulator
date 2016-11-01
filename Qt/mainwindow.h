#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>

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

private slots:
    void on_next_instr_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QStringListModel *model;
};

#endif // MAINWINDOW_H
