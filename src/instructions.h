#ifndef MIPS_INSTRUCTIONS_SET_H
#define MIPS_INSTRUCTIONS_SET_H

#include "datapath_elements.h"
#include <vector>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Instruction_Set {
public:
        virtual void execute() = 0;
        static Instruction_Set *create_instr_obj(string , vector<string>& );
        string instr;
        Instruction_Set() { instr.resize(35); };
};

class add : public Instruction_Set {
int src_reg1,src_reg2,dest_reg;
public:
        add(string,string,string,string);
        void execute();
};

class addi : public Instruction_Set {
int src_reg,value,dest_reg;
public:
        addi(string,string,string,string);
        void execute();
};

class _and : public Instruction_Set {
int src_reg1,src_reg2,dest_reg;
public:
        _and(string,string,string,string);
        void execute();
};

class _andi : public Instruction_Set {
int src_reg,value,dest_reg;
public:
        _andi(string,string,string,string);
        void execute();
};

class beq : public Instruction_Set {
int reg_1,reg_2,target;
public:
        beq(string,string,string,string);
        void execute();
};

class bne : public Instruction_Set {
int reg_1,reg_2,target;
public:
        bne(string,string,string,string);
        void execute();
};

class bgez : public Instruction_Set {
int reg_1,target;
public:
        bgez(string,string,string);
        void execute();
};

class blez : public Instruction_Set {
int reg_1,target;
public:
        blez(string,string,string);
        void execute();
};

class bgtz : public Instruction_Set {
int reg_1,target;
public:
        bgtz(string,string,string);
        void execute();
};

class bltz : public Instruction_Set {
int reg_1,target;
public:
        bltz(string,string,string);
        void execute();
};

class bgezal : public Instruction_Set {
int reg_1,target;
public:
        bgezal(string,string,string);
        void execute();
};

class bltzal : public Instruction_Set {
int reg_1,target;
public:
        bltzal(string,string,string);
        void execute();
};

class _div : public Instruction_Set {
int divisor_reg,divident_reg;
public:
        _div(string,string,string);
        void execute();
};

class divu : public Instruction_Set {
int divisor_reg,divident_reg;
public:
        divu(string,string,string);
        void execute();
};

class j : public Instruction_Set {
int target;
public:
        j(string,string);
        void execute();
};

class jr : public Instruction_Set {
int src_reg;
public:
        jr(string,string);
        void execute();
};

class jal : public Instruction_Set {
int target;
public:
        jal(string,string);
        void execute();
};

class lw: public Instruction_Set {
    int offset,base,reg_dest;
    public:
        lw(string,string,string,string);
        void execute();
};

class mult : public Instruction_Set {
int multiplicand_reg,multiplier_reg;
public:
        mult(string,string,string);
        void execute();
};

class multu : public Instruction_Set {
int multiplicand_reg,multiplier_reg;
public:
        multu(string,string,string);
        void execute();
};

class mfhi : public Instruction_Set {
int dest_reg;
public:
        mfhi(string,string);
        void execute();
};

class mflo : public Instruction_Set {
int dest_reg;
public:
        mflo(string,string);
        void execute();
};

class _or : public Instruction_Set {
int src_reg1,src_reg2,dest_reg;
public:
        _or(string,string,string,string);
        void execute();
};

class _ori : public Instruction_Set {
int src_reg,value,dest_reg;
public:
        _ori(string,string,string,string);
        void execute();
};

class sw: public Instruction_Set {
        int offset,base,src_reg;
    public:
        sw(string,string,string,string);
        void execute();
};

class sll : public Instruction_Set {
int src_reg,shamt,dest_reg;
public:
        sll(string,string,string,string);
        void execute();
};

class srl : public Instruction_Set {
int src_reg,shamt,dest_reg;
public:
        srl(string,string,string,string);
        void execute();
};

class srlv : public Instruction_Set {
int src_reg,shamt_reg,dest_reg;
public:
        srlv(string,string,string,string);
        void execute();
};

class sllv : public Instruction_Set {
int src_reg,shamt_reg,dest_reg;
public:
        sllv(string,string,string,string);
        void execute();
};

class sra : public Instruction_Set {
int src_reg,shamt,dest_reg;
public:
        sra(string,string,string,string);
        void execute();
};

class slt : public Instruction_Set {
int dest_reg,reg_lhs,reg_rhs;
public:
        slt(string,string,string,string);
        void execute();
};

class sltu : public Instruction_Set {
int dest_reg;
unsigned int reg_lhs,reg_rhs;
public:
        sltu(string,string,string,string);
        void execute();
};

class slti : public Instruction_Set {
int dest_reg,reg_lhs,value;
public:
        slti(string,string,string,string);
        void execute();
};

class sltiu : public Instruction_Set {
int dest_reg;
unsigned int reg_lhs,value;
public:
        sltiu(string,string,string,string);
        void execute();
};

class sub : public Instruction_Set {
int src_reg1,src_reg2,dest_reg;
public:
        sub(string,string,string,string);
        void execute();
};

class subu : public Instruction_Set {
int src_reg1,src_reg2,dest_reg;
public:
        subu(string,string,string,string);
        void execute();
};

class subi : public Instruction_Set {
int src_reg,value,dest_reg;
public:
        subi(string,string,string,string);
        void execute();
};

class _xor : public Instruction_Set {
int src_reg1,src_reg2,dest_reg;
public:
        _xor(string,string,string,string);
        void execute();
};

class _xori : public Instruction_Set {
int src_reg,value,dest_reg;
public:
        _xori(string,string,string,string);
        void execute();
};

class noop : public Instruction_Set {
public:
        noop(string);
        void execute();
};


#endif
