#include "grafoLista.hpp"
#include "fstream"
#include "string"

int main(){

    ifstream datos;
    datos.open("bitacoraTest1.txt");
    //Declara variables para leer datos y crear grafo
    string mes,dia,tiempo,iporigen,ipdestino,falla;
    Grafo * ejemploGrafo1=new Grafo();
    
    while(datos.good()){
        bool agregar = true;//Estado para agregar conexion al grafo
        getline(datos,mes,' ');
        getline(datos,dia,' ');
        getline(datos,tiempo,' ');
        getline(datos,iporigen,' ');
        getline(datos,ipdestino,' ');
        getline(datos,falla,'\n');
        
        //Si la ip de origen o de destino no existe en el grafo lo agrega
        if(!ejemploGrafo1->buscarNodo(iporigen)){
            ejemploGrafo1->insertarNodoGrafo(iporigen);
        }
        if(!ejemploGrafo1->buscarNodo(ipdestino)){
            ejemploGrafo1->insertarNodoGrafo(ipdestino);
        }

        //Busca la lista de conexiones de iporigen 
        Lista<Conexion *> * conexiones = ejemploGrafo1->buscarNodo(iporigen)->getConexiones();
        Nodo<Conexion *> * auxiliar= conexiones->getHead();
        while(auxiliar){
            if(auxiliar->getValor()->getNombreNodo() == ipdestino){
                agregar = false;//Si la ipdestino esta en la lista de conexiones del origen no lo agrega.
            }
            auxiliar = auxiliar->getSiguiente();
        }
        if(agregar){
            ejemploGrafo1->agregarArco(iporigen,ipdestino,1);//agrega arco al grafo
        }
        
    }
    datos.close();

    //Imprime el grafo generado con el archivo de ips
    ejemploGrafo1->imprimirGrafo();

    //Imprime la o las ips con mayor cantidad de fallas recibidas.
    ejemploGrafo1->cantFallasRecibidas();
    cout<< endl;

    //Imprime la o las ips con mayor cantidad de fallas recibidas.
    ejemploGrafo1->cantFallasGeneradas();
    cout<< endl;
    cout<< endl;

    //Imprime ips en orden DephFirst
    cout<< "Ips en orden DepthFirst:"<< endl;
    cout<< ejemploGrafo1->DepthFisrt(0);
    cout<< endl;
    
    //Almacena en un archivo el resultado del recorrido DepthFirst
    ofstream archivoDepthFirst("Archivo_DepthFirst.txt");
        archivoDepthFirst << ejemploGrafo1->DepthFisrt(0);
    archivoDepthFirst.close();
    return 0;
}