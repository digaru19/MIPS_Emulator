#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QFrame>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStringListModel(this);
    QStringList List;
    List << "Clair de Lune" << "Reverie" << "Prelude" ;
    List.push_back("Hello World");
    model->setStringList(List);
    ui->listView->setModel(model);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_next_instr_clicked()
{
    QStringList k = model->stringList();
    k.append("Hello WOrld");
    model->setStringList(k);
}
