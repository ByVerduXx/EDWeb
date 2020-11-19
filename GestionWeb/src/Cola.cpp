#include "Cola.h"
#include <iostream>
Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;

}

Cola::~Cola()
{
    //dtor
}
void Cola::encolar(int p){
    pnodo nuevo = new Nodo(p);
    if(esVacia()){
        primero = nuevo;
        ultimo = nuevo;
    }
    else{
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
    longitud++;
}
void Cola::desencolar(){
    if(!esVacia()){
        pnodo aux = primero;
        if((primero == ultimo) && (primero->siguiente == NULL)){
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete(aux);
        }
        else{
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete(aux);
        }
        longitud--;
    }
}
int Cola::prim(){
    return primero->ped;
}
int Cola::ult(){
    return ultimo->ped;
}
bool Cola::esVacia(){
    return  (primero==NULL);
}
void Cola::verCola(){
    pnodo aux = primero;
    while(aux != NULL){
        cout << aux->ped << endl;                               //implementar pediodos es ped.to_string
        cout << "-------------------" << endl;
        aux = aux->siguiente;
    }
}
