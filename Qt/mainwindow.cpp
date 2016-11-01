#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QFrame>
#include <QListWidgetItem>
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    strcpy(k,"A");
    QListWidgetItem *item1 = new QListWidgetItem(k);
    k[0]++;
    ui->listWidget->addItem(item1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_next_instr_clicked()
{
    QListWidgetItem *item1 = new QListWidgetItem(k);
    k[0]++;
    ui->listWidget->addItem(item1);
    ui->listWidget->item(((int)k[0])-66)->setSelected(true);
}
