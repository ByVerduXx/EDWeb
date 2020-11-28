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

void Web::introducirPedido(Pedido p){ //No sale de aqui la 3º vuelta y no se por que
 if(p.erroneo){
    pilaErroneos.apilarOrdenado(p);

 }
 else{
    if(p.prioridad == 2 || p.prioridad == 1){
        colaReg.encolar(p);
    }
    else{
        colaNR.encolar(p);
    }
 }
}

int Web::introducirTxt(){ //Salir sale del bucle solo que al 3º pedido no muestra el contador y no se si se cierra el fichero
    ifstream fe("Pedidos.txt");
    string str;
    int contador = 0;
    while(!fe.eof()){
        getline(fe,str);
        if(!str.empty()){
            Pedido p = Pedido(str);
            introducirPedido(p);
            contador++;
        }
    }
    fe.close();
    return contador;

}

void Web::incluirListaEnvios(Cola c, int n){ //ERROR
    int contador=0;
    cout<<"ENTRA"<<endl;
    while(contador<n && !c.esVacia()){
        cout<<c.prim().erroneo<<endl;
        if(c.prim().erroneo){
             cout<<"ERRONEO"<<endl;
            pilaErroneos.apilar(c.prim());
            c.desencolar();
        }
        else{
            cout<<"LISTA"<<endl;
            listaEnviar.insertarDer(c.prim());
            contador++;
            c.desencolar();
        }
    }
    cout<<"SALE"<<endl;
}

void Web::pasarTiempo(){
    //Primero insertamos 3 pedidos correctos de usuarios registrados en listaEnviar
    incluirListaEnvios(colaReg,3);
    //Hacemos lo mismo pero 1 pedido de usuarios No registrados
    incluirListaEnvios(colaNR,1);

    char continuar = 'Y';
    while(!listaEnviar.es_vacia() && continuar != 'N'){
        int t = listaEnviar.prim().tiempo;
        while(t>0){
            cout<<"El pedido "<<listaEnviar.prim().nombre<<" esta preparandose, espere "<<t<<" minutos."<<endl;
            t--;
            system("pause");
            system("cls");
        }
        //El pedido ha sido enviado y por tanto mostramos los datos de este y lo eliminamos del sistema
        cout<<"El pedido ha sido enviado."<<endl;
        cout<<"----------------------------------"<<endl;
        listaEnviar.prim().toStr();
        cout<<"----------------------------------"<<endl;
        system("pause");
        system("cls");

        listaEnviar.resto();
        //Incluimos nuevos pedidos teniendo 3 casos
        incluirListaEnvios(colaReg,3);
        if(!pilaErroneos.esVacia()){
            //Caso 1
            if(pilaErroneos.mostrarCima().getPrioridad()!=0){
                listaEnviar.insertarDer(pilaErroneos.mostrarCima());
                pilaErroneos.desapilar();
            }
            //Caso 2
            else if(!colaNR.esVacia()){
                incluirListaEnvios(colaNR,1);
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
        else{
            continuar='Y';
        }

    }
    cout<<"Todos los pedidos introducidos del sistema han sido enviados exitosamente."<<endl;
}
void Web::mostrarColas(){
    cout << "Cola de Registrados:\n";
    colaReg.verCola();
    cout << "\nCola de No Registrados\n";
    colaNR.verCola();
}
