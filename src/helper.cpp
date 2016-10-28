#include "helper.h"
#include <string.h>
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

Instruction *Instruction::create_instr_obj(string instr, vector<string>& tokens) {
    string instr_name = tokens[0];

    if(instr_name == "add") {
        return new add(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "addi") {
        return new addi(instr,tokens[1],tokens[2],tokens[3]);
    }
    else return NULL;
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

add::add(string s,string x,string y,string z) {
            instr = s;
            dest_reg = get_reg_no(x.c_str());
            src_reg1 = get_reg_no(y.c_str());
            src_reg2 = get_reg_no(z.c_str());
}

void add::execute() {
    int rs = RegisterFile.read_reg(src_reg1);
    int rt = RegisterFile.read_reg(src_reg2);
    RegisterFile.write_reg(rs+rt,dest_reg);
};

addi::addi(string s,string dest,string src,string v) {
      instr = s;
      value = atoi(v.c_str());
      src_reg = get_reg_no(src);
      dest_reg = get_reg_no(dest);
}

void addi::execute() {
      int src = RegisterFile.read_reg(src_reg);
      RegisterFile.write_reg(value+src,dest_reg);
}

lw::lw(string s,string dest,string offset_value,string base_reg) {
    instr = instr;
    reg_dest = get_reg_no(dest);
    base = get_reg_no(base_reg);
    offset = atoi(offset_value.c_str());
}

void lw::execute() {
    int _base_value = RegisterFile.read_reg(base);
    int read_data = DataMemory.read_mem(_base_value + offset);
    RegisterFile.write_reg(read_data,reg_dest);
}

sw::sw(string s,string src,string offset_value,string base_reg) {
    instr = s;
    src_reg = get_reg_no(src);
    base = get_reg_no(base_reg);
    offset = atoi(offset_value.c_str());
}

void sw::execute() {
    int _data = RegisterFile.read_reg(src_reg);
    int _base_value = RegisterFile.read_reg(base);
    DataMemory.write_mem(offset+_base_value,_data);
}
