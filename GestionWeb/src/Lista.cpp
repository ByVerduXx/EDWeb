#include "Lista.h"
#include "iostream"
Lista::Lista()
{
    primero = NULL;
    ultimo = NULL;
}

Lista::~Lista()
{
    //dtor
}

void Lista::insertarIzq(int p){
    pnodo nuevo = new Nodo(p);
    if(es_vacia()){
        primero = nuevo;
        ultimo = nuevo;
    }
    else{
        nuevo->siguiente = primero;
        primero= nuevo;
    }
}

void Lista::insertarDer(int p){
    pnodo nuevo = new Nodo(p);
    if(es_vacia()){
        primero = nuevo;
        ultimo = nuevo;
    }
    else{
        ultimo->siguiente = nuevo;
        nuevo->siguiente = NULL;
        ultimo= nuevo;
    }
}
void Lista::insertarOrdenado(int p){

}

void Lista::resto(){
    if(!es_vacia()){
        pnodo borrar = primero;
        if ((primero==ultimo) && (primero->siguiente = NULL)){
            primero=NULL;
            ultimo=NULL;
            borrar->siguiente = NULL;
            delete(borrar);
        }
        else{
            primero = primero->siguiente;
            borrar->siguiente = NULL;
            delete(borrar);
        }
    }

}
void Lista::eult(){
    pnodo p,aux;
    if(!es_vacia()){
        p = primero;
        if(p->siguiente == NULL){
            primero = NULL;
            delete(p);
        }
        else{
            while (p->siguiente->siguiente != NULL){
                p = p->siguiente;
            }
            aux = p->siguiente;
            p->siguiente = NULL;
            delete(aux);
        }
    }

}
bool Lista::es_vacia(){
    return (primero==NULL);
}
int Lista::prim(){
    return primero->ped;
}
int Lista::ult(){
    return ultimo->ped;
}
