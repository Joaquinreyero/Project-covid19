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

void estad(const string& fileName) {

    fstream fin;
    fin.open("./" + fileName, ios::in);

    vector<string> row;
    string line, word;
    int confirmed = 0;
    int death = 0;
    int total = -1;

    HashMap<int,int> mapC(10);
    HashMap<int,int> mapD(10);

    for (unsigned int i = 0; i < 10; ++i) {
        mapC.put(i,0);
    }
    for (unsigned int i = 0; i < 10; ++i) {
        mapD.put(i,0);
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
            if (row[2][0]=='N' or row[14]=="NA" or row[3][0]=='N' or row[2][0]=='-'){
                total--;
                continue;
            }
            else{
                int clave = row[2][0]-'0';
                confirmed++;
                if (row[14][0] == 'S'){
                    death++;
                    if (row[3][0] == 'A'){
                        if (row[2].length() > 1)
                            mapD.put(clave,mapD.get(clave)+1);
                        else
                            mapD.put(0,mapD.get(0)+1);
                    }
                    else
                        mapD.put(0,mapD.get(0)+1);
                }
                if (row[3][0] == 'A'){
                    if (row[2].length() > 1)
                        mapC.put(clave,mapC.get(clave)+1);
                    else {
                        mapC.put(0,mapC.get(0)+1);
                    }
                }
                else {
                    mapC.put(0,mapC.get(0)+1);
                }
            }
        }
    }

    clock_t end = clock();
    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;

    cout<<endl<<"Se registraron "<<total<<" casos de los cuales fueron confirmados "<<confirmed<<" ,falleciendo "
    <<death<<" de ellos."<<endl<<"Estadisticamente, un "<< (confirmed*100)/total<<"% fueron confirmados, de los cuales un "
    <<(death*100)/confirmed<<"% fallecieron."<<endl<<endl;
    int j=0;
    for (int i = 0; i < 10; ++i) {
        cout<<"Confirmados en rango de "<<i+(9*j)<<" a "<<(i+(9*j))+9<<" :"<<mapC.get(i+0)<<endl;
        j++;
    }
    cout<<endl;j=0;
    for (int i = 0; i < 10; ++i) {
        cout<<"muertes en rango de "<<i+(9*j)<<" a "<<(i+(9*j))+9<<" :"<<mapD.get(i+0)<<endl;
        j++;
    }

    cout<<endl<<"La ejecucion tomo: "<< elapsed_secs<<endl;
}