#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <iostream>
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
    ui->PC_Value->setAlignment(Qt::AlignRight);
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
    display_register_values();
    mips_code.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
QString int_to_QStr(int n) {
    return QString::fromStdString(to_string(n));
}

void MainWindow::on_next_instr_clicked()
{
    //std::cout << " \n\t **  PC is :- " << InstructionMemory.get_PC();

    if(InstructionMemory.PC_is_valid()) {
    ui->listWidget->item(InstructionMemory.get_PC())->setSelected(true);
    ui->PC_Value->setText(int_to_QStr(InstructionMemory.get_PC()));
    InstructionMemory.execute_next();
    display_register_values();
    }

}

void MainWindow::display_register_values() {

    ui->r1->setText(int_to_QStr(RegisterFile.read_reg(1)));
    ui->r2->setText(int_to_QStr(RegisterFile.read_reg(2)));
    ui->r3->setText(int_to_QStr(RegisterFile.read_reg(3)));
    ui->r4->setText(int_to_QStr(RegisterFile.read_reg(4)));
    ui->r5->setText(int_to_QStr(RegisterFile.read_reg(5)));
    ui->r6->setText(int_to_QStr(RegisterFile.read_reg(6)));
    ui->r7->setText(int_to_QStr(RegisterFile.read_reg(7)));
    ui->r8->setText(int_to_QStr(RegisterFile.read_reg(8)));
    ui->r9->setText(int_to_QStr(RegisterFile.read_reg(9)));
    ui->r10->setText(int_to_QStr(RegisterFile.read_reg(10)));
    ui->r11->setText(int_to_QStr(RegisterFile.read_reg(11)));
    ui->r12->setText(int_to_QStr(RegisterFile.read_reg(12)));
    ui->r13->setText(int_to_QStr(RegisterFile.read_reg(13)));
    ui->r14->setText(int_to_QStr(RegisterFile.read_reg(14)));
    ui->r15->setText(int_to_QStr(RegisterFile.read_reg(15)));
    ui->r16->setText(int_to_QStr(RegisterFile.read_reg(16)));
    ui->r17->setText(int_to_QStr(RegisterFile.read_reg(17)));
    ui->r18->setText(int_to_QStr(RegisterFile.read_reg(18)));
    ui->r19->setText(int_to_QStr(RegisterFile.read_reg(19)));
    ui->r20->setText(int_to_QStr(RegisterFile.read_reg(20)));
    ui->r21->setText(int_to_QStr(RegisterFile.read_reg(21)));
    ui->r22->setText(int_to_QStr(RegisterFile.read_reg(22)));
    ui->r23->setText(int_to_QStr(RegisterFile.read_reg(23)));
    ui->r24->setText(int_to_QStr(RegisterFile.read_reg(24)));
    ui->r25->setText(int_to_QStr(RegisterFile.read_reg(25)));
    ui->r26->setText(int_to_QStr(RegisterFile.read_reg(26)));
    ui->r27->setText(int_to_QStr(RegisterFile.read_reg(27)));
    ui->r28->setText(int_to_QStr(RegisterFile.read_reg(28)));
    ui->r29->setText(int_to_QStr(RegisterFile.read_reg(29)));
    ui->r30->setText(int_to_QStr(RegisterFile.read_reg(30)));
    ui->r31->setText(int_to_QStr(RegisterFile.read_reg(31)));
    ui->r32->setText(int_to_QStr(RegisterFile.read_reg(32)));
    ui->r33->setText(int_to_QStr(RegisterFile.read_reg(33)));
}
