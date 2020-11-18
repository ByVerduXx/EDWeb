#ifndef NODO_H
#define NODO_H
#include <iostream>
#include "Pedido.h"

class Nodo
{
    public:
        Nodo(int p,Nodo *sig = NULL);
        ~Nodo();


    private:
        int ped;
        Nodo *siguiente;
        friend class Pila;
        friend class Cola;
        friend class Lista;

};
typedef Nodo *pnodo;
#endif // NODO_H
