
#include <vector>
#include <string>
#include "instructions.h"
#include <string.h>

#ifndef MIPS_EMULATOR_H
#define MIPS_EMULATOR_H


using namespace std;

int get_reg_no(string);

class Instruction_Set;

class Registers {
    // There are 34 registers, instead of 32, for strogin the values of HI and LO.
    // But, in a typical MIPS architecture, there are only 32 registers.
    // For the implementation of this emulator, I have considered the HI and LO registers
    // to be a part of the 32 general purpose registers of MIPS.
    // HI = 32 ;  LO = 33
    int Register[34];
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
        vector < Instruction_Set * > instructions;
        int PC;
        int size;
    public:
        _Instruction_Memory();
        void display_instr();
        bool execute_next();
        void update_PC(int step=1);
        void add_instruction(string);
        void execute_all();
        int get_PC();
        bool PC_is_valid();
};

extern Registers RegisterFile;
extern Main_Memory DataMemory;
extern _Instruction_Memory InstructionMemory;


#endif
