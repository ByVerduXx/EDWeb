#include "Pedido.h"
#include "iostream"
#include <string>
#include <string.h>
using namespace std;

//Variables auxiliares para constructores
string VIP = "VIP";
string NVIP = "NVIP";
string NR ="NR";

Pedido::Pedido(string datos)
{
    string n,c,d,tp,tj;
    int t;
    string str;
    size_t posicion = str.find("//");           //pendiente de terminar que me voy a dormir jajajaja
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

void Pedido::to_string(){
    cout << "Producto: " << nombre << endl;
    cout << "Nombre Cliente: " << ncliente << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Categoria: " << tipo << endl;
    cout << "Tiempo de preparacion: " << tiempo << " minuto(s)" << endl;
}
