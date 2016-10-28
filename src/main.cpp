#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include "helper.h"

using namespace std;

int main() {

    char s[50] ;
    char *p ;
    int i=0;
    int x,y,z;

    vector< Instruction* > functions;

    cout << atoi("99") << endl;;
    while(i<2) {
    cout << "\n Enter string :-  ";
    cin.getline(s,49);
    p = strtok(s," ,");
   // while(p!=NULL) {
    cout << "  " << p << "\n";
    if(strcmp(p,"add")==0) {
        p = strtok(NULL," ,");
        x = atoi(p);
        cout << " then :- " << p << "  " << x << "\n";

        p = strtok(NULL," ,");
        y = atoi(p);
        cout << " then :- " << p << "  " << y << "\n";

        add *k = new add(x,y);
        k->execute();
        functions.push_back( k );
    }
    //    p = strtok(NULL," ,");
   // }
    i++;
    }

    vector< Instruction* >::iterator w;
    for(w=functions.begin();w!=functions.end();w++) {
        (*w)->execute();
    }


   // cout << "\n\n\t Size of functions :- " << functions.size();

}
