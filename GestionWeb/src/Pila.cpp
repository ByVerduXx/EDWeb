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
void Pila::verPila(){
    pnodo aux = cima;
    while(aux != NULL){
        cout << aux->ped << endl;//cambiar a ped.to_string una vez hayamos implementado los pedidos
        cout << "-------------------" << endl;
        aux = aux->siguiente;
    }
}
