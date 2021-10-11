#include <iostream>
#include <vector>
#include "listaDL.hpp"


using namespace std;

template <typename objeto>
class NodoArbolBinario{
    //Atributos
    public:
    int valor;
    ListaDL<string>  listaip;//ListaDL con objetos tipo string
    NodoArbolBinario * izq;
    NodoArbolBinario * der;
    NodoArbolBinario * padre;
    public:
        //Métodos get
        int getValor(){return this->valor;}
        NodoArbolBinario * getIzq(){return this->izq;}
        NodoArbolBinario * getDer(){return this->der;}
        NodoArbolBinario * getPadre(){return this->padre;}
        //Métodos set
        void setValor(int valor){this->valor=valor;}
        void setIzq(NodoArbolBinario * izq){this->izq=izq;}
        void setDer(NodoArbolBinario * der){this->der=der;}
        void setPadre(NodoArbolBinario * padre){this->padre=padre;}

        NodoArbolBinario(NodoArbolBinario * padre, int valor){
            this->valor=valor;
            this->izq=nullptr;
            this->der=nullptr;
            this->padre=padre;
        }
        //Agrega ip a listaip
        void agregarIp(string ip){
            listaip.agregarInicio(ip);
        }

        // Imprimir lista ips
        void imprimirIps(){
            Nodo<objeto> * elemento=this->listaip.getHead();
                //Imprime todos los elementos de la listaIp
                while(elemento){
                    cout<<elemento->getValor()<< endl;
                    elemento = elemento->getSiguiente();
                }
        }


        //Metodo de clase (no se tiene que crear un objeto)
        static void imprimirInorden(NodoArbolBinario * actual){
            //Caso base
            if(!actual)
                return;
            else{
                imprimirInorden(actual->izq);
                cout<<actual->valor<<" ";
                
                imprimirInorden(actual->der);
            }
        }
        //Preorder
        static void imprimirPreorder(NodoArbolBinario * actual){
            //Caso base
            if(!actual)
                return;
            else{
                cout<<actual->valor<<" ";
                imprimirPreorder(actual->izq);
                imprimirPreorder(actual->der);
                
            }
        }   
        //Postorden
        static void imprimirPostorden(NodoArbolBinario * actual){
            //Caso base
            if(!actual)
                return;
            else{
                imprimirPostorden(actual->izq);
                imprimirPostorden(actual->der);
                cout<<actual->valor<<" ";
            }
        }

        //Sucesor
        //Busca el nodo menor de un subarbol con raíz en nodo
        static NodoArbolBinario * valorMenor(NodoArbolBinario * nodo){
            if(!nodo)
                return nodo;
            NodoArbolBinario * actual=nodo;
            while(actual->getIzq())
                actual=actual->getIzq();
            return actual;
        }

        //Antecesor
        //Busca el nodo mayor de un subarbol con raíz en nodo
        static NodoArbolBinario * valorMayor(NodoArbolBinario * nodo){
            if(!nodo)
                return nodo;
            NodoArbolBinario * actual=nodo;
            while(actual->getDer())
                actual=actual->getDer();
            return actual;
        }

        //Revisa la altura del arbol
        static int altura(NodoArbolBinario * actual)
        {
            int alturatemp= 0;
            if (!actual)
                return alturatemp;
            else{
                int izquierdo = altura(actual->izq);
                int derecho = altura(actual->der);
                if(derecho < izquierdo)
                    alturatemp = izquierdo + 1;
                else
                    alturatemp = derecho + 1;
                return alturatemp;
            }
        }
    

        //Borra todo la información de un árbol o subárbol empezando por nodo
        static void borrarNodos(NodoArbolBinario * nodo){
            if(!nodo)
                return;
            borrarNodos(nodo->getIzq());
            borrarNodos(nodo->getDer());
            delete nodo;            
        }
};
template <typename objeto>
class BST{
    //Atributos
    NodoArbolBinario<objeto> * root;
    public:
        //Métodos get
        NodoArbolBinario<objeto> * getRoot(){return this->root;}
        //Métodos set
        void setRoot(NodoArbolBinario<objeto> * root){this->root=root;}
        //Método constructor
        BST(){
            this->root=nullptr;
        }
        //Método destructor
        ~BST(){
            NodoArbolBinario<objeto>::borrarNodos(this->root);
        }

        void agregarNodoIterativo(int valor){
            NodoArbolBinario<objeto> * actual =this->root;
            NodoArbolBinario<objeto> * padre=nullptr;

            //Arbol vacío
            if(!this->root){
                this->root= new NodoArbolBinario<objeto>(nullptr,valor);
                return;
            }
            //Arbol con valores
            //Encontrar al nodo padre
            while(actual){
                padre=actual;
                if(valor<actual->getValor())
                    actual=actual->getIzq();
                else
                    actual=actual->getDer();
            }

            if(valor<padre->getValor())
                padre->setIzq(new NodoArbolBinario<objeto>(padre,valor));
            else
                padre->setDer(new NodoArbolBinario<objeto>(padre,valor));
            
        }

        //Busca un valor dentro del árbol y devuelve el nodo que lo contiene
        NodoArbolBinario<objeto> * buscaNodo(int valor){
            NodoArbolBinario<objeto> * actual=this->root;
            while(actual){
                if(actual->getValor()==valor)
                    return actual;
                else
                    actual=actual->getValor()>valor?actual->getIzq():actual->getDer();
            } 
            return nullptr;
        }


