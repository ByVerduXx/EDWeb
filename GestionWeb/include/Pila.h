#ifndef PILA_H
#define PILA_H
#include "Nodo.h"
#include "Pedido.h"

class Pila
{
    public:
        Pila();
        ~Pila();
        bool esVacia();
        void apilar(int p);
        void desapilar();
        int mostrarCima(); //cambiar int por pedido cuando se implemente
        void apilarOrdenado(int p);   //falta implementar cuando esten los pedidos
        void verPila(); //funcion hecha solo para fines de comprension de la practica
    private:
        pnodo cima;
};

#endif // PILA_H
