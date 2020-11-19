#ifndef COLA_H
#define COLA_H
#include "Nodo.h"
#include "Pedido.h"

class Cola
{
    public:
        Cola();
        ~Cola();
        void encolar(int p);
        void desencolar();
        int prim();
        int ult();
        bool esVacia();
        void verCola();  //funcion hecha con fines de comprension de la practica
    private:
        pnodo primero;
        pnodo ultimo;
        int longitud;
};

#endif // COLA_H
