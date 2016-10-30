#include <iostream>
#include <vector>
#include <stdlib.h>
#include "datapath_elements.h"
#include "datapath_elements.cpp"
#include "instructions.h"
#include "instructions.cpp"
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

_Instruction_Memory InstructionMemory;
Registers RegisterFile ;
Main_Memory DataMemory ;

int main() {

    char s[50],t[50] ;
    char *p;
    int i=0;
    int x,y,z,j=0;
    ifstream mips_code("code.mips");

    while(!mips_code.eof()) {
    mips_code.getline(s,40);
    InstructionMemory.add_instruction(s);
    i++;
    }
    cout<< "\n\n\t Beginning execution .. ";
    cin.ignore();
    cout << "\n\n";
    i = 0;

    bool d = true;

    while(InstructionMemory.PC_is_valid()) {

    cout << "\n";
    InstructionMemory.display_instr();
    InstructionMemory.execute_next();
    //cout << "\n";
    cout << "\n\t Register[t2]  =  " << RegisterFile.read_reg(10);

    cout << "\n\t PC = " << InstructionMemory.get_PC();
    cin.ignore();
    /*for(int e=0;e<=31;e++) {
        cout << "\n\t Register[" << e << "]  =  " << RegisterFile.read_reg(e);
    }
    */

    }

    return 0;

    /*
    if(strcmp(p,"add")==0) {
        p = strtok(NULL," ,()");
        //cout << " then :- " << p << "  " << x << "\n";
        p = strtok(NULL," ,");
        //cout << " then :- " << p << "  " << y << "\n";
        p = strtok(NULL," ,");

        //cout << " then :- " << p << "  " << z << "\n";

        add *k = new add(t,x,y,z);
        //k->execute();
        functions.push_back( k );
    }
    */

    cout << "\n\n ## Finished \n";
   // cout << "\n\n\t Size of functions :- " << functions.size();

}
