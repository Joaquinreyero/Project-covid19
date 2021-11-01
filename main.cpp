#include <iostream>
#include <sstream>
#include <cstring>


using namespace std;

bool isNumber(const string& x){
    for (char const &y : x) {
        if (isdigit(y) == 0)
            return false;
    }
    return true;
}

bool isDate(const string& x){
    for (char const &y: x) {
        if (isdigit(y) == 0)
            return false;
    }
    return true;
}

int main(int argc, char **argv) {

    for (int i = 0; i < argc; ++i) {

        if (strcmp(argv[i], "-estad") == 0) {
            cout << "funcion estado y archivo:" << argv[i+1];
            break;
        }

        if (strcmp(argv[i], "-p_casos") == 0) {
            if (!isNumber(argv[i+1])) {
                cout << "funcion p casos para todos y archivo: " << argv[i + 1];
                break;
            } else {
                cout << "funcion p casos con p igual a: " << argv[i + 1] << " y archivo: " << argv[i + 2];
                break;
            }
        }

        if (strcmp(argv[i], "-p_muertes") == 0) {
            if (!isNumber(argv[i+1])) {
                cout << "funcion p muertes para todas provincias y archivo: " << argv[i + 1];
                break;
            } else {
                cout << "funcion p casos con p igual a: " << argv[i + 1] << " y archivo: " << argv[i + 2];
                break;
            }
        }

        if (strcmp(argv[i], "-casos-edad") == 0) {
            if(!isNumber(argv[i+1])){
                cout<<"error, dato invalido!";
                break;
            }
            else {
                cout<<"funcion para mostrar casos donde edad sea: "<<argv[i+1]<<" y arhivo: "<<argv[i+2];
                break;
            }
        }

        if (strcmp(argv[i], "-casos-cui") == 0) {

        }
    }
    return 0;
}
