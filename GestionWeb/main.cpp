#include <iostream>
#include "Nodo.h"
#include "Pila.h"
using namespace std;

int main()
{
    cout << "Hola pepe" << endl;
    Pila p;
    p.apilar(3);
    p.apilar(4);
    cout << p.mostrarCima() << endl;
    p.desapilar();
    cout << p.mostrarCima() << endl;
    return 0;
}
