#include "Web.h"

#include<fstream>
#include<string>
#include<cstdlib>
Web::Web()
{
    //ctor
}

Web::~Web()
{
    //dtor
}

void Web::introducirPedido(Pedido p){
 if(p.erroneo){
    //pilaErroneos.apilarOrdenado(p);
 }
 else{
    if(p.prioridad ==2 || p.prioridad==1){
        colaReg.encolar(p);
    }
    else{
        colaNR.encolar(p);
    }
 }
}

void Web::introducirTxt(){
    ifstream fe("Pedidos.txt");
    string str;
    while(!fe.eof()){
        getline(fe,str);
        Pedido p = Pedido(str);
        introducirPedido(p);
    }
    fe.close();

}

void Web::pasarTiempo(){

}
