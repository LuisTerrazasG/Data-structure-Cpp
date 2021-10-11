#include <iostream>
#include <vector>
//Listas

using namespace std;



template <typename T>
class Nodo{
    //Atributos
    T valor;
    Nodo<T> * siguiente;
    public:
        //get
        T getValor(){return this->valor;}
        Nodo<T> * getSiguiente(){return this->siguiente;}
        //set
        void setValor(T valor){this->valor=valor;}
        void setSiguiente(Nodo<T>* siguiente){this->siguiente=siguiente;}
        //constructor
        Nodo(T valor,Nodo<T> * siguiente){
            this->valor=valor;
            this->siguiente=siguiente;
        }
};

template <typename T>
class Lista{
    //Atributos
    Nodo<T> * head;
    int tam;
    public:
        //Metodos get y set        
        Nodo<T> * getHead(){return this->head;}
        int getTam(){return this->tam;}
        void setHead(Nodo<T> * head){this->head=head;}
        void setTam(int tam){this->tam=tam;}
        //Método constructor
        Lista(){
            this->head=nullptr;
            this->tam=0;
        }
        //Operaciones de la lista

        //Agregar un nodo al inicio de la lista
        void agregarInicio(T valor){
            Nodo<T> * nuevo=new Nodo<T>(valor,this->head); // Creando el nuevo nodo
            this->head=nuevo; //Actualizar la head de la lista
            this->tam++; //Actualizamos el tamaño
        }

        //Agregar un nodo al final de la lista
        void agregarFinal(T valor){
            Nodo<T> * nuevo=new Nodo<T>(valor,nullptr);
            if(this->head){//Verificar si la lista esta vacia
                Nodo<T> * elemento=this->head;
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
            Nodo<T> * elemento=this->head;
            while(elemento){
                cout<<elemento->getValor()<<endl;
                elemento=elemento->getSiguiente();
            }
            cout<<endl;
        }

        //Eliminar un nodo al inicio de la lista
        Nodo<T> * eliminarInicio(){
            if(this->tam==0)
                return nullptr;
            Nodo<T> * eliminado=this->head;
            this->head=this->head->getSiguiente();
            this->tam--;
            return eliminado;
        }

};
    template <typename T>
    class Pila{
        Lista<T> * pila;
        public: 
            Pila(){
                this->pila=new Lista<T>();
            }
            void setPila(Lista<T> pila){this->pila=pila;}
            Lista<T> getPila(){return this->pila;}

            //Meter un elemento a la pila
            void push(T valor){
                this->pila->agregarInicio(valor);
            }
            //Nos regresa el nodo del top sacandolo de la pila
            Nodo<T> * pop(){
                return this->pila->eliminarInicio();
            }
            //Nos regres< el nodeo del top sin sacarlo
            Nodo<T> * top(){
                return this->pila->getHead();
            }

            //Nos regresa si la lista esta vacia o no
            bool isEmpty(){
                if(this->pila->getTam()==0)
                    return true;
                else
                    return false;
            }
            void imprimirPila(){
                this->pila->imprimirLista();
            }

};

class Conexion{
    string nombreNodo;
    int peso;

    public:
        string getNombreNodo(){return this->nombreNodo;}
        int getPeso(){return this->peso;}
        void setNombreNodo(string nombreNodo){this->nombreNodo=nombreNodo;}
        void setPeso(int peso){this->peso=peso;}
        Conexion(string nombreNodo,int peso){
            this->nombreNodo=nombreNodo;
            this->peso=peso;
        }
    
};

class NodoGrafo{
    string nombreNodo;
    int fallasRecibidas;
    Lista<Conexion *> * conexiones;

