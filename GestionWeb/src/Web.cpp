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
    if(p.prioridad == 2 || p.prioridad == 1){
        colaReg.encolar(p);
    }
    else{
        colaNR.encolar(p);
    }
}


int Web::introducirTxt(){
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
    cout<<colaReg.esVacia()<<endl;
    while(contador<n && !c.esVacia()){
                cout<<"ENTRA2"<<endl;
                cout<<c.prim().erroneo<<endl;
                //Algo le pasa al primero de la cola
        if(c.prim().erroneo){
             cout<<"ERRONEO"<<endl;
            pilaErroneos.apilar(c.prim());
            c.desencolar();
        }
        else{
            cout<<"LISTA"<<endl;
            listaEnviar.insertarOrdenado(c.prim());
            contador++;
            c.desencolar();
        }
    }
    cout<<"SALE"<<endl;
}

void Web::pasarTiempo(){
    colaReg.verCola();
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
        cout<<"ENTRA COLA REG"<<endl;
        incluirListaEnvios(colaReg,3);
        cout<<"SALE COLA REG"<<endl;
        if(!pilaErroneos.esVacia()){
            //Caso 1
            if(pilaErroneos.mostrarCima().getPrioridad()!=0){
                listaEnviar.insertarOrdenado(pilaErroneos.mostrarCima());
                pilaErroneos.desapilar();
            }
            //Caso 2
            else if(!colaNR.esVacia()){
                incluirListaEnvios(colaNR,1);
            }
            //Caso 3
            else{
                listaEnviar.insertarOrdenado(pilaErroneos.mostrarCima());
                pilaErroneos.desapilar();
            }
        }
        else{
            incluirListaEnvios(colaNR,1);
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
    if(continuar != 'N'){
        cout<<"Todos los pedidos introducidos del sistema han sido enviados exitosamente."<<endl;
    }
    else{
       cout<<"Se ha parado el procesado de pedidos, aunque hay pedidos pendientes de envío."<<endl;
    }
}
void Web::mostrarColas(){
    cout << "Cola de Registrados:\n";
    colaReg.verCola();
    cout << "\nCola de No Registrados\n";
    colaNR.verCola();
}
void Web::mostrarPila(){
    cout<<"Pila erroneos:"<<endl;
    pilaErroneos.verPila();
}
void Web::mostrarLista(){
    cout<<"Lista enviar:"<<endl;
    listaEnviar.verLista();

}
