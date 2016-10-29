#include "instructions.h"
#include "datapath_elements.h"
#include <vector>
#include <string>

using namespace std;

Instruction *Instruction::create_instr_obj(string instr, vector<string>& tokens) {
    string instr_name = tokens[0];

    if(instr_name == "add") {
        return new add(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "addi") {
        return new addi(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "lw") {
        return new add(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "sw") {
        return new add(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "and") {
        return new _and(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "andi") {
        return new _andi(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "sub") {
        return new sub(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "subi") {
        return new subi(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "or") {
        return new _or(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "ori") {
        return new _ori(instr,tokens[1],tokens[2],tokens[3]);
    }
     else if(instr_name == "sll") {
        return new sll(instr,tokens[1],tokens[2],tokens[3]);
    }
    else return NULL;
};

add::add(string s,string dest,string rs,string rt) {
            instr = s;
            dest_reg = get_reg_no(dest);
            src_reg1 = get_reg_no(rs);
            src_reg2 = get_reg_no(rt);
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
    DataMemory.write_mem(_data,offset+_base_value);
}

sub::sub(string s,string dest,string rs,string rt) {
    instr = s;
    dest_reg = get_reg_no(dest);
    src_reg1 = get_reg_no(rs);
    src_reg2 = get_reg_no(rt);
}

void sub::execute() {
    int rs = RegisterFile.read_reg(src_reg1);
    int rt = RegisterFile.read_reg(src_reg2);
    RegisterFile.write_reg(rs-rt,dest_reg);
}

subi::subi(string s,string dest,string src,string imm) {
    instr = s;
    value = atoi(imm.c_str());
    src_reg = get_reg_no(src);
    dest_reg = get_reg_no(dest);
}

void subi::execute() {
    int rs = RegisterFile.read_reg(src_reg);
    RegisterFile.write_reg( rs - value , dest_reg);
}

_and::_and(string s,string dest,string rs,string rt) {
    instr = s;
    dest_reg = get_reg_no(dest);
    src_reg1 = get_reg_no(rs);
    src_reg2 = get_reg_no(rt);
}

void _and::execute() {
    int rs = RegisterFile.read_reg(src_reg1);
    int rt = RegisterFile.read_reg(src_reg2);
    RegisterFile.write_reg(rs & rt , dest_reg );
}

_andi::_andi(string s,string dest,string src,string imm) {
    instr = s;
    value = atoi(imm.c_str());
    src_reg = get_reg_no(src);
    dest_reg = get_reg_no(dest);
}

void _andi::execute() {
    int rs = RegisterFile.read_reg(src_reg);
    RegisterFile.write_reg(rs & value , dest_reg);
}

_or::_or(string s,string dest,string rs,string rt) {
    instr = s;
    dest_reg = get_reg_no(dest);
    src_reg1 = get_reg_no(rs);
    src_reg2 = get_reg_no(rt);
}

void _or::execute() {
    int rs = RegisterFile.read_reg(src_reg1);
    int rt = RegisterFile.read_reg(src_reg2);
    RegisterFile.write_reg(rs | rt , dest_reg );
}

_ori::_ori(string s,string dest,string src,string imm) {
    instr = s;
    value = atoi(imm.c_str());
    src_reg = get_reg_no(src);
    dest_reg = get_reg_no(dest);
}

void _ori::execute() {
    int rs = RegisterFile.read_reg(src_reg);
    RegisterFile.write_reg(rs | value , dest_reg);
}

sll::sll(string s,string dest,string src,string sa) {
    instr = s;
    dest_reg = get_reg_no(dest);
    src_reg = get_reg_no(src);
    shamt = atoi(sa.c_str());
}

void sll::execute() {
    int rs = RegisterFile.read_reg(src_reg);
    RegisterFile.write_reg(rs << shamt , dest_reg);
};


