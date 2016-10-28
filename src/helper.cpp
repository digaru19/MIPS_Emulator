#include "helper.h"
#include <string.h>

class RegFile {
    int Register[32];
    public:
    RegFile() {
        for(int i=0;i<20;i++)
            Register[i]=0;
    }

    int read_reg(int src_reg) {
        return Register[src_reg];
    };

    void write_reg(int data,int dest_reg) {
        Register[dest_reg] = data;
    };

};

class Instruction {
    public:
        char name[10];
        Instruction() {
            strcpy(name,"");
        }
};
class

class lw : public Instruction {
    public:
        int offset,base,reg_dest;
        lw() {
            strcpy(name,"lw");
        }
};
