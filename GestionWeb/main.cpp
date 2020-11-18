#include <iostream>
#include "Nodo.h"
#include "Pila.h"
#include "Cola.h"
using namespace std;
void comprobador(Cola c){
    if (c.esVacia()){
        cout << "Dani es el mejor" << endl;
    }
    else{
        cout << "Javi es el mejor" << endl;
    }
}
int main()
{
    cout << "Javi es Arceus" << endl;
    Cola c;
    c.encolar(3);
    comprobador(c);
    c.desencolar();
    comprobador(c);


    return 0;
}
