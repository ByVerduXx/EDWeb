#include <iostream>
#include "Nodo.h"
#include "Pila.h"
#include "Cola.h"
#include "Lista.h"

#include<fstream>
#include<cstdlib>
using namespace std;

int main()
{
    cout << "Hola buenas tardes" << endl;
    ifstream fe("Pedidos.txt");
    string str;

    while(!fe.eof()){
        getline(fe,str);
        if(!str.empty()){
            cout<<str<<endl;
        }
    }
    fe.close();
    Pedido p = Pedido("Ordenador//Dani//Calle 32//Prueba//124352362626//5");
    p.toStr();
    return 0;
}
