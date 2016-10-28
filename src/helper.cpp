#include "helper.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>

int get_reg_no(char *reg_name) {
    if(strcmp(reg_name,"$zero")==0) {
        return 0;
    }
    if(strcmp(reg_name,"$at")==0) {
        return 1;
    }
    else if(reg_name[1]=='v') {
        return 2+(reg_name[2]-48);
    }
    else if(reg_name[1]=='a') {
        return 4+(reg_name[2]-48);
    }
    else if(reg_name[1]=='t') {
        if(reg_name[2]-48 <= 7)
            return 8+(reg_name[2]-48);
        else
            return 24+(reg_name[2]-48);
    }
    else if(reg_name[1]=='s') {
        return 16+(reg_name[2]-48);
    }
    else if(reg_name[1]=='k') {
        return 26+(reg_name[2]-48);
    }
    else if(strcmp(reg_name,"$gp")==0) {
        return 28;
    }
    else if(strcmp(reg_name,"$sp")==0) {
        return 29;
    }
    else if(strcmp(reg_name,"$fp")==0) {
        return 30;
    }
    else if(strcmp(reg_name,"$ra")==0) {
        return 31;
    }
    return -1;
};

class RegFile {
    int Register[32];
    public:
    RegFile() {
        for(int i=0;i<32;i++)
            Register[i]=0;
    }

    int read_reg(int src_reg) {
        return Register[src_reg];
    };

    void write_reg(int data,int dest_reg) {
        Register[dest_reg] = data;
    };

};

/*class Instruction {
    public:
        char name[10];
        Instruction() {
        strcpy(name,"");
        };
};
*/

class lw: public Instruction {
    public:
        int offset;
        int base;
        int reg_dest;
        lw() {
            strcpy(name,"lw");
        }

};

class sw: public Instruction {
    public:
        int offset,base,mem_dest;
        sw() {
            strcpy(name,"sw");
        }

    };

void add::execute() {
    c = a+b;
    std::cout << "\n\t Adding " << a << " and " << b << " , c = " << c;

};