        //Busca el nivel de un valor en el arbol
        NodoArbolBinario<objeto> * buscarNivel( int valor)
        {
            int nivelnodo = 0;
            NodoArbolBinario<objeto> * actual=this->root;
            while(actual){
                if(actual->getValor()==valor)
                {
                    cout << nivelnodo << endl;
                    return actual;
                }
                else
                    actual=actual->getValor()>valor?actual->getIzq():actual->getDer();
                nivelnodo++;
            } 
            return nullptr;
        }

        //Imprime los nodos del árbol en orden
        void imprimirArbol(int valor){
            if (valor == 1)
                NodoArbolBinario<objeto>::imprimirPreorder(this->root);
            if (valor == 2)
                NodoArbolBinario<objeto>::imprimirInorden(this->root);
            if (valor == 3)
                NodoArbolBinario<objeto>::imprimirPostorden(this->root);    
            if (valor == 4)
                imprimirNivxNiv(this->root);

            cout<<endl;
        }

        //Imprime el arbol nivel por nivel
        static void imprimirNivxNiv(NodoArbolBinario<objeto> * actual)  
        {  
            if (!actual) return;  
            vector<NodoArbolBinario<objeto> *> datos;  
            datos.push_back(actual);  
            
            while (datos.empty() == false)  
            { 
                int contador = datos.size();  
                while (contador > 0) 
                {  
                    NodoArbolBinario<objeto> *nodo = datos.front();  
                    cout<< nodo->getValor()<< " ";
                    datos.erase(datos.begin());  
                    if (nodo->getIzq() != NULL)  
                        datos.push_back(nodo->getIzq());  
                    if (nodo->getDer() != NULL)  
                    datos.push_back(nodo->getDer());  
                    contador--;  
                }
            }
        }  

        //Borra un nodo de acuerdo con su valor
        void eliminarNodo(int valor){
            NodoArbolBinario<objeto> * eliminar = this->buscaNodo(valor);
            NodoArbolBinario<objeto> * padre= nullptr;
            if(eliminar){
                padre=eliminar->getPadre();
                if(!eliminar->getIzq() && !eliminar->getDer()){  //Eliminar un nodo hoja
                    //Actualizar referencia
                    if(padre->getValor()>eliminar->getValor())
                        padre->setIzq(nullptr); //Si el nodo hoja a eliminar es el nodo izquierdo
                    else
                        padre->setDer(nullptr); //Si el nodo hoja a eliminar es el nodo derecho
                    delete eliminar;
                }else if(!eliminar->getIzq() && eliminar->getDer()){ //Eliminar un nodo con hijo derecho
                    if(padre->getValor()>eliminar->getValor())
                        padre->setIzq(eliminar->getDer());//Si el nodo a eliminar es el nodo izquierdo y tiene un hijo derecho
                    else
                        padre->setDer(eliminar->getDer());//Si el nodo a eliminar es el nodo derecho y tiene un hijo derecho
                    eliminar->getDer()->setPadre(padre);//Actualizar el padre del hijo derecho del nodo a eliminar
                    delete eliminar;
                }else if(eliminar->getIzq() && !eliminar->getDer()){ //Eliminar un nodo con hijo izq
                    if(padre->getValor()>eliminar->getValor())
                        padre->setIzq(eliminar->getIzq());//Si el nodo a eliminar es el nodo izquierdo y tiene un hijo izquierdo
                    else
                        padre->setDer(eliminar->getIzq());//Si el nodo a eliminar es el nodo derecho y tiene un hijo izquierdo
                    eliminar->getIzq()->setPadre(padre);//Actualizar el padre del hijo izquierdo del nodo a eliminar
                    delete eliminar;
                }else{//Eliminar un nodo con dos hijos
                    //Sucesor
                    NodoArbolBinario<objeto> * sucesor = NodoArbolBinario<objeto>::valorMenor(eliminar->getDer()); //Busca el menor en el subarbol derecho de nodo a eliminar (sucesor
                    eliminar->setValor(sucesor->getValor()); //Intercambia el valor del sucesor con el valor del nodo que se desea borrar
                    if(sucesor->getPadre()->getValor()>sucesor->getValor())
                        sucesor->getPadre()->setIzq(nullptr); //Si el sucesor era hijo izquierdo lo desconectamos del árbol
                    else
                        sucesor->getPadre()->setDer(nullptr); //Si el sucesor era hijo derecho lo desconectamos del árbol
                    delete sucesor; //Eliminamos el sucesor puesto que el valor que representaba ya se intercambio por el nodo a eliminar
                }
            }else{
                cout<<"Valor inexistente en el árbol"<<endl;
            }

        }


        void visit()
        {
            int valor;
            cout <<"De que forma quieres imprimir tu Arbol?"<< endl;
            cout <<"1. Preorder\n2. Inorder\n3. Postorden\n4. Level by level"<< endl;
            cout << "Dato: ";
            cin  >> valor;
            imprimirArbol(valor);

        }

        void height()
        {   
            cout<<"Altura: "<< NodoArbolBinario<objeto>::altura(this->root) << endl;
        }

        void antecesor()
        {
            int valor;
            cout << "Valor del cual deasea conocer su antecesor:  ";
            cin >> valor;
            cout <<"Valor antecesor: " << NodoArbolBinario<objeto>::valorMayor(buscaNodo(valor))->getValor() << endl;
        }

        void whatlevelamI()
        {
            int valor;
            cout << "Valor a buscar para encontar su nivel:  ";
            cin >> valor;
            cout << "Nivel: ";
            if(buscaNodo(valor)){
                buscarNivel(valor);
            }
            else{
                cout << "-1" << endl;
            }
            
        }
};