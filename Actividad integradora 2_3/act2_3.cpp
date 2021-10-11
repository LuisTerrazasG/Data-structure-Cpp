
#include <vector>
#include "Bitacora.hpp"
#include "listaDL.hpp"
#include <fstream>
#include "ListaCircular_Fallas.hpp"
#include <string>

using namespace std;

int main(){

    
    //Lectura de archivo y creacion de listaDL
    ifstream datos;
    datos.open("bitacora_prueba-1.txt");
    string mes,dia,tiempo,ip,falla;
    ListaDL<Bitacora *> * log=new ListaDL<Bitacora *>(); //Elementos dinámicos
    while(datos.good()){
        getline(datos,mes,' ');//getline(ifstream archivo,string dato,char separador);
        getline(datos,dia,' ');
        getline(datos,tiempo,' ');
        getline(datos,ip,' ');
        getline(datos,falla,'\n');
        log->agregarInicio(new Bitacora(mes,dia,tiempo,ip,falla)); //Creando un nuevo elemento y agregarlo al vector
    }

    
    //Pide al usuario una fecha a buscar y la guarda en un archivo nuevo
    ofstream Archivohora("Archivo hora buscada.txt");
    string hora_input;
    cout<<"Ingrese una hora para buscar en la lista: ";
    cin >> hora_input;
    Archivohora << "Hora elegida a buscar: "<< hora_input << "\n";

    Nodo<Bitacora *> * elemento=log->head;
    while(elemento){
                string tiempo = elemento->getValor()->getTiempo();
                string hora;
                hora.append(tiempo,0,2);
                if(hora == hora_input){
                    elemento->getValor()->imprimirEntrada();
                    Archivohora << elemento->getValor()->regresarValores() << "\n";
                }
                elemento=elemento->getSiguiente();
            }
    Archivohora.close();
    cout<< endl;

    //Creacion de objetos tipo falla con las fallas posibles para contar la cantidad de fallas de cada archivo
    Falla * falla1 = new Falla("Failed password for illegal user test");
    Falla * falla2 = new Falla("Failed password for admin");
    Falla * falla3 = new Falla("Failed password for root");
    Falla * falla4 = new Falla("Illegal user");
    Falla * falla5 = new Falla("Failed password for illegal user guest");

    //Lectura de datos para revisar cantidad de fallas
    ifstream datos2;
    datos2.open("bitacora_prueba-1.txt");
    string mes2,dia2,tiempo2,ip2,falla0;
    ListaCS<Falla *> * log2=new ListaCS<Falla *>();
    while(datos2.good()){
        getline(datos2,mes2,' ');
        getline(datos2,dia2,' ');
        getline(datos2,tiempo2,' ');
        getline(datos2,ip2,' ');
        getline(datos2,falla0,'\n');
        log2->revisarFalla(new Falla(mes2,falla0), falla1);
        log2->revisarFalla(new Falla(mes2,falla0), falla2);
        log2->revisarFalla(new Falla(mes2,falla0), falla3);
        log2->revisarFalla(new Falla(mes2,falla0), falla4);
        log2->revisarFalla(new Falla(mes2,falla0), falla5);
    }

    //Agrega los objetos tipo falla a una listaCS
    log2->agregarInicio(falla1);
    log2->agregarInicio(falla2);
    log2->agregarInicio(falla3);
    log2->agregarInicio(falla4);
    log2->agregarInicio(falla5);

    //cout << "Imprimir valores de lista circular:"<< endl;
    //log2->imprimirLista();
    //cout << endl;

    
    //Pide al usuario el tipo de falla a buscar y guarda en un archivo el resultado de la busqueda
    int falla_input;
    vector<string> mess {"Jun", "Jul", "Aug", "Sep", "Oct"};
    //cout << "Que tipo de falla quieres buscar? "<< endl;
    //cout << "1.- Failed password for illegal user test"<< endl;
    //cout << "2.- Failed password for admin"<< endl;
    //cout << "3.- Failed password for root"<< endl;
    //cout << "4.- Illegal user "<< endl;
    //cout << "5.- Failed password for illegal user guest "<< endl;
    //cout << "Selecion: ";
    //cin >> falla_input;
    //cout << endl;
    //falla_input--;

    ofstream ArchivoFallas("Cantidad_Fallas.txt");

    if(falla_input == 1){
        cout<<"Fallas("<<falla1->getFalla()<<"): ";
        cout<< falla1->cant_fallas.at(0)<< endl;
        ArchivoFallas<<"Fallas("<<falla1->getFalla()<<"): ";
        ArchivoFallas<< falla1->cant_fallas.at(0)<< "\n";
        for(int i = 5; i>0 ; i--){
            cout<< log2->mes.at(i-1)<< ": ";
            cout<< falla1->cant_fallas.at(i) <<endl;
            ArchivoFallas<<log2->mes.at(i-1)<< ": ";
            ArchivoFallas<<falla1->cant_fallas.at(i)<< "\n";
        }
    }

    if(falla_input == 1){
        cout<<"Fallas("<<falla2->getFalla()<<"): ";
        cout<< falla2->cant_fallas.at(0)<< endl;
        ArchivoFallas<<"Fallas("<<falla2->getFalla()<<"): ";
        ArchivoFallas<< falla2->cant_fallas.at(0)<< "\n";
        for(int i = 5; i>0 ; i--){
            cout<< log2->mes.at(i-1)<< ": ";
            cout<< falla2->cant_fallas.at(i) <<endl;
            ArchivoFallas<<log2->mes.at(i-1)<< ": ";
            ArchivoFallas<<falla2->cant_fallas.at(i)<< "\n";
        }
    }
    if(falla_input == 2){
        cout<<"Fallas("<<falla3->getFalla()<<"): ";
        cout<< falla3->cant_fallas.at(0)<< endl;
        ArchivoFallas<<"Fallas("<<falla3->getFalla()<<"): ";
        ArchivoFallas<< falla3->cant_fallas.at(0)<< "\n";
        for(int i = 5; i>0 ; i--){
            cout<< log2->mes.at(i-1)<< ": ";
            cout<< falla3->cant_fallas.at(i) <<endl;
            ArchivoFallas<<log2->mes.at(i-1)<< ": ";
            ArchivoFallas<<falla3->cant_fallas.at(i)<< "\n";
        }
    }
    if(falla_input == 3){
        cout<<"Fallas("<<falla4->getFalla()<<"): ";
        cout<< falla4->cant_fallas.at(0)<< endl;
        ArchivoFallas<<"Fallas("<<falla4->getFalla()<<"): ";
        ArchivoFallas<< falla4->cant_fallas.at(0)<< "\n";
        for(int i = 5; i>0 ; i--){
            cout<< log2->mes.at(i-1)<< ": ";
            cout<< falla4->cant_fallas.at(i) <<endl;
            ArchivoFallas<<log2->mes.at(i-1)<< ": ";
            ArchivoFallas<<falla4->cant_fallas.at(i)<< "\n";
        }
    }
    if(falla_input == 4){
        cout<<"Fallas("<<falla5->getFalla()<<"): ";
        cout<< falla5->cant_fallas.at(0)<< endl;
        ArchivoFallas<<"Fallas("<<falla5->getFalla()<<"): ";
        ArchivoFallas<< falla5->cant_fallas.at(0)<< "\n";
        for(int i = 5; i>0 ; i--){
            cout<< log2->mes.at(i-1)<< ": ";
            cout<< falla5->cant_fallas.at(i) <<endl;
            ArchivoFallas<<log2->mes.at(i-1)<< ": ";
            ArchivoFallas<<falla5->cant_fallas.at(i)<< "\n";
        }
    }


    
    
}

