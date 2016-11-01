#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QVBoxLayout>
#include <fstream>
#include <QListWidgetItem>
#include <stdlib.h>
#include "instructions.h"
#include "datapath_elements.h"

Registers RegisterFile;
_Instruction_Memory InstructionMemory;
Main_Memory DataMemory;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    strcpy(k,"A");
    ifstream mips_code("code.mips");
    char s[50];
    while(!mips_code.eof()) {
        mips_code.getline(s,40);
        if(InstructionMemory.add_instruction(s))
        {
            QListWidgetItem *item = new QListWidgetItem(s);
            InstructionMemory.update_PC();
            ui->listWidget->addItem(item);
        }
        }
    InstructionMemory.reset_PC();
    mips_code.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_next_instr_clicked()
{
    if(InstructionMemory.PC_is_valid()) {
    ui->listWidget->item(InstructionMemory.get_PC())->setSelected(true);
    ui->PC_Value->setText(QString::fromStdString(to_string(InstructionMemory.get_PC())));
    InstructionMemory.update_PC();
    }
}

void MainWindow::on_pushButton_clicked()
{


}