    public:
        string getNombreNodo(){return this->nombreNodo;}
        int getFallasRecibidas(){return this->fallasRecibidas;}
        Lista<Conexion*> * getConexiones(){return this->conexiones;}
        void setNombreNodo(string nombreNodo){this->nombreNodo=nombreNodo;}
        void setConexiones(Lista<Conexion*> *conexiones){this->conexiones=conexiones;}
        NodoGrafo(string nombreNodo){
            this->nombreNodo=nombreNodo;
            this->conexiones=new Lista<Conexion*>();
        }
    void aumentarFallas(){
        fallasRecibidas++;
    }

};

class Grafo{
    int numNodos;
    Lista<NodoGrafo *> * nodos;

    public:
        Lista<NodoGrafo *> * getNodos(){return this->nodos;}
        void setNodos(Lista<NodoGrafo *> * nodos){this->nodos=nodos;}
        Grafo(){
            this->nodos=new Lista<NodoGrafo *>();
            this->numNodos=0;
        }

        void insertarNodoGrafo(string nombreNodo){
            if(!this->buscarNodo(nombreNodo)){
                this->nodos->agregarInicio(new NodoGrafo(nombreNodo));
                this->numNodos++;
            }
            else
                cout<<"Nombre de nodo ya existente"<<endl;
        }

        //Método para buscar un nodo dentro de la lista de nodos del grafo
        NodoGrafo * buscarNodo(string nombreNodo){
            Nodo<NodoGrafo *> *elemento=this->nodos->getHead();
            while(elemento){
                if(elemento->getValor()->getNombreNodo()==nombreNodo)
                    return elemento->getValor();                
                elemento=elemento->getSiguiente();
            }
            return nullptr;
        }

        //Método para agregar arcos
        void agregarArco(string nodoOrigen,string nodoDestino, int peso){
            NodoGrafo * origen = this->buscarNodo(nodoOrigen); 
            NodoGrafo * destino = this->buscarNodo(nodoDestino);
            if(origen&&destino)//Validar que exista en la lista el nodo origen y destino
                origen->getConexiones()->agregarInicio(new Conexion(nodoDestino,peso));
            else
                cout<<"Ambos nodos del grafo deben existir dentro de la lista"<<endl;
        }

        //Método para imprimir la lista de adyancencia
        void imprimirGrafo(){
            Nodo<NodoGrafo *> *elemento=this->nodos->getHead();
            while(elemento){
                cout<<"Nodo:"<<elemento->getValor()->getNombreNodo();
                Nodo<Conexion *> * auxiliar=elemento->getValor()->getConexiones()->getHead();
                while(auxiliar){
                    cout<<" -> "<<auxiliar->getValor()->getNombreNodo()<<":"<<auxiliar->getValor()->getPeso();
                    auxiliar=auxiliar->getSiguiente();
                }
                cout<<endl;
                elemento=elemento->getSiguiente();
            }
            cout<<endl;                        
        }

        NodoGrafo * buscarId(int id){
            if(id>=0&&id<this->numNodos){
                int aux = 0;
                Nodo<NodoGrafo*> *elemento = this->nodos->getHead();
                while(aux!=id){
                    elemento=elemento->getSiguiente();
                    aux++;
                }
                return elemento->getValor();
            }
            return nullptr;
        }

        int buscarPosicion(string nombreNodo){
            int pos = 0;
            Nodo<NodoGrafo*>* elemento = this->nodos->getHead();
            while(elemento){
                if(elemento->getValor()->getNombreNodo()==nombreNodo)
                    return pos;
                elemento=elemento->getSiguiente();
                pos++;
            }
            return -1;
        }

        //Regresa string con elementos ordenados en DepthFirst
        string DepthFisrt(int id){
            vector<bool> procesados(this->numNodos,false);
            string idOrdenadas;
            Pila<NodoGrafo *> * pila= new Pila<NodoGrafo *>();
            int aux;
            NodoGrafo * elemento;
            procesados[id]=true;
            pila->push(this->buscarId(id));
            while(!pila->isEmpty()){
                elemento=pila->pop()->getValor();
                idOrdenadas = idOrdenadas + elemento->getNombreNodo() + " / ";
                Nodo<Conexion*>*actual = elemento->getConexiones()->getHead();
                while(actual){
                    aux = this->buscarPosicion(actual->getValor()->getNombreNodo());
                    if(!procesados[aux]){
                        procesados[aux]=true;
                        pila->push(this->buscarId(aux));
                    }
                    actual = actual->getSiguiente();
                }
            }
            return idOrdenadas;
        }

