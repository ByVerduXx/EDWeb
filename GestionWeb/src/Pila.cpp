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

void Pila::apilar(Pedido p){
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
Pedido Pila::mostrarCima(){
    return cima->ped;
}
void Pila::verPila(){
    pnodo aux = cima;
    while(aux != NULL){
        aux->ped.to_string();
        cout << "-------------------" << endl;
        aux = aux->siguiente;
    }
}
