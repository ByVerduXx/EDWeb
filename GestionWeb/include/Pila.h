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
        void apilar(Pedido p);
        void desapilar();
        Pedido mostrarCima();
        void apilarOrdenado(Pedido p);
        void verPila(); //funcion hecha solo para fines de comprension de la práctica
    private:
        pnodo cima;
};

#endif // PILA_H
