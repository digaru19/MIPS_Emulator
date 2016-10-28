#include <string.h>

#ifndef MIPS_EMULATOR_H
#define MIPS_EMULATOR_H


int get_reg_no(char *reg_name);

class Registers {
    int Register[32];
    public:
        Registers();
        int read_reg(int);
        void write_reg(int ,int );

};

extern Registers RegisterFile;

class Instruction {
public:
        virtual void execute() = 0;
        char instr[30];
};

class lw: public Instruction {
    public:
        int offset;
        int base;
        int reg_dest;
        lw(char*,int,int,int);
        void execute();
};

class sw: public Instruction {
    public:
        int offset;
        int base;
        int reg_dest;
        sw(char*,int,int,int);
        void execute();
};

class add : public Instruction {
public:
        int src_reg1,src_reg2,dest_reg;
        add(char*,int,int,int);
        void execute();
};

class addi : public Instruction {
public:
        int src_reg,value,dest_reg;
        addi(char*,int,int,int);
        void execute();
};

#endif
