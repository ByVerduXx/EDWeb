#include "Pedido.h"
#include "iostream"
#include <string>
#include <string.h>
using namespace std;

//Variables auxiliares para constructores
string VIP = "VIP";
string NVIP = "NVIP";
string NR ="NR";
Pedido::Pedido(){

}
Pedido::Pedido(string datos)
{
    string n,c,d,tp,tj;
    int t,contador = 0;
    string str;
    size_t posicion = datos.find("//");
    str = datos.substr(0,posicion);
    n = str;
    datos.erase(0,posicion+2);
    while((contador < 5)){                  // && !datos.empty()    : para cuando hagamos los pedidos erroneos
        posicion = datos.find("//");
        str = datos.substr(0,posicion);
        switch(contador){
            case(0): c = str; break;
            case(1): d = str; break;
            case(2): tp = str; break;
            case(3): tj = str;  break;
            case(4): t = stoi(str); break;
        }
        datos.erase(0,posicion+2);
        contador++;
    }
    nombre = n;
    ncliente = c;
    direccion = d;
    tipo = tp;
    tarjeta = tj;
    tiempo = t;

    if(strcmp(VIP.c_str(),tp.c_str()) == 0){
            prioridad = 2;

    }
    else if (strcmp(NVIP.c_str(),tp.c_str()) == 0){
            prioridad = 1;
    }
    else if(strcmp(NR.c_str(),tp.c_str()) == 0){
            prioridad = 0;
    }
    else{
        tipo = "NR";
        prioridad = 0;

    }

}

Pedido::Pedido(string n, string c, string d , string tp , string tj, int t){
    nombre=n;
    ncliente=c;
    direccion=d;
    tipo=tp;
    tarjeta=tj;
    tiempo = t;
    erroneo = false;

    if(strcmp(VIP.c_str(),tp.c_str()) == 0){
            prioridad = 2;

    }
    else if (strcmp(NVIP.c_str(),tp.c_str()) == 0){
            prioridad = 1;
    }
    else if(strcmp(NVIP.c_str(),tp.c_str()) == 0){
            prioridad = 0;
    }
    else{
        tipo = "NR";
        prioridad = 0;
        erroneo = true;

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
    cout << "Numero de prioridad: " << prioridad << endl;
}
