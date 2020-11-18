#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"

class Lista
{
    public:
        //Constructores
        Lista();
        virtual ~Lista();
        //Operaciones
        void insertarIzq(int p); //Añade un pedido por la izquierda
        void insertarDer(int p); //Añade un pedido por la derecha
        void insertarOrdenado(int p);//Inserta un pedido a más derecha de su tipo
        void resto();//Elimina el primero elemento de la lista
        void eult(); //Elimina el ultimo elemento de la lista
        bool es_vacia();//Comprueba si una lista es vacia
        int prim(); //Devuelve el primer elemento de la lista
        int ult(); //Devuelve el ultimo elemento de la lista
        int lon();

    private:
        pnodo primero;
        pnodo ultimo;
        int longitud;

};

#endif // LISTA_H
