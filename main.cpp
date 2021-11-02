#include <iostream>
#include <sstream>
#include <cstring>
#include "fstream"
#include "estad.h"
#include "muertes.h"
#include "p_casos.h"
#include "casos_edad.h"
#include "casos_cui.h"

using namespace std;

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
    string ruta;
    for (int i = 0; i < argc; ++i) {


        if (strcmp(argv[i], "-estad") == 0) {
            ruta = argv[i+1];
            fstream file("./"+ruta);
            if (file.fail()){
                cout<<"El archivo: "<<ruta<<" es invalido";
                break;
            }
            //cout << "funcion estado y archivo:" << argv[i+1];
            estad(argv[i+1]);
            break;
        }


        if (strcmp(argv[i], "-p_casos") == 0) {
            if (!isNumber(argv[i+1])) {
                ruta = argv[i+1];
                fstream file("./"+ruta);
                if (file.fail()){
                    cout<<"El archivo: "<<ruta<<" es invalido";
                    break;
                }
                else {
                    cout << "funcion p casos para todos y archivo: " << argv[i + 1];
                    p_casos(argv[i+1]);
                    break;
                }
            } else {
                ruta = argv[i+2];
                fstream file("./"+ruta);
                if (file.fail()){
                    cout<<"El archivo: "<<ruta<<" es invalido";
                    break;
                }else {
                    cout << "funcion p casos con p igual a: " << argv[i + 1] << " y archivo: " << argv[i + 2];
                    int firstProv = stoi(argv[i+1]);
                    p_casos(argv[i+2],firstProv);
                    break;
                }
            }
        }


        if (strcmp(argv[i], "-p_muertes") == 0) {
            if (!isNumber(argv[i+1])) {
                ruta = argv[i+1];
                fstream file("./"+ruta);
                if (file.fail()){
                    cout<<"El archivo: "<<ruta<<" es invalido";
                    break;
                }
                else{
                    cout << "funcion p muertes para todas provincias y archivo: " << argv[i + 1];
                    //p_muertes(argv[i+1]);
                    break;
                }
            } else {
                ruta = argv[i+2];
                fstream file("./"+ruta);
                if (file.fail()){
                    cout<<"El archivo: "<<ruta<<" es invalido";
                    break;
                }
                else{
                    cout << "funcion p muertes con p igual a: " << argv[i + 1] << " y archivo: " << argv[i + 2];
                    int fistProv = stoi(argv[i+1]);
                    //p_muertes(argv[i+2],fistProv);
                    break;
                }
            }
        }


        if (strcmp(argv[i], "-casos-edad") == 0) {
            if(!isNumber(argv[i+1])){
                cout<<"error, dato invalido!";
                break;
            }
            else {
                ruta = argv[i+2];
                fstream file("./"+ruta);
                if (file.fail()){
                    cout<<"El archivo: "<<ruta<<" es invalido";
                    break;
                }
                else{
                    cout<<"funcion para mostrar casos donde edad sea: "<<argv[i+1]<<" y arhivo: "<<argv[i+2];
                    int edad = stoi(argv[i+1]);
                    //casos_edad(argv[i+2],edad);
                    break;
                }
            }
        }


        if (strcmp(argv[i], "-casos-cui") == 0) {
            if (isDate(argv[i + 1])) {
                if (!isValidDate(argv[i + 1])) {
                    cout << "error, fecha invalida!";
                    break;
                }
                else {
                    ruta = argv[i + 2];
                    fstream file("./" + ruta);
                    if (file.fail()) {
                        cout << "El archivo : " << ruta << " es invalido";
                        break;
                    } else {
                        cout <<"funcion casos CUI apartir de fecha: "<<argv[i+1]<<" y archivo: "<<argv[i + 2];
                        break;
                    }
                }
            }
            else {
                ruta = argv[i + 1];
                fstream file("./" + ruta);
                if (file.fail()) {
                    cout << "El archivo o fecha: " << ruta << " es invalido";
                    break;
                } else {
                    cout << "funcion casos CUI para todos y archivo: " << argv[i + 1];
                    //casos_cui(argv[i+1]);
                    break;
                }
            }
        }
    }
    return 0;
}
