#include <string>
#include <iostream>
#include <sstream>


using namespace std;

class Bitacora{
    //Atributos
    private:
        string mes;
        string dia;
        string tiempo;
        string ip;
        string falla;
        int id;
    //Metodos
    public:
        Bitacora(string mes, string dia,string tiempo, string ip, string falla){
            this->mes=mes;
            this->dia=dia;
            this->tiempo=tiempo;
            this->ip=ip;
            this->falla=falla;
            this->asignarId();

        }
        Bitacora(string falla){
            this->mes="";
            this->dia="";
            this->tiempo="";
            this->ip="";
            this->falla=falla;
        }

        Bitacora(){
            this->mes="";
            this->dia="";
            this->tiempo="";
            this->ip="";
            this->falla="";
        }
        Bitacora(string mes, string dia){
            this->mes= mes;
            this->dia= dia;
            this->tiempo="";
            this->ip="";
            this->falla="";
        }
        //camelcase
        //Getters y setters
        string getMes(){return this->mes;}
        void setMes(string mes){this->mes=mes;}
        string getDia(){return this->dia;}
        void setDia(string dia){this->dia=dia;}
        string getTiempo(){return this->tiempo;}
        void setTiempo(string tiempo){this->tiempo=tiempo;}
        string getIp(){return this->ip;}
        void setIp(string ip){this->ip=ip;}
        string getFalla(){return this->falla;}
        void setFalla(string falla){this->falla=falla;}
        int getId(){return this->id;}
        void setId(int id){this->id=id;}


        void imprimirEntrada(){
            cout<<getMes()<<" "<<getDia()<<" "<<getTiempo()<<" "<<getIp()<<" "<<getFalla()<<endl;
        }
        string regresarValores(){
            return this->getMes()+" "+this->getDia()+" "+this->getTiempo()+" "+this->getIp()+" "+this->getFalla();
        }

        string mesANumero(){
            if(!getMes().compare("Jun"))
                return "6";
            else if(!getMes().compare("Jul"))
                return "7";
            else if(!getMes().compare("Aug"))
                return "8";
            else if(!getMes().compare("Sep"))
                return "9";
            else if(!getMes().compare("Oct"))
                return "10";
            else 
                return "0";
        }

        void asignarId(){
            string id=mesANumero()+this->dia; //Juntando elementos
            
            stringstream string2int(id);// de string a int           
            int value=0;
            string2int>>value;//Conversion del string a int
            setId(value);
        }
        

};

//Quick sort objetos
int auxiliarQS_Obj(vector<Bitacora *> &vec, int inicio, int final)
    {
        int pivote = vec[final]->getId();
        int indx = inicio;
    
            for(int i = inicio;i<final;i++){
                
                if(vec[i]->getId()<pivote){

                Bitacora * temp = vec[i];
                vec[i] = vec[indx];
                vec[indx] = temp;
                indx++;
            }
    }
    
        Bitacora * temp = vec[final];
        vec[final] = vec[indx];
        vec[indx] = temp;
    
        return indx;
    }
 
    void ordenaQuicksort_Obj(vector<Bitacora *> &vec, int inicio, int final){
        if(inicio<final)
        {
        int p = auxiliarQS_Obj(vec,inicio, final);
        ordenaQuicksort_Obj(vec, inicio, (p-1));  
        ordenaQuicksort_Obj(vec, (p+1), final);  
        }
    };
