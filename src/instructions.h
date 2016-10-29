#ifndef MIPS_INSTRUCTIONS_SET_H
#define MIPS_INSTRUCTIONS_SET_H

#include "datapath_elements.h"
#include <vector>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Instruction {
public:
        virtual void execute() = 0;
        static Instruction *create_instr_obj(string , vector<string>& );
        string instr;
        Instruction() { instr.resize(35); };
};

class lw: public Instruction {
    int offset,base,reg_dest;
    public:
        lw(string,string,string,string);
        void execute();
};

class sw: public Instruction {
        int offset,base,src_reg;
    public:
        sw(string,string,string,string);
        void execute();
};

class add : public Instruction {
int src_reg1,src_reg2,dest_reg;
public:
        add(string,string,string,string);
        void execute();
};

class addi : public Instruction {
int src_reg,value,dest_reg;
public:
        addi(string,string,string,string);
        void execute();
};

class sub : public Instruction {
int src_reg1,src_reg2,dest_reg;
public:
        sub(string,string,string,string);
        void execute();
};

class subi : public Instruction {
int src_reg,value,dest_reg;
public:
        subi(string,string,string,string);
        void execute();
};

class _and : public Instruction {
int src_reg1,src_reg2,dest_reg;
public:
        _and(string,string,string,string);
        void execute();
};

class _andi : public Instruction {
int src_reg,value,dest_reg;
public:
        _andi(string,string,string,string);
        void execute();
};

#endif
