#include "Nodo.h"

Nodo::Nodo(int p,Nodo *sig)
{
    ped = p;
    siguiente = sig;
}

Nodo::~Nodo()
{
    //dtor
}
