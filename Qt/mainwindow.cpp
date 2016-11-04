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
int regs_read_success;

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

    ui->next_instr->setDisabled(true);
    ui->listWidget->setCurrentRow(-1);
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
    else if(InstructionMemory.get_Instruction_size() == InstructionMemory.get_PC()) {
        // Execution is over
        ui->begin_execution->setDisabled(false);
        ui->next_instr->setDisabled(true);
        InstructionMemory.reset_PC();
        //ui->listWidget->item(0)->setSelected(true);
        ui->r2->deselect(); //  <- Included because disabling "Begin Execution" selects the text in r2, might be a bug in Qt
        ui->listWidget->setCurrentRow(-1);
    }

}

void MainWindow::read_UI_reg(QLineEdit *input, int n) {
    bool success;
    int read_data = input->text().toInt(&success);
    if(success == false)
    {
        input->setStyleSheet("QLineEdit { border : 2px inset red; }");
        regs_read_success = 0;
        return ;
    }
    else {
    RegisterFile.write_reg(read_data,n);
    input->setStyleSheet("");
    }
}

void MainWindow::read_register_values() {
    // Read all the QStrings from the QLineEdits of register values,
    // convert to integers and store in RegisterFile

    read_UI_reg(ui->r1,1);
    read_UI_reg(ui->r2,2);
    read_UI_reg(ui->r3,3);
    read_UI_reg(ui->r4,4);
    read_UI_reg(ui->r5,5);
    read_UI_reg(ui->r6,6);
    read_UI_reg(ui->r7,7);
    read_UI_reg(ui->r8,8);
    read_UI_reg(ui->r9,9);
    read_UI_reg(ui->r10,10);
    read_UI_reg(ui->r11,11);
    read_UI_reg(ui->r12,12);
    read_UI_reg(ui->r13,13);
    read_UI_reg(ui->r14,14);
    read_UI_reg(ui->r15,15);
    read_UI_reg(ui->r16,16);
    read_UI_reg(ui->r17,17);
    read_UI_reg(ui->r18,18);
    read_UI_reg(ui->r19,19);
    read_UI_reg(ui->r20,20);
    read_UI_reg(ui->r21,21);
    read_UI_reg(ui->r22,22);
    read_UI_reg(ui->r23,23);
    read_UI_reg(ui->r24,24);
    read_UI_reg(ui->r25,25);
    read_UI_reg(ui->r26,26);
    read_UI_reg(ui->r27,27);
    read_UI_reg(ui->r28,28);
    read_UI_reg(ui->r29,29);
    read_UI_reg(ui->r30,30);
    read_UI_reg(ui->r31,31);
    read_UI_reg(ui->r32,32);
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

void MainWindow::on_begin_execution_clicked()
{
    regs_read_success = 1;

    read_register_values();

    if(regs_read_success == 1) {
        ui->begin_execution->setDisabled(true);
        ui->r2->deselect();  //  <- Included because disabling "Begin Execution" selects the text in r2, might be a bug in Qt
        ui->next_instr->setDisabled(false);

        ui->r1->setReadOnly(true);
        ui->r2->setReadOnly(true);
        ui->r3->setReadOnly(true);
        ui->r4->setReadOnly(true);
        ui->r5->setReadOnly(true);
        ui->r6->setReadOnly(true);
        ui->r7->setReadOnly(true);
        ui->r8->setReadOnly(true);
        ui->r9->setReadOnly(true);
        ui->r10->setReadOnly(true);
        ui->r11->setReadOnly(true);
        ui->r12->setReadOnly(true);
        ui->r13->setReadOnly(true);
        ui->r14->setReadOnly(true);
        ui->r15->setReadOnly(true);
        ui->r16->setReadOnly(true);
        ui->r17->setReadOnly(true);
        ui->r18->setReadOnly(true);
        ui->r19->setReadOnly(true);
        ui->r20->setReadOnly(true);
        ui->r21->setReadOnly(true);
        ui->r22->setReadOnly(true);
        ui->r23->setReadOnly(true);
        ui->r24->setReadOnly(true);
        ui->r25->setReadOnly(true);
        ui->r26->setReadOnly(true);
        ui->r27->setReadOnly(true);
        ui->r28->setReadOnly(true);
        ui->r29->setReadOnly(true);
        ui->r30->setReadOnly(true);
        ui->r31->setReadOnly(true);
        ui->r32->setReadOnly(true);         //   HI Register
        ui->r33->setReadOnly(true);         //   LO Register
    }

}
