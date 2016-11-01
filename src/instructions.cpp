#include "instructions.h"
#include "datapath_elements.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int parse_int(const char str[20]) {
    long integer;
    if(str[1]=='x' or str[1]=='X')
        integer = strtol(str,NULL,16);
    else
        integer = strtol(str,NULL,10);
    return integer;
}

Instruction_Set *Instruction_Set::create_instr_obj(string instr, vector<string>& tokens) {
    string instr_name = tokens[0];

    if(instr_name == "add") {
        return new add(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "addi") {
        return new addi(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "and") {
        return new _and(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "andi") {
        return new _andi(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "beq") {
        return new beq(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "bne") {
        return new bne(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "bgez") {
        return new bgez(instr,tokens[1],tokens[2]);
    }
    else if(instr_name == "bgtz") {
        return new bgtz(instr,tokens[1],tokens[2]);
    }
    else if(instr_name == "blez") {
        return new blez(instr,tokens[1],tokens[2]);
    }
    else if(instr_name == "bltz") {
        return new bltz(instr,tokens[1],tokens[2]);
    }
    else if(instr_name == "bgezal") {
        return new bgezal(instr,tokens[1],tokens[2]);
    }
    else if(instr_name == "bltzal") {
        return new bltzal(instr,tokens[1],tokens[2]);
    }
    else if(instr_name == "div") {
        return new _div(instr,tokens[1],tokens[2]);
    }
    else if(instr_name == "divu") {
        return new divu(instr,tokens[1],tokens[2]);
    }
    else if(instr_name == "j") {
        return new j(instr,tokens[1]);
    }
    else if(instr_name == "jr") {
        return new jr(instr,tokens[1]);
    }
    else if(instr_name == "jal") {
        return new jal(instr,tokens[1]);
    }
    else if(instr_name == "lw") {
        return new add(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "mfhi") {
        return new mfhi(instr,tokens[1]);
    }
    else if(instr_name == "mflo") {
        return new mflo(instr,tokens[1]);
    }
    else if(instr_name == "mult") {
        return new mult(instr,tokens[1],tokens[2]);
    }
    else if(instr_name == "multu") {
        return new multu(instr,tokens[1],tokens[2]);
    }
    else if(instr_name == "or") {
        return new _or(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "ori") {
        return new _ori(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "sw") {
        return new add(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "sub") {
        return new sub(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "subi") {
        return new subi(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "subu") {
        return new subu(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "sll") {
        return new sll(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "sllv") {
        return new sllv(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "srl") {
        return new srl(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "srlv") {
        return new srlv(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "sra") {
        return new sra(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "slt") {
        return new slt(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "sltu") {
        return new sltu(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "sltiu") {
        return new sltiu(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "xor") {
        return new _xor(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "xori") {
        return new _xori(instr,tokens[1],tokens[2],tokens[3]);
    }
    else if(instr_name == "noop") {
        return new noop(instr);
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
      value = parse_int(v.c_str());
      src_reg = get_reg_no(src);
      dest_reg = get_reg_no(dest);
}
void addi::execute() {
      int src = RegisterFile.read_reg(src_reg);
      RegisterFile.write_reg(value+src,dest_reg);
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
    value = parse_int(imm.c_str());
    src_reg = get_reg_no(src);
    dest_reg = get_reg_no(dest);
}
void _andi::execute() {
    int rs = RegisterFile.read_reg(src_reg);
    RegisterFile.write_reg(rs & value , dest_reg);
}

beq::beq(string s,string rs,string rt,string offset_value) {
    instr = s;
    reg_1 = get_reg_no(rs);
    reg_2 = get_reg_no(rt);
    target = parse_int(offset_value.c_str());
};
void beq::execute() {
    int r1 = RegisterFile.read_reg(reg_1);
    int r2 = RegisterFile.read_reg(reg_2);
    //cout << "\n\t Checking  " << r1 << "  and  " << r2;
    if(r1 == r2)
        InstructionMemory.update_PC(target - 1);
};

bne::bne(string s,string rs,string rt,string offset_value) {
    instr = s;
    reg_1 = get_reg_no(rs);
    reg_2 = get_reg_no(rt);
    target = parse_int(offset_value.c_str());
};
void bne::execute() {
    int r1 = RegisterFile.read_reg(reg_1);
    int r2 = RegisterFile.read_reg(reg_2);
    //cout << "\n\t Checking  " << r1 << "  and  " << r2;
    if(r1 != r2)
        InstructionMemory.update_PC(target - 1);
};

bgez::bgez(string s,string rs,string jump_to) {
    instr = s;
    reg_1 = get_reg_no(rs);
    target = parse_int(jump_to.c_str());
}
void bgez::execute() {
    int r1 = RegisterFile.read_reg(reg_1);
    if(r1 >= 0)
        InstructionMemory.update_PC(target - 1);
}

blez::blez(string s,string rs,string jump_to) {
    instr = s;
    reg_1 = get_reg_no(rs);
    target = parse_int(jump_to.c_str());
}
void blez::execute() {
    int r1 = RegisterFile.read_reg(reg_1);
    if(r1 <= 0)
        InstructionMemory.update_PC(target - 1);
}

bgtz::bgtz(string s,string rs,string jump_to) {
    instr = s;
    reg_1 = get_reg_no(rs);
    target = parse_int(jump_to.c_str());
}
void bgtz::execute() {
    int r1 = RegisterFile.read_reg(reg_1);
    if(r1 > 0)
        InstructionMemory.update_PC(target - 1);
}

bltz::bltz(string s,string rs,string jump_to) {
    instr = s;
    reg_1 = get_reg_no(rs);
    target = parse_int(jump_to.c_str());
}
void bltz::execute() {
    int r1 = RegisterFile.read_reg(reg_1);
    if(r1 < 0)
        InstructionMemory.update_PC(target - 1);
}

bgezal::bgezal(string s,string rs,string jump_to) {
    instr = s;
    reg_1 = get_reg_no(rs);
    target = parse_int(jump_to.c_str());
}
void bgezal::execute() {
    int r1 = RegisterFile.read_reg(reg_1);
    if(r1 >= 0) {
        int curr_PC = InstructionMemory.get_PC();
        RegisterFile.write_reg(curr_PC,31);
        InstructionMemory.update_PC(target - 1);
        }
}

bltzal::bltzal(string s,string rs,string jump_to) {
    instr = s;
    reg_1 = get_reg_no(rs);
    target = parse_int(jump_to.c_str());
}
void bltzal::execute() {
    int r1 = RegisterFile.read_reg(reg_1);
    if(r1 < 0) {
        int curr_PC = InstructionMemory.get_PC();
        RegisterFile.write_reg(curr_PC,31);
        InstructionMemory.update_PC(target - 1);
        }
}

_div::_div(string s,string divident,string divisor) {
    instr = s;
    divident_reg = get_reg_no(divident);
    divisor_reg = get_reg_no(divisor);
}
void _div::execute() {
    int divisor = RegisterFile.read_reg(divisor_reg);
    int divident = RegisterFile.read_reg(divident_reg);
    RegisterFile.write_reg( divident / divisor , 32);   //  LO is 32
    RegisterFile.write_reg( divident % divisor , 33);   // HI is 33
}

divu::divu(string s,string divident,string divisor) {
    instr = s;
    divident_reg = get_reg_no(divident);
    divisor_reg = get_reg_no(divisor);
}
void divu::execute() {
    unsigned int divisor = RegisterFile.read_reg(divisor_reg);
    unsigned int divident = RegisterFile.read_reg(divident_reg);
    RegisterFile.write_reg( divident / divisor , 32);   //  LO is 32
    RegisterFile.write_reg( divident % divisor , 33);   // HI is 33
}

j::j(string s,string offset) {
    target = parse_int(offset.c_str());
    instr = s;
}
void j::execute() {
    int jump_to = (InstructionMemory.get_PC() & 0xf0000000) | (target << 2);
    InstructionMemory.update_PC(jump_to-1);
};

jr::jr(string s,string src) {
    instr = s;
    src_reg = get_reg_no(src);
}
void jr::execute() {
    int jump_to = RegisterFile.read_reg(src_reg);
    InstructionMemory.update_PC(jump_to-1);
};

jal::jal(string s,string offset) {
    instr = s;
    target = parse_int(offset.c_str());
}
void jal::execute() {
    int curr_PC = InstructionMemory.get_PC() + 1;
    RegisterFile.write_reg(curr_PC,31);
    int jump_to = (InstructionMemory.get_PC() & 0xf0000000) | (target << 2);
    InstructionMemory.update_PC(jump_to-1);
};

lw::lw(string s,string dest,string offset_value,string base_reg) {
    instr = instr;
    reg_dest = get_reg_no(dest);
    base = get_reg_no(base_reg);
    offset = parse_int(offset_value.c_str());
}
void lw::execute() {
    int _base_value = RegisterFile.read_reg(base);
    int read_data = DataMemory.read_mem(_base_value + offset);
    RegisterFile.write_reg(read_data,reg_dest);
}

mult::mult(string s, string multiplicand,string multiplier) {
    instr = s;
    multiplicand_reg = get_reg_no(multiplicand);
    multiplier_reg = get_reg_no(multiplier);
}
void mult::execute() {
    int multiplicand = RegisterFile.read_reg(multiplicand_reg);
    int multiplier = RegisterFile.read_reg(multiplier_reg);
    RegisterFile.write_reg(multiplicand * multiplier , 32);
}

multu::multu(string s, string multiplicand,string multiplier) {
    instr = s;
    multiplicand_reg = get_reg_no(multiplicand);
    multiplier_reg = get_reg_no(multiplier);
}
void multu::execute() {
    unsigned int multiplicand = RegisterFile.read_reg(multiplicand_reg);
    unsigned int multiplier = RegisterFile.read_reg(multiplier_reg);
    RegisterFile.write_reg(multiplicand * multiplier , 32);
}

mfhi::mfhi(string s,string dest) {
    instr = s;
    dest_reg = get_reg_no(dest);
}
void mfhi::execute() {
    int hi_data = RegisterFile.read_reg(33);
    RegisterFile.write_reg(hi_data,dest_reg);
}

mflo::mflo(string s,string dest) {
    instr = s;
    dest_reg = get_reg_no(dest);
}
void mflo::execute() {
    int hi_data = RegisterFile.read_reg(32);
    RegisterFile.write_reg(hi_data,dest_reg);
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
    value = parse_int(imm.c_str());
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
    shamt = parse_int(sa.c_str());
}
void sll::execute() {
    int rs = RegisterFile.read_reg(src_reg);
    RegisterFile.write_reg(rs << shamt , dest_reg);
};

srl::srl(string s,string dest,string src,string sa) {
    instr = s;
    dest_reg = get_reg_no(dest);
    src_reg = get_reg_no(src);
    shamt = parse_int(sa.c_str());
}
void srl::execute() {
    unsigned int rs = RegisterFile.read_reg(src_reg);
    RegisterFile.write_reg(rs >> shamt , dest_reg);
};

sra::sra(string s,string dest,string src,string sa) {
    instr = s;
    dest_reg = get_reg_no(dest);
    src_reg = get_reg_no(src);
    shamt = parse_int(sa.c_str());
}
void sra::execute() {
    int rs = RegisterFile.read_reg(src_reg);
    RegisterFile.write_reg(rs >> shamt , dest_reg);
};

srlv::srlv(string s,string dest,string src,string shamt) {
    instr = s;
    dest_reg = get_reg_no(dest);
    src_reg = get_reg_no(src);
    shamt_reg = get_reg_no(shamt);
};
void srlv::execute() {
    unsigned int rs = RegisterFile.read_reg(src_reg);
    int shamt = RegisterFile.read_reg(shamt_reg);
    RegisterFile.write_reg(rs >> shamt, dest_reg);
}

sllv::sllv(string s,string dest,string src,string shamt) {
    instr = s;
    dest_reg = get_reg_no(dest);
    src_reg = get_reg_no(src);
    shamt_reg = get_reg_no(shamt);
};
void sllv::execute() {
    int rs = RegisterFile.read_reg(src_reg);
    int shamt = RegisterFile.read_reg(shamt_reg);
    RegisterFile.write_reg(rs << shamt, dest_reg);
}

slt::slt(string s,string dest,string reg_l,string reg_r) {
    instr = s;
    reg_rhs = get_reg_no(reg_r);
    reg_lhs = get_reg_no(reg_l);
    dest_reg = get_reg_no(dest);
};
void slt::execute() {
    int reg_data_1 = RegisterFile.read_reg(reg_lhs);
    int reg_data_2 = RegisterFile.read_reg(reg_rhs);
    if(reg_data_1 < reg_data_2)
        RegisterFile.write_reg(1,dest_reg);
    else
        RegisterFile.write_reg(0,dest_reg);
}

sltu::sltu(string s,string dest,string reg_l,string reg_r) {
    instr = s;
    reg_rhs = get_reg_no(reg_r);
    reg_lhs = get_reg_no(reg_l);
    dest_reg = get_reg_no(dest);
};
void sltu::execute() {
    unsigned int reg_data_1 = RegisterFile.read_reg(reg_lhs);
    unsigned int reg_data_2 = RegisterFile.read_reg(reg_rhs);
    if(reg_data_1 < reg_data_2)
        RegisterFile.write_reg(1,dest_reg);
    else
        RegisterFile.write_reg(0,dest_reg);
}

slti::slti(string s,string dest,string reg_l,string imm) {
    instr = s;
    dest_reg = get_reg_no(dest);
    reg_lhs = get_reg_no(reg_l);
    value = parse_int(imm.c_str());
}
void slti::execute() {
    int src_reg_data = RegisterFile.read_reg(reg_lhs);
    if(src_reg_data < value)
        RegisterFile.write_reg(1,dest_reg);
    else
        RegisterFile.write_reg(0,dest_reg);
};

sltiu::sltiu(string s,string dest,string reg_l,string imm) {
    instr = s;
    dest_reg = get_reg_no(dest);
    reg_lhs = get_reg_no(reg_l);
    value = parse_int(imm.c_str());
}
void sltiu::execute() {
    unsigned int src_reg_data = RegisterFile.read_reg(reg_lhs);
    if(src_reg_data < value)
        RegisterFile.write_reg(1,dest_reg);
    else
        RegisterFile.write_reg(0,dest_reg);
}

sw::sw(string s,string src,string offset_value,string base_reg) {
    instr = s;
    src_reg = get_reg_no(src);
    base = get_reg_no(base_reg);
    offset = parse_int(offset_value.c_str());
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

subu::subu(string s,string dest,string rs,string rt) {
    instr = s;
    dest_reg = get_reg_no(dest);
    src_reg1 = get_reg_no(rs);
    src_reg2 = get_reg_no(rt);
}
void subu::execute() {
    unsigned int rs = RegisterFile.read_reg(src_reg1);
    unsigned int rt = RegisterFile.read_reg(src_reg2);
    RegisterFile.write_reg(rs-rt,dest_reg);
}

subi::subi(string s,string dest,string src,string imm) {
    instr = s;
    value = parse_int(imm.c_str());
    src_reg = get_reg_no(src);
    dest_reg = get_reg_no(dest);
}
void subi::execute() {
    int rs = RegisterFile.read_reg(src_reg);
    RegisterFile.write_reg( rs - value , dest_reg);
}

_xor::_xor(string s,string dest,string rs,string rt) {
    instr = s;
    dest_reg = get_reg_no(dest);
    src_reg1 = get_reg_no(rs);
    src_reg2 = get_reg_no(rt);
}
void _xor::execute() {
    int rs = RegisterFile.read_reg(src_reg1);
    int rt = RegisterFile.read_reg(src_reg2);
    RegisterFile.write_reg(rs ^ rt , dest_reg );
}

_xori::_xori(string s,string dest,string src,string imm) {
    instr = s;
    value = parse_int(imm.c_str());
    src_reg = get_reg_no(src);
    dest_reg = get_reg_no(dest);
}
void _xori::execute() {
    int rs = RegisterFile.read_reg(src_reg);
    RegisterFile.write_reg(rs ^ value , dest_reg);
}

noop::noop(string s) {
    instr = s;
};
void noop::execute() {
return ;
};
