#include "Pila.h"
#include <iostream>
Pila::Pila()
{
    cima = NULL;
}

Pila::~Pila()
{
    //dtor
}

bool Pila::esVacia(){return cima == NULL;}
void Pila::apilar(int p){
    pnodo nuevo = new Nodo(p,cima);
    cima = nuevo;
}
void Pila::desapilar(){
    pnodo borrar;
    if(cima){
        borrar = cima;
        cima = borrar->siguiente;
        delete(borrar);
    }
}
int Pila::mostrarCima(){
    return cima->ped;
}
