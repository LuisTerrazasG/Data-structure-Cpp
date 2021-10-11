#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Falla{

    //Variables
    public:
    string mes;
    string falla;
    //Vector que sirve para guarda las ocurrencias de el objeto tipo falla 
    vector<int> cant_fallas {0,0,0,0,0,0};//cant_fallas [fallas_totales,cant_jun,cant_jul,cant_aug,cant_sep,can_oct]

    public:
    //constructor
    Falla(string mes,string falla){
            this->mes=mes;
            this->falla=falla;
            }
    Falla(string falla){
            this->mes="";
            this->falla=falla;
            }
    
    string getMes(){return this->mes;}
    void setMes(string mes){this->mes=mes;}
    string getFalla(){return this->falla;}
    void setFalla(string falla){this->falla=falla;}

    //Suma 1 a cada tipo de falla por posicion en el vector cant_fallas
    void sumarFalla(int posicion){
        cant_fallas.at(posicion)++;
    }
};

template <typename objeto>
class NodoCS{
    //Atributos
    objeto valor;
    NodoCS<objeto>* siguiente;
    public:
        //get
        objeto getValor(){return this->valor;}
        NodoCS * getSiguiente(){return this->siguiente;}
        //set
        void setValor(objeto valor){this->valor=valor;}
        void setSiguiente(NodoCS * siguiente){this->siguiente=siguiente;}
        //constructor
        NodoCS(objeto valor,NodoCS * siguiente){
            this->valor=valor;
            this->siguiente=siguiente;
        }
};

template <typename objeto>
class ListaCS{
    public:
    vector<string> nombre_fallas{"Failed password for illegal user test","Failed password for admin","Failed password for root","Illegal user", "Failed password for illegal user guest"};
    vector<string> mes {"Jun", "Jul", "Aug", "Sep", "Oct"};
    NodoCS<objeto> * last;
    int tam;

    public:
        NodoCS<objeto> * getLast(){return this->last;}
        int getTam(){return this->tam;}
        void setLast(NodoCS<objeto> * last){this->last=last;}
        void setTam(int tam){this->tam=tam;}
        int i;
  
        ListaCS(){
            this->last=nullptr;
            this->tam=0;
        }

        //Funcion que recibe un objeto tipo nodo y un objeto falla para revisar que falla tiene y en que mes
        void revisarFalla(objeto falla, Falla *tipo_falla){
            
            if(falla->falla == tipo_falla->falla){
                    tipo_falla->sumarFalla(0);
                    for(i = mes.size(); i > 0; i--){
                        if(mes[i-1] == falla->getMes()){
                            tipo_falla->sumarFalla(i);
                        }
                    }
            }
        }


        void agregarInicio(objeto valor){
            if(this->last){
                NodoCS<objeto> * nuevo=new NodoCS<objeto>(valor,this->last->getSiguiente());
                this->last->setSiguiente(nuevo);
            }else{ 
                NodoCS<objeto> * nuevo=new NodoCS<objeto>(valor,nullptr); 
                nuevo->setSiguiente(nuevo);
                this->last=nuevo; 
                
            }
            this->tam++;
            
        }


        void agregarFinal(objeto valor){
            if(this->last){ 
                NodoCS<objeto> * nuevo=new NodoCS<objeto>(valor,this->last->getSiguiente());
                this->last->setSiguiente(nuevo);
                this->last=nuevo;
            }else{ 
                NodoCS<objeto> * nuevo=new NodoCS<objeto>(valor,nullptr);
                nuevo->setSiguiente(nuevo); 
                this->last=nuevo; 
            }            
            this->tam++;
        }
        
        void imprimirLista(){ 
            if(this->last){
                NodoCS<objeto> * elemento=this->last->getSiguiente();
                do{
                    cout<<elemento->getValor()<<" ";
                    elemento=elemento->getSiguiente(); 
                }while(elemento!=this->last->getSiguiente());
                cout<<endl;
            }else{
                cout<<"Lista vacía"<<endl;
            }  
        }



};