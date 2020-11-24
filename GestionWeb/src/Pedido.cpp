#include "Pedido.h"
#include "iostream"
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
using namespace std;

//Variables auxiliares para constructores
string VIP = "VIP";
string NVIP = "NVIP";
string NR ="NR";
Pedido::Pedido(){

}
Pedido::Pedido(string datos)
{

    erroneo = false;

    string n,c,d,tp,tj;
    int t,contador = 0;
    string str;

    size_t posicion = datos.find("//");
    str = datos.substr(0,posicion);
    n = str;
    datos.erase(0,posicion+2);

    while((contador < 5) && !datos.empty()){
        posicion = datos.find("//");
        str = datos.substr(0,posicion);

        switch(contador){
            case(0): c = str; break;
            case(1): d = str; break;
            case(2): tp = str; break;
            case(3): tj = str;  break;
            case(4):
                try{
                    t = stoi(str);
                }
                catch(exception e){
                    cout << "Pedido erroneo: tiempo no válido" << endl;
                    t = (rand() % 10) + 1;
                    erroneo = true;
                }
                break;

        }
        if(posicion == 4294967295){
            datos.erase(0,strlen(datos.c_str()));
        }
        else{
            datos.erase(0,posicion+2);
        }
        contador++;
    }
    if (contador == 5){
        nombre = n;
        ncliente = c;
        direccion = d;
        tipo = tp;
        tarjeta = tj;
        tiempo = t;
    }
    else{
        erroneo = true;
        cout << "Pedido erroneo: faltan datos(completado del pedido automatico)" << endl;
        switch(contador){
        case(0):
            nombre = n;
            ncliente = "No rellenado";
            direccion = "Calle no especificada";
            tipo = "NR";;
            tarjeta = to_string((rand() % 100000000));
            tiempo = (rand() % 10) + 1;
            break;
        case(1):
            nombre = n;
            ncliente = c;
            direccion = "Calle no especificada";
            tipo = "NR";
            tarjeta = to_string((rand() % 100000000));
            tiempo = (rand() % 10) + 1;
            break;
        case(2):
            nombre = n;
            ncliente = c;
            direccion = d;
            tipo = "NR";
            tarjeta = to_string((rand() % 100000000));
            tiempo = (rand() % 10) + 1;
            break;
        case(3):
            nombre = n;
            ncliente = c;
            direccion = d;
            tipo = tp;
            tarjeta = to_string((rand() % 100000000));
            tiempo = (rand() % 10) + 1;
            break;
        case(4):
            nombre = n;
            ncliente = c;
            direccion = d;
            tipo = tp;
            tarjeta = tj;
            tiempo = (rand() % 10) + 1;
            break;
        }



    }


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
        cout << "Pedido erroneo: tipo de cliente mal especificado(automatico NR)" << endl;
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

void Pedido::toStr(){
    cout << "Producto: " << nombre << endl;
    cout << "Nombre Cliente: " << ncliente << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Categoria: " << tipo << endl;
    cout << "Tiempo de preparacion: " << tiempo << " minuto(s)" << endl;
    cout << "Tarjeta de credito: " << tarjeta << endl;
    cout << "Numero de prioridad: " << prioridad << endl;
}
