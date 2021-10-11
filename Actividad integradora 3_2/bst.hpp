#include <iostream>
#include <vector>

using namespace std;


class Falla{

    //Variables
    string ip;
    int numFallas;

    public:
    //constructor
    Falla(string ip, int numFallas){
            this->ip=ip;
            this->numFallas= numFallas;
            }
    Falla(int numFallas){
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

};




