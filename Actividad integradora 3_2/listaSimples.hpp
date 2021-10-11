#include <iostream>
//Listas

using namespace std;

template <typename objeto>
class Nodo{
    //Atributos
    objeto valor;
    Nodo * siguiente;
    public:
        //get
        objeto getValor(){return this->valor;}
        Nodo * getSiguiente(){return this->siguiente;}
        //set
        void setValor(objeto valor){this->valor=valor;}
        void setSiguiente(Nodo * siguiente){this->siguiente=siguiente;}
        //constructor
        Nodo(objeto valor,Nodo * siguiente){
            this->valor=valor;
            this->siguiente=siguiente;
        }
};

template <typename objeto>
class Lista{
    //Atributos
    Nodo<objeto> * head;
    int tam;
    public:
        //Metodos get y set        
        Nodo<objeto> * getHead(){return this->head;}
        int getTam(){return this->tam;}
        void setHead(Nodo<objeto> * head){this->head=head;}
        void setTam(int tam){this->tam=tam;}
        //Método constructor
        Lista(){
            this->head=nullptr;
            this->tam=0;
        }
        //Operaciones de la lista

        //Agregar un nodo al inicio de la lista
        void agregarInicio(objeto valor){
            Nodo<objeto> * nuevo=new Nodo<objeto>(valor,this->head); // Creando el nuevo nodo
            this->head=nuevo; //Actualizar la head de la lista
            this->tam++; //Actualizamos el tamaño
        }

        //Agregar un nodo al final de la lista
        void agregarFinal(objeto valor){
            Nodo<objeto> * nuevo=new Nodo<objeto>(valor,nullptr);
            if(this->head){//Verificar si la lista esta vacia
                Nodo<objeto> * elemento=this->head;
                while(elemento->getSiguiente())
                    elemento=elemento->getSiguiente();
                elemento->setSiguiente(nuevo);                
            }else{
                this->head=nuevo;
            }
            this->tam++;
        }
        
        //Imprimir los nodos de la lista
        void imprimirLista(){
            Nodo<objeto> * elemento=this->head;
            while(elemento){
                cout<<elemento->getValor()<<" ";
                elemento=elemento->getSiguiente();
            }
            cout<<endl;
        }

        //Funcion create
        void create(objeto valor){
            agregarFinal(valor);

        }

        //Funcion read
        Nodo<objeto> * read(int posicion){
            int contador = 0;
            Nodo<objeto> * elemento=this->head;
            if (this->tam > posicion){
                while(elemento){
                    if(posicion == contador){
                        return elemento;
                    }
                    elemento=elemento->getSiguiente();
                    contador++;
                }
            }
            else{
                return 0;
            }
        }

        //Funcion update
        void update(int posicion,objeto nuevo_valor){

            if(this->tam > posicion){
                Nodo<objeto> * elemento=this->read(posicion);
                int elemento2= elemento->getValor();
                elemento->setValor(nuevo_valor);
                cout << "Valor anterior: "<< elemento2 << "\nValor nuevo: " << nuevo_valor << endl;
            }
            else{
                cout<< "¡¡¡Que no entiendes, no estas en el rango!!!"<< endl;
            }
        }

        //Funcion del
        Nodo<objeto> * del(int posicion){
            int count = 0;
            Nodo<objeto> * elemento=this->head;
            Nodo<objeto> * el_temporal=this->head;
            
            if (this->tam > posicion){
                if (posicion > 0){
                    while(elemento){
                        if(posicion == count){
                            el_temporal = elemento->getSiguiente(); 
                        }
                        elemento=elemento->getSiguiente();
                        count++;
                    }   
                    elemento= this->head;
                    count = 0;
                    while(elemento){
                        if(posicion-1 == count){
                            elemento->setSiguiente(el_temporal);
                        }
                        elemento=elemento->getSiguiente();
                        count++;
                        }
                    }
                else{
                    this->setHead(elemento->getSiguiente());
                }

            }
            else{
                cout<< "¡¡¡Que no entiendes, no estas en el rango!!!"<< endl;
            }

        }

            
};