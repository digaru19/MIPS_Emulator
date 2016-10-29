#include <iostream>
#include <vector>
#include <stdlib.h>
#include "datapath_elements.h"
#include "instructions.h"
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

Registers RegisterFile ;
Main_Memory DataMemory ;

int main() {

    char s[50],t[50] ;
    char *p ;
    int i=0;
    int x,y,z,j=0;
    ifstream mips_code("code.mips");

    vector <string> tokens(6);
    string h;

    vector< Instruction* > functions;
    Instruction *temp;

    while(i<4) {
    tokens.clear();
    j = 0;
    p = NULL;
    //cout << "\n Enter string :-  ";
    //cin.getline(s,49);
    mips_code.getline(s,40);
    strcpy(t,s);
    p = strtok(s," ,()");
    while(p!=NULL && j<50) {
    j++;
    h = p;
    //cout << "\n\t  p = " << p << " , register is :- " << get_reg_no(p);
    tokens.push_back(p);
    p = strtok(NULL," ,()");
    }
    //cout << "\n\t Calling Factory object method .. ";
    temp = Instruction::create_instr_obj(t,tokens);
    if(temp != NULL) {
        cout << "\n\t Instruction created successfully !!";
        functions.push_back(temp);
        }
    else
        cout << "\n\t Failed to create Instruction !!";
    i++;
    }
    cout<< "\n\n\t beginning execution .. ";
    cin.ignore();
    cout << "\n\n";
    for(vector<Instruction *>::iterator m = functions.begin();m!=functions.end();m++)
    {
        (*m)->execute();
        (*m)->instr;
    }
    //cin.ignore();
    cout << "\n";
    for(int e=0;e<=31;e++) {
        cout << "\n\t Register[" << e << "]  =  " << RegisterFile.read_reg(e);
    }
    cin.ignore();

    return 0;

    for(vector<string>::iterator k = tokens.begin();k!=tokens.end();k++)
        cout << "\n\t " << *k;



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

    cout << endl;
    vector< Instruction* >::iterator w;
    for(w=functions.begin();w!=functions.end();w++) {
        cout << (*w)->instr << endl;
        (*w)->execute();
    }
    cout << "\n";
    for(int e=0;e<=31;e++) {
        cout << "\n\t Register[" << e << "]  =  " << RegisterFile.read_reg(e);
    }

    cout << "\n\n ## Finished \n";
   // cout << "\n\n\t Size of functions :- " << functions.size();

}
