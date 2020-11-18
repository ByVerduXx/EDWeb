#include <iostream>
#include "Nodo.h"
#include "Pila.h"
#include "Lista.h"
using namespace std;

int main()
{
    cout << "Hola pepo" << endl;
    Lista l;
    l.insertarIzq(3);
    l.insertarDer(4);
    cout << l.prim() << endl;
    cout << l.ult() << endl;
    l.eult();
    cout << l.es_vacia() << endl;
    l.eult();
    cout << l.es_vacia() << endl;
    return 0;
}
// Inserta por la izquierda, muestra prim y ult y resto , derecha ok
