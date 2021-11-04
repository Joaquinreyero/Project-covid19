#include <iostream>
#include <sstream>
#include <cstring>
#include "estad.h"
#include "muertes.h"
#include "p_casos.h"
#include "casos_edad.h"
#include "casos_cui.h"

using namespace std;

bool Fexists(char* fname) {
    ifstream f;
    f.open(fname);
    bool f_exists = f.is_open();
    f.close();
    return f_exists;
}

bool isNumber(const string& x){
    for (char const &y : x) {
        if (isdigit(y) == 0)
            return false;
    }
    return true;
}

bool isDate(const string& x){
    for (int i = 0; i < x.length(); ++i) {
        if (isdigit( x[i]) == 0 ){
            if (x[4] == '-' && x[7] == '-'){
                cout<<"";
            }
            else
                return false;
        }
    }
    return true;
}

bool isValidDate(const string& x){
    string year = x.substr(0,4);
    string month = x.substr(5,2);
    string day = x.substr(8,10);
    int anio = stoi(year);
    int mes = stoi(month);
    int dia = stoi(day);
    if (anio < 0)
        return false;
    else{
        if (mes < 0 or mes > 12)
            return false;
        else{
            if ((mes==1 and dia>31) or (mes==3 and dia>31) or (mes==5 and dia>31) or (mes==7 and dia>31) or (mes==8 and dia>31) or (mes==10 and dia>31) or (mes==12 and dia>31) or (mes==4 and dia>30) or (mes==6 and dia>30) or (mes==9 and dia>30) or (mes==11 and dia>30) or (mes==2 and dia>28))
                return false;
            else
                if(dia < 0){
                    return false;
                }
                else
                    return true;
        }
    }
}

int main(int argc, char **argv) {
    for (int i = 0; i < argc; ++i) {


        if (strcmp(argv[i], "-estad") == 0) {
            if (!Fexists(argv[i+1])){
              cout<<"Fichero invalido";
                break;
            }
            estad(argv[i+1]);
        }


        if (strcmp(argv[i], "-p_casos") == 0) {

            if (!isNumber(argv[i+1])) {
                if (!Fexists(argv[i+1])){
                    cout<<"Fichero invalido";
                    break;
                }
                p_casos(argv[i+1]);
            } else {
                if (!Fexists(argv[i+2])){
                    cout<<"Fichero invalido";
                    break;
                }
                int firstProv = stoi(argv[i+1]);
                p_casos(argv[i+2],firstProv);
                }
            }


        if (strcmp(argv[i], "-p_muertes") == 0) {
            if (!isNumber(argv[i+1])) {
                if (!Fexists(argv[i+1])){
                    cout<<"Fichero invalido";
                    break;
                }
                muertes(argv[i+1]);
                break;
            }
            if (!Fexists(argv[i+2])){
                cout<<"Fichero invalido";
                break;
            }
            int fistProv = stoi(argv[i+1]);
            muertes(argv[i+2],fistProv);
        }


        if (strcmp(argv[i], "-casos_edad") == 0) {
            if(!isNumber(argv[i+1])){
                cout<<"error, dato invalido!";
                break;
            }
            if (!Fexists(argv[i+2])){
                cout<<"Fichero invalido";
                break;
            }
            casos_edad(argv[i+2],argv[i+1]);
            break;
        }


        if (strcmp(argv[i], "-casos_cui") == 0) {
            if (isDate(argv[i + 1])) {
                if (!Fexists(argv[i+2])){
                    cout<<"Fichero invalido";
                    break;
                }
                if (!isValidDate(argv[i+1])){
                    cout<<"Fecha invalida";
                    break;
                }
                casos_cui(argv[i + 2],argv[i+1]);
                break;
            }
            if (!Fexists(argv[i+1])){
                cout<<"Fichero invalido";
                break;
            }
            casos_cui(argv[i+1],"0");
        }
    }

    return 0;
}
