#include <iostream>
#include <vector>

using namespace std;

class AccesoIp{
    //Variables
    string ip;
    int numFallas;//Cantidad accesos

    public:
    //constructor
    AccesoIp(string ip){
            this->ip=ip;
            this->numFallas= 1;
            }
    AccesoIp(int numFallas){
            this->ip="";
            this->numFallas=numFallas;
            }
    
    string getIp(){return this->ip;}
    void setIp(string ip){this->ip=ip;}
    int getnumFallas(){return this->numFallas;}
    void setFalla(int numFallas){this->numFallas=numFallas;}

    void sumarFalla(){
        numFallas++;
    }

    friend ostream& operator<<(ostream& salida, const AccesoIp& objeto){
        salida<<objeto.ip<<" Accesos: "<<objeto.numFallas;
        return salida;
    }

};