        //Regresa todos los elementos con la mayor cantidad de fallas generadas.
        void cantFallasGeneradas(){
            int cantidad = 0;
            vector<string> conMayorCant;//Almacenara todos los elementos con el mayor tamano de conexiones.
            Nodo<NodoGrafo *> *elemento=this->nodos->getHead();
            //Revisa el tamano de la lista conexiones de cada elemento y guarda el valor mas grande.
            while(elemento){
                if(elemento->getValor()->getConexiones()->getTam() > cantidad){
                    cantidad = elemento->getValor()->getConexiones()->getTam();
                }
                elemento=elemento->getSiguiente();
            }
            elemento=this->nodos->getHead();

            //Compara si el tamano de la lista conexiones es igual a la mayor cantidad de conexiones encontradas en un nodo del grafo.
            while(elemento){
                if(elemento->getValor()->getConexiones()->getTam() == cantidad){
                    conMayorCant.push_back(elemento->getValor()->getNombreNodo());
                }
                elemento=elemento->getSiguiente();
            }
            //Imprime el vector de elementos para mostrar los elementos con mayor cantidad de fallas generadas.
            cout << "Ips con mayor fallas generadas: " << endl;
            for(int i=0; i < conMayorCant.size(); i++)
                cout << conMayorCant.at(i) << '/';
        }

        //Regresa todos los elementos con la mayor cantidad de fallas recibidas.
        void cantFallasRecibidas(){
            int cantidad = 0;
            Nodo<NodoGrafo *> *elemento=this->nodos->getHead();
            vector<string> conMayorCant;//Almacenara todos los elementos con el mayor tamano de fallas recibidas.

            //Busca en cada lista de conexiones si el nombre del valor es igual al nombre del nodo grafo.
            while(elemento){
                Nodo<Conexion *> * conexionesTemp = elemento->getValor()->getConexiones()->getHead();
                while(conexionesTemp){
                    if(conexionesTemp->getValor()->getNombreNodo() == elemento->getValor()->getNombreNodo()){//Si los nombres son iguales le suma en uno la cantidad de fallas al nodo grafo.
                        elemento->getValor()->aumentarFallas();
                    }
                    conexionesTemp= conexionesTemp->getSiguiente();
                }
                elemento=elemento->getSiguiente();
            }
            elemento=this->nodos->getHead();

            //Revisasa los nodos del grafo para buscar los que tienen una mayor cantidad de fallas recibidas.
            while(elemento){
                if(elemento->getValor()->getFallasRecibidas()>cantidad){
                    cantidad = elemento->getValor()->getFallasRecibidas();//Actualiza el numero mayor de fallas recibidas encontradas en cada nodo grafo.
                }
                elemento=elemento->getSiguiente();
            }
            elemento=this->nodos->getHead();  

            //Agrega todo elemento que tenga la misma cantidad de fallas al numero mayor de fallas en un vector.
            while(elemento){
                if(elemento->getValor()->getFallasRecibidas() == cantidad){
                    conMayorCant.push_back(elemento->getValor()->getNombreNodo());
                }
                elemento=elemento->getSiguiente();
            }
            
            //Imprime el vector de elementos para mostrar los elementos con mayor cantidad de fallas recibidas.
            cout << "Ips que reciben mas fallas: " << endl;
            for(int i=0; i < conMayorCant.size(); i++)
                cout << " " <<conMayorCant.at(i) << '/';   
        }

};



