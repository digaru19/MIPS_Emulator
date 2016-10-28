#ifndef MIPS_EMULATOR_H
#define MIPS_EMULATOR_H

#include <vector>
#include <string>
#include "instructions.h"
#include <string.h>

using namespace std;

int get_reg_no(string);

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

extern Registers RegisterFile;
extern Main_Memory DataMemory;



#endif
