#include <string.h>
#include <vector>
#include <string>

using namespace std;

#ifndef MIPS_EMULATOR_H
#define MIPS_EMULATOR_H

int get_reg_no(string);

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
        static Instruction *create_instr_obj(string , vector<string>& );
        string instr;
        Instruction() { instr.resize(35); };
};

class _Data_Memory {
        int Memory[400];
public:
        int read_mem(int);
        void write_mem(int,int);
};

class lw: public Instruction {
    int offset,base,reg_dest;
    public:
        lw(string,string,string,string);
        void execute();
};

class sw: public Instruction {
        int offset,base,reg_dest;
    public:
        sw(string,string,string,string);
        void execute();
};

class add : public Instruction {
int src_reg1,src_reg2,dest_reg;
public:
        add(string,string,string,string);
        void execute();
        void display();
};

class addi : public Instruction {
int src_reg,value,dest_reg;
public:
        addi(string,string,string,string);
        void execute();
        void display();
};

#endif
