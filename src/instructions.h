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

class lw: public Instruction_Set {
    int offset,base,reg_dest;
    public:
        lw(string,string,string,string);
        void execute();
};

class sw: public Instruction_Set {
        int offset,base,src_reg;
    public:
        sw(string,string,string,string);
        void execute();
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

class sub : public Instruction_Set {
int src_reg1,src_reg2,dest_reg;
public:
        sub(string,string,string,string);
        void execute();
};

class subi : public Instruction_Set {
int src_reg,value,dest_reg;
public:
        subi(string,string,string,string);
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

class sll : public Instruction_Set {
int src_reg,shamt,dest_reg;
public:
        sll(string,string,string,string);
        void execute();
};

class slt : public Instruction_Set {
int dest_reg,reg_lhs,reg_rhs;
public:
        slt(string,string,string,string);
        void execute();
};

class beq : public Instruction_Set {
int reg_1,reg_2,offset;
public:
        beq(string,string,string,string);
        void execute();
};


#endif
