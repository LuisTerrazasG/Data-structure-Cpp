
#include <vector>
#include "Bitacora.hpp"
#include <fstream> //Biblioteca para lectura y escritura de archivos

using namespace std;

int main(){
    
    //Pide al ususario una fecha de inicio y fin de buaqueda en archivo
    string fech_inico_mes,fech_inico_dia,fech_fin_mes,fech_fin_dia;
    cout << "Desde que fecha quieres buscar? "<< endl;
    cout << "Mes: ";
    cin >> fech_inico_mes;
    cout << "Dia: ";
    cin >> fech_inico_dia;
    cout << "Hasta que fecha quieres buscar? "<< endl;
    cout << "Mes: ";
    cin >> fech_fin_mes;
    cout << "Dia: ";
    cin >> fech_fin_dia;

    Bitacora *fecha_inicial; 
    fecha_inicial=new Bitacora(fech_inico_mes,fech_inico_dia);
    Bitacora *fecha_final; 
    fecha_final=new Bitacora(fech_fin_mes,fech_fin_dia);

    fecha_inicial->asignarId();
    fecha_final->asignarId();


    int * arreglo;//<-Creando un apuntador a un arreglo de enteros
    Bitacora *prueba; //Creando el apuntador para guardar el objeto creado
    prueba=new Bitacora("Oct", "09", "10:32:24", "423.2.230.77:6166", "Failed password for illegal user guest");
    //prueba->asignarId();
    //prueba->imprimirEntrada();
    
    //Escritura de archivos
    //r->read   ifstream 
    //w->write creaba el archivo si no existia o lo sobreescribia  ofstream
    //a->append creaba el archivo si no existia o agregaba el nuevo contenido si el archivo ya existia   fstream

 
    //Lectura de archivos
    
    ifstream datos;
    datos.open("bitacora.txt");

    string entrada;
    /* while(getline(datos, entrada)) //getline(ifstream archivo,string linea)
        cout<<entrada<<endl;
    */
    datos.close();
    
    datos.open("bitacora.txt");
    string mes,dia,tiempo,ip,falla;
    vector<Bitacora *> log; //Elementos dinámicos
    while(datos.good()){
        getline(datos,mes,' ');//getline(ifstream archivo,string dato,char separador);
        getline(datos,dia,' ');
        getline(datos,tiempo,' ');
        getline(datos,ip,' ');
        getline(datos,falla,'\n');
        log.push_back(new Bitacora(mes,dia,tiempo,ip,falla)); //Creando un nuevo elemento y agregarlo al vector
    }

    ordenaQuicksort_Obj(log,0, log.size()-1);
    
    for(Bitacora * entrada:log){

        if (entrada->getId() >= fecha_final->getId()){
            break;
        }
        if (entrada->getId() >= fecha_inicial->getId()){
            entrada->imprimirEntrada();
        }
        
    }
    ofstream miArchivo("ArchivosOrdenados.txt"); //Tipo de dato para crear y escribir archivos
    for(Bitacora * entrada:log)
        miArchivo<< entrada->getMes()<<" "<<entrada->getDia()<<" "<<entrada->getTiempo()<<" "<<entrada->getIp()<<" "<<entrada->getFalla() <<"\n";    

    miArchivo.close(); 
    

    return 0;
}

