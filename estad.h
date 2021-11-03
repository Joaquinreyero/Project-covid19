//
// Created by joaqu on 1/11/2021.
//
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <ctime>
#include "Estructuras/Hashmap/HashMap.h"

using namespace std;

unsigned int HashFString(char clave){
    /*out<<"clave: "<<clave<<endl
        <<"hash clave: "<<idx;*/
    auto idx= (unsigned int) clave;
    return idx;
}

void estad(const string& fileName) {

    int colsOfInterest[] = {0, 2, 3, 12, 13, 14, 17, 20};
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);

    fstream fin;
    fin.open("./" + fileName, ios::in);

    vector<string> row;
    string line, word;
    int confirmed = 0;
    int death = 0;
    int total = -1;
    int month = 0;

    HashMap<char,int> mapC(10,&HashFString);
    HashMap<char,int> mapD(10,&HashFString);

    for (int i = 0; i < 10; ++i) {
        mapC.put(i+'0',0);
    }
    for (int i = 0; i < 10; ++i) {
        mapD.put(i+'0',0);
    }

    clock_t begin;
    begin = clock();

    while (getline(fin, line)) {
        total++;
        row.clear();
        stringstream s(line);

        while (getline(s, word, ',')) {
            if (!word.empty())
            {
                word = word.substr(1, word.size() - 2);
            }
            else
            {
                word = "NA";
            }
            row.push_back(word);
        }
        if (row[20][0] == 'C' && total != -1) {
            if (row[2][0]=='N' or row[14]=="NA" or row[3][0]=='N')
                continue;
            else{
                confirmed++;
                if (row[14][0] == 'S'){
                    death++;
                    if (row[3][0] == 'A'){
                        if (row[2].length() > 1)
                            mapD.put(row[2][0],mapD.get(row[2][0])+1);
                        else
                            mapD.put('0',mapD.get('0')+1);
                    }
                    else
                        mapD.put('0',mapD.get('0')+1);
                }
                else{
                    if (row[3][0] == 'A'){
                        if (row[2].length() > 1)
                            mapC.put(row[2][0],mapC.get(row[2][0])+1);
                        else {
                            mapC.put('0',mapC.get('0')+1);
                        }

                    }
                    else {
                        mapC.put('0',mapC.get('0')+1);
                    }
                }
            }
        }
    }

    clock_t end = clock();
    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;

    cout<<endl<<"Se registraron "<<total<<" casos de los cuales fueron confirmados "<<confirmed<<" ,falleciendo "
    <<death<<" de ellos."<<endl<<"Estadisticamente, un "<< (confirmed*100)/total<<"% fueron confirmados, de los cuales un "
    <<(death*100)/confirmed<<"% fallecieron."<<endl<<endl;

    for (int i = 0; i < 10; ++i) {
        cout<<"Casos en rango "<<i<<" : "<<mapC.get(i+'0')<<endl;
    }
    cout<<endl;
    for (int i = 0; i < 10; ++i) {
        cout<<"muertes en rango "<<i<<" : "<<mapD.get(i+'0')<<endl;
    }

    cout<<endl<<"La ejecucion tomo: "<< elapsed_secs<<endl;
}