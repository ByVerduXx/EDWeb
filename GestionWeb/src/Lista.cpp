#include "Lista.h"
#include "iostream"
#include "Pedido.h"
Lista::Lista()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

Lista::~Lista()
{
    //dtor
}

void Lista::insertarIzq(Pedido p){
    pnodo nuevo = new Nodo(p);
    if(es_vacia()){
        primero = nuevo;
        ultimo = nuevo;
    }
    else{
        nuevo->siguiente = primero;
        primero= nuevo;
    }
    longitud++;
}

void Lista::insertarDer(Pedido p){
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
    longitud++;
}
void Lista::insertarOrdenado(Pedido p){
    if(!es_vacia()){

        Nodo *nuevo = new Nodo(p);
        Nodo *aux = ultimo;
        if(ultimo->ped.getPrioridad()==p.getPrioridad()){
            insertarDer(p);
        }
        else{
            //Utilizando un puntero auxiliar buscamos la posición que tenga la misma prioridad que nuestro elemento a insertar.
            while(aux->siguiente->ped.getPrioridad()!=p.getPrioridad()){
                    aux = aux->siguiente;
            }
            //Al encontrarlo colocamos el nuevo Nodo entre auxiliar y el siguiente a auxiliar
            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
        }
        longitud++;
    }
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
        longitud--;
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
        longitud--;
    }

}
bool Lista::es_vacia(){
    return(longitud == 0);
}
Pedido Lista::prim(){
    return primero->ped;
}
Pedido Lista::ult(){
    return ultimo->ped;
}
int Lista::lon(){
    return longitud;
}
void Lista::verLista(){
    pnodo aux = primero;
    while(aux != NULL){
        aux->ped.toStr();
        cout << "-------------------" << endl;
        aux = aux->siguiente;   //poner ped.to_string
    }
}
