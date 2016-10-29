#ifndef MIPS_EMULATOR_H
#define MIPS_EMULATOR_H

#include <vector>
#include <string>
#include "instructions.h"
#include <string.h>

using namespace std;

int get_reg_no(string);

class Instruction_Set;

class Registers {
    int Register[32];
    public:
        Registers();
        int read_reg(int);
        void write_reg(int ,int );

};

class Main_Memory {
        int Memory[400];
public:
        Main_Memory();
        int read_mem(int);
        void write_mem(int,int);
};

class _Instruction_Memory {
public:
        vector < Instruction_Set * > instructions;
        int PC;
        int size;

        _Instruction_Memory();
        bool execute_next();
        void update_PC(int step=1);
        void add_instruction(string);
        void execute_all();

};

extern Registers RegisterFile;
extern Main_Memory DataMemory;
extern _Instruction_Memory InstructionMemory;


#endif
