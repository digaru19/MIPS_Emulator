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
    else return NULL;
};

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
