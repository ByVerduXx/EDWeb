#ifndef COLA_H
#define COLA_H
#include "Nodo.h"

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
    private:
        pnodo primero;
        pnodo ultimo;
        int longitud;
};

#endif // COLA_H
