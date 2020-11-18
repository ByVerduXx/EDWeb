#include "Pedido.h"
#include "iostream"
using namespace std;

//Variables auxiliares para constructores
string VIP = "VIP";
string NVIP = "NVIP";
string NR ="NR";

Pedido::Pedido(string datos)
{
    //Falta por implementar pedidos
}

Pedido::Pedido(string n, string c, string d , string tp , string tj, int t){
    nombre=n;
    ncliente=c;
    direccion=d;
    tipo=tp;
    tarjeta=tj;
    tiempo = t;

    if(strcmp(VIP.c_str(),tp.c_str()) == 0){
            prioridad = 2;

    }
    else if (strcmp(NVIP.c_str(),tp.c_str())){
            prioridad = 1;
    }
    else if(strcmp(NVIP.c_str(),tp.c_str())){
            prioridad = 0;
    }
    else{
        cout<<"Error el tipo introducido no es valido"<<endl;
        prioridad =-1;

    }

}
Pedido::~Pedido()
{
    //dtor
}
string Pedido::getTipo(){
    return tipo;
}
int Pedido::getPrioridad(){
    return prioridad;
}
string Pedido::mostrarPedido(){
    return nombre+"//"+ncliente+"//"+direccion+"//"+tipo+"//"+tarjeta+"//"+to_string(tiempo);

}
