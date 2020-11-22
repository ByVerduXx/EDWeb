#ifndef WEB_H
#define WEB_H
#include "Pedido.h"
#include "Pila.h"
#include "Cola.h"
#include "Lista.h"

class Web
{
    public:
        //Constructores
        Web();
        virtual ~Web();
        //Operaciones
        void introducirPedido(Pedido p); //Introduce un pedido en el sistema.
        void introducirTxt(); //Lee un txt e introduce todos los pedidos en el sistema.
        void pasarTiempo(); //Simula el paso del tiempo y no termina hasta que todo este enviado.

    private:
        //Atributos
        Pila pilaErroneos;
        Cola colaReg;
        Cola colaNR;
        Lista listaEnviar;
};

#endif // WEB_H
