#include "helper.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>

int get_reg_no(char *reg_name) {
    if(strcmp(reg_name,"$zero")==0) {
        return 0;
    }
    if(strcmp(reg_name,"$at")==0) {
        return 1;
    }
    else if(reg_name[1]=='v') {
        return 2+(reg_name[2]-48);
    }
    else if(reg_name[1]=='a') {
        return 4+(reg_name[2]-48);
    }
    else if(reg_name[1]=='t') {
        if(reg_name[2]-48 <= 7)
            return 8+(reg_name[2]-48);
        else
            return 24+(reg_name[2]-48);
    }
    else if(reg_name[1]=='s') {
        return 16+(reg_name[2]-48);
    }
    else if(reg_name[1]=='k') {
        return 26+(reg_name[2]-48);
    }
    else if(strcmp(reg_name,"$gp")==0) {
        return 28;
    }
    else if(strcmp(reg_name,"$sp")==0) {
        return 29;
    }
    else if(strcmp(reg_name,"$fp")==0) {
        return 30;
    }
    else if(strcmp(reg_name,"$ra")==0) {
        return 31;
    }
    return -1;
};

Registers::Registers() {
        for(int i=0;i<32;i++)
            Register[i]=0;
    }

int Registers::read_reg(int src_reg) {
        return Register[src_reg];
    };

void Registers::write_reg(int data,int dest_reg) {
        Register[dest_reg] = data;
};

void add::execute() {
    std::cout << "\n\t Adding " << src_reg1 << " and " << src_reg2 << " , destination = " << dest_reg ;
    RegisterFile.write_reg(src_reg1+src_reg2,dest_reg);
};

add::add(char *s,int x,int y,int z) {
            strcpy(instr,s);
            dest_reg = x;
            src_reg1 = y;
            src_reg2 = z;
}

addi::addi(char *s,int dest,int v,int base) {
      strcpy(instr,s);
      value = v;
      src_reg = base;
      dest_reg = dest;
}

void addi::execute() {
      int src = RegisterFile.read_reg(src_reg);
      RegisterFile.write_reg(value+src,dest_reg);
}
