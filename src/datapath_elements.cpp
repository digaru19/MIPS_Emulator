#include "datapath_elements.h"
#include "instructions.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

// Function to get the register number from the arguments
// passed in the MIPS instruction.
// Example :- $t3 = 11 , $v1 = 3 , $s4 = 20 , etc.
int get_reg_no(string reg) {
    char reg_name[8];
    strcpy(reg_name,reg.c_str());

    if(strcmp(reg_name,"$zero")==0) {
        return 0;
    }
    else if(strcmp(reg_name,"$at")==0) {
        return 1;
    }
    else if(strcmp(reg_name,"$sp")==0) {
        return 29;
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
            return 24+(reg_name[2]-56);
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

    else if(strcmp(reg_name,"$fp")==0) {
        return 30;
    }
    else if(strcmp(reg_name,"$ra")==0) {
        return 31;
    }
    return -1;
};

// Initialize registers to 0
Registers::Registers() {
        for(int i=0;i<32;i++)
            Register[i]=0;
    }

// Member function to read a register using a Register File
int Registers::read_reg(int src_reg) {
        return Register[src_reg];
    };

// Member function to write to a register using a Register File
void Registers::write_reg(int data,int dest_reg) {
        Register[dest_reg] = data;
};

// Initialize all the cells of the main memory to zero
Main_Memory::Main_Memory() {
    for(int i=0;i<400;i++)
            Memory[i]=0;
}

// Public member function to read a memory cell
int Main_Memory::read_mem(int mem_cell) {
    return Memory[mem_cell];
};

// Public member function to write to a memory cell
void Main_Memory::write_mem(int data,int location) {
    Memory[location] = data;
}

_Instruction_Memory::_Instruction_Memory() {
    instructions.reserve(100);
    PC = 0;
    size = 0;
}

void _Instruction_Memory::update_PC(int step) {
    if(PC + step >= 0 && PC + step <= size)
        PC = PC + step;
}

void _Instruction_Memory::add_instruction(string instr) {

    vector <string> tokens(6);
    char s[50],*p;
    Instruction_Set *temp;
    tokens.clear();

    p = NULL;

    strcpy(s,instr.c_str());
    p = strtok(s," ,()");
    while(p!=NULL) {
    tokens.push_back(p);
    p = strtok(NULL," ,()");
    }

    temp = Instruction_Set::create_instr_obj(instr,tokens);
    if(temp != NULL) {
        size++;
        cout << "\n\n\t " << temp->instr << "  ==  Instruction created successfully !! \n\t size = " << size;
        //temp->execute();
        cout << "\n\t Object at :- " << temp;
        instructions.push_back(temp);
        }
    else
        cout << "\n\t Failed to create Instruction !!";
}

void _Instruction_Memory::execute_all() {
    vector<Instruction_Set *>::iterator i ;
    for(i=instructions.begin();i!=instructions.end();i++)
        {
            (*i)->execute();
        }
}

bool _Instruction_Memory::execute_next() {
    if(PC >= size)
        return false;
    instructions[PC]->execute();
    update_PC();
}

void _Instruction_Memory::display_instr() {
    cout << "\n\t" << instructions[PC]->instr;

}
