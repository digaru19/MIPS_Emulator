#include <string.h>

#ifndef MY_UNIQUE_INCLUDE_NAME_H
#define MY_UNIQUE_INCLUDE_NAME_H


int get_reg_no(char *reg_name);

class RegFile;
class Instruction {
public:
        virtual void execute() = 0;
        char name[10];


};

class lw;
class sw;
class add : public Instruction {
public:
        int a,b,c;
        add(){
            strcpy(name,"add");
        }
        add(int x,int y) {
            strcpy(name,"add");
            a = x;
            b = y;
        };
        void execute();
} ;

//int get_reg_no(char *);

#endif
