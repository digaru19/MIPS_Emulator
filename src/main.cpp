#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include "helper.h"

using namespace std;

Registers RegisterFile ;

int main() {

    char s[50],t[50] ;
    char *p ;
    int i=0;
    int x,y,z;

    vector <char[10]> tokens("",6);

    vector< Instruction* > functions;

    while(i<4) {
    cout << "\n Enter string :-  ";
    cin.getline(s,49);
    strcpy(t,s);
    p = strtok(s," ,");
   // while(p!=NULL) {
    cout << "  " << p << "\n";
    if(strcmp(p,"add")==0) {
        p = strtok(NULL," ,()");
        x = atoi(p);
        //cout << " then :- " << p << "  " << x << "\n";

        p = strtok(NULL," ,");
        y = atoi(p);
        //cout << " then :- " << p << "  " << y << "\n";

        p = strtok(NULL," ,");
        z = atoi(p);
        //cout << " then :- " << p << "  " << z << "\n";

        add *k = new add(t,x,y,z);
        //k->execute();
        functions.push_back( k );
    }

    i++;
    }
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
