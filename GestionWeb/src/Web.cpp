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
    if(p.prioridad == 2 || p.prioridad== 1){
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
        if(!str.empty()){
            Pedido p = Pedido(str);
            introducirPedido(p);
        }
    }
    fe.close();

}

void Web::incluirColaEnvios(Cola c, int n){
    int contador;
    while(contador<n && !c.esVacia()){
        if(c.prim().erroneo){
            pilaErroneos.apilar(c.prim());
            c.desencolar();
        }
        else{
            listaEnviar.insertarDer(c.prim());
            c.desencolar();
            n++;
        }
    }
}

void Web::pasarTiempo(){
    //Primero insertamos 3 pedidos correctos de usuarios registrados en listaEnviar
    incluirColaEnvios(colaReg,3);
    //Hacemos lo mismo pero 1 pedido de usuarios No registrados
    incluirColaEnvios(colaNR,1);

    char continuar = 'Y';
    while(!listaEnviar.es_vacia() && continuar != 'N'){
        int t = listaEnviar.prim().tiempo;
        while(t>0){
            cout<<"El pedido "<<listaEnviar.prim().nombre<<" esta preparandose, espere "<<t<<" minutos."<<endl;
            t--;
        }
        //El pedido ha sido enviado y por tanto mostramos los datos de este y lo eliminamos del sistema
        cout<<"El pedido ha sido enviado."<<endl;
        //Cambiar luego a toStr()
        listaEnviar.prim().to_string();
        listaEnviar.resto();
        //Incluimos nuevos pedidos teniendo 3 casos
        incluirColaEnvios(colaReg,3);
        if(!pilaErroneos.esVacia()){
            //Caso 1
            if(pilaErroneos.mostrarCima().getPrioridad()!=0){
                listaEnviar.insertarDer(pilaErroneos.mostrarCima());
                pilaErroneos.desapilar();
            }
            //Caso 2
            else if(!colaNR.esVacia()){
                incluirColaEnvios(colaNR,1);
            }
            //Caso 3
            else{
                listaEnviar.insertarDer(pilaErroneos.mostrarCima());
                pilaErroneos.desapilar();
            }
        }
        //Después de realizar esto
        cout<<"¿Quiere continuar al siguiente pedido?(Y:Si,N:No):";
        cin>>continuar;
        if(continuar=='n'){
            continuar='N';
        }

    }
}
