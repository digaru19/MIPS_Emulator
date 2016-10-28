#include "datapath_elements.h"
#include "instructions.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int get_reg_no(string reg) {
    char reg_name[8];
    strcpy(reg_name,reg.c_str());

    if(strcmp(reg_name,"$zero")==0) {
        return 0;
    }
    else if(strcmp(reg_name,"$at")==0) {
        return 1;
    }
    else if(strcmp(reg_name,"$sp")==0) {
        return 29;
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
            return 24+(reg_name[2]-56);
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

Main_Memory::Main_Memory() {
    for(int i=0;i<400;i++)
            Memory[i]=0;
}

int Main_Memory::read_mem(int mem_cell) {
    return Memory[mem_cell];
};

void Main_Memory::write_mem(int location,int data) {
    Memory[location] = data;
}


