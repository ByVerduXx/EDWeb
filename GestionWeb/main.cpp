#include <iostream>
#include "Nodo.h"
#include "Pila.h"
#include "Cola.h"
#include "Lista.h"
#include <ctime>
#include<fstream>
#include<cstdlib>
using namespace std;

int main()
{
    srand((int) time (0));
    cout << "Hola don pepito" << endl;
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
    Pedido x = Pedido("Ordenador//Jose//Calle 32//VIP//124352362626//5");
    Pedido r = Pedido("Ordenador//XD//Calle 32//NVIP//124352362626//5");
    Pedido hola = Pedido("Ordenador//FFFFF//Calle 32//NR//124352362626//5");
    Pedido adios = Pedido("Ordenador//FFFFF//direccion1");
    Pila aux;
    aux.apilarOrdenado(p);
    aux.apilarOrdenado(x);
    aux.apilarOrdenado(r);
    aux.apilarOrdenado(hola);
    aux.apilarOrdenado(adios);
    aux.verPila();
    return 0;
}
