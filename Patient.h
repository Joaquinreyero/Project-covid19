//
// Created by Augusto
#include "string.h"

#ifndef PROYECTO_FINAL_PATIENT_H
#define PROYECTO_FINAL_PATIENT_H




class Patient {
private:
    std::string CI, dateCI, dead, confirmed;
    int age,id,idprov;
public:
    Patient(){
        age=0;
        id=0;
        idprov=0;
        CI = "NA";
        dateCI = "NA";
        dead = "NA";
        confirmed = "NA";
    };

    void setdead(std::string a) {dead = a;};

    void setage(std::string a){age = stoi(a);};

    void setid(std::string a){ id = stoi(a);};

    void setCI(std::string a){CI = a;};

    void setdateCI(std::string a){dateCI = a;};

    void setidprov(std::string a) { idprov = stoi(a);};

    void setconfirmed(std::string a){confirmed = a;};

    int getage(){return age;};

    int getid(){return id;};

    std::string getCI(){return CI;};

    std::string getdateCI(){return dateCI;};

    std::string getdead(){return dead;};

    int getidprov(){return idprov;};

    std::string getconfirmed(){return confirmed;};

    void Print(){
        std::cout<<"Paciente ="<<id<<std::endl;
        std::cout<<"edad ="<<age<<std::endl;
        std::cout<<"Tipo Caso ="<<confirmed<<std::endl;
        std::cout<<"Cuidados Intensivos ="<<CI<<std::endl;
        std::cout<<"fecha CI ="<<dateCI<<std::endl;
        std::cout<<"Fallecio ="<<dead<<std::endl;
        std::cout<<"id Provincia ="<<idprov<<std::endl;
        std::cout<<"---------------------------------------"<<std::endl;


    }

};


#endif //PROYECTO_FINAL_PATIENT_H
