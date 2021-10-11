#include <iostream>

//Lista doblemente ligada 

using namespace std;

template <typename objeto>
class Nodo{
    //Atributos
    public:
    objeto valor;
    Nodo<objeto> * siguiente;
    Nodo<objeto> * anterior;
    public:
        //get
        objeto getValor(){return this->valor;}
        Nodo * getSiguiente(){return this->siguiente;}
        Nodo * getAnterior(){return this->anterior;}
        //set
        void setValor(objeto valor){this->valor=valor;}
        void setSiguiente(Nodo * siguiente){this->siguiente=siguiente;}
        void setAnterior(Nodo * anterior){this->anterior=anterior;}
        //constructor
        Nodo(objeto valor,Nodo * siguiente,Nodo * anterior){
            this->valor=valor;
            this->siguiente=siguiente;
            this->anterior=anterior;
        }
        
};


template <typename objeto>
class ListaDL{

    //Atributos
    public:
    Nodo<objeto> * head;
    int tam;
    public:
        Nodo<objeto> * getHead(){return this->head;}
        int getTam(){return this->tam;}
        void setHead(Nodo<objeto> * head){this->head=head;}
        void setTam(int tam){this->tam=tam;}

        ListaDL(){
            this->head=nullptr;
            this->tam=0;
        }

        void agregarInicio(objeto valor){

            Nodo<objeto> * nuevo=new Nodo<objeto>(valor,this->head,nullptr); 
            if(this->head) 
                this->head->setAnterior(nuevo);
            this->head=nuevo; 
            this->tam++; 
        }

        void agregarFinal(objeto valor){
            Nodo<objeto> * nuevo=new Nodo<objeto>(valor,nullptr,nullptr);
            Nodo<objeto> * elemento=this->head; 
            if(elemento){
                while(elemento->getSiguiente()){
                    elemento=elemento->getSiguiente();
                }
                elemento->setSiguiente(nuevo); 
                nuevo->setAnterior(elemento);  
            }else{
                this->head=nuevo; 
            }
            this->tam++;
        }
        
        void imprimirLista(){
            Nodo<objeto> * elemento=this->head;
            while(elemento){
                cout<<elemento->getValor()<<" ";
                elemento=elemento->getSiguiente();
            }
            cout<<endl; 
        
        }
        //Imprimimos los valores de la lista alrevés
        void imprimirListaRev(){
            Nodo<objeto> * elemento=this->head;            
            if(elemento){
                //Encontrar el último nodo
                while(elemento->getSiguiente())
                    elemento=elemento->getSiguiente();
                //Imprimir los valores del último al primero utilizando el apuntador anterior de los nodos
                while(elemento){
                    cout<<elemento->getValor()<<" ";
                    elemento=elemento->getAnterior();
                }
            }
            cout<<endl;   
        }


};