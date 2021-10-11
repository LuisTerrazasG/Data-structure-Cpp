#include <vector>
#include <fstream>
#include <string>
#include "accesoIp.hpp"
#include "Bitacora.hpp"
#include "arbolbinario.hpp"


using namespace std;

int main(){

    //Abre el archivo deaseado
    ifstream datos;
    datos.open("bitacoraPrueba.txt");
    //Declara variables para leer datos y crea listaDL
    string mes,dia,tiempo,ip,falla;
    ListaDL<AccesoIp *> * log=new ListaDL<AccesoIp *>(); //Elementos dinámicos
    
    //Lee el archivo selecionado
    //BigO(n^2)
    while(datos.good()){
        bool sumar = false;
        Nodo<AccesoIp *> * elemento = log->getHead();
        getline(datos,mes,' ');//getline(ifstream archivo,string dato,char separador);
        getline(datos,dia,' ');
        getline(datos,tiempo,' ');
        getline(datos,ip,' ');
        getline(datos,falla,'\n');
        //Revisa si el valor de ip existe en la listaDL, si no esta lo agrega a la lista, si esta en la lista suma 1 a la cantidad de fallas del objeto.
        while(elemento){
            if(ip == elemento->getValor()->getIp()){
                elemento->getValor()->sumarFalla();
                sumar = true;
            }  
            elemento = elemento->getSiguiente();
        }
        if (!sumar){
            log->agregarInicio(new AccesoIp(ip)); //Creando un nuevo elemento y agregarlo a la lista
        }   
    }
    datos.close();

    
    //Crea un nuevo archivo que contendra la ip y la cantidad de accesos de esa ip
    ofstream archivoAccesos("Archivo_Accesos.txt");
    Nodo<AccesoIp *> * elemento1 = log->getHead();
    //Revisa toda la listaDL y escribe en el archivo la ip y accesso de el objeto.
    while(elemento1){
        if (elemento1->getValor()->getnumFallas() > 0){
            archivoAccesos << "Ip: " << elemento1->getValor()->getIp() << ", ";
            archivoAccesos << "Accesos: " << elemento1->getValor()->getnumFallas() << endl;
       }
        elemento1 = elemento1->getSiguiente();
    }
    archivoAccesos.close();

    //Crea el arbol binario para ordenar las ips por cantidad de accesos
    BST<string> * arboldeAccesos=new BST<string>(); 
    Nodo<AccesoIp *> * elemento2 = log->getHead();
    while (elemento2){
        //Si encuentra un nodo en el arbol que ya existe agrega la ip del objeto actual a la lista de ips del nodo con esa cantidad de accesos.
        if (!arboldeAccesos->buscaNodo(elemento2->getValor()->getnumFallas())){
            arboldeAccesos->agregarNodoIterativo(elemento2->getValor()->getnumFallas());
        }
        else{
            arboldeAccesos->buscaNodo(elemento2->getValor()->getnumFallas())->agregarIp(elemento2->getValor()->getIp());
        }
        
        elemento2 = elemento2->getSiguiente();
    }

    //Imprime objetos de listaDL
    //cout << "Impresion de objetos en listaDL :"<< endl;
    //log->imprimirLista();
    //cout<< "---------------"<< endl;

    //Imprimir nodos de arbol en orden y preorden
    cout << "Arbol en preorden:"<< endl;
    arboldeAccesos->imprimirArbol(1);
    cout<< endl;
    cout << "Arbol en orden:"<< endl;
    arboldeAccesos->imprimirArbol(2);
    cout<< "---------------"<< endl;


    //Funcion buscar lista de Ip por cantidad de acessos
    int cantAcessos;
    cout<< "Buscar lista de Ips por cantidad de accesos"<< endl;
    cout<< "Num accesos: ";
    cin>> cantAcessos;

    if(arboldeAccesos->buscaNodo(cantAcessos)){
        cout<< "---------------"<< endl;
        cout<< "Ips con cantidad de accesos = "<< cantAcessos<< endl;
        arboldeAccesos->buscaNodo(cantAcessos)->imprimirIps();
    }
    else{
        cout<<"No hay Ips con esa cantidad de accesos." << endl;
    }

    //Elimina objetos creadas
    delete log;
    delete arboldeAccesos;
    
    return 0;
}