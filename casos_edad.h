//
// Created by Augusto on 4/11/2021.
//
using namespace std;
#include "./Estructuras/Cola/Cola.h"
#include "Patient.h"
void casos_edad(string fileName,string age)
{   Patient a;

    int colsOfInterest[] = {0, 2, 3, 12, 13, 14, 17, 20};
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);

    fstream fin;
    fin.open("./" + fileName,ios::in);
    if(!fin.is_open())std::cout<<"Error file open"<<endl;//comprueba si abre el archivo o no
    vector<Cola<Patient>> Order(100);
    vector<string> row;
    string line, word;
    int confirmed = 0;
    int total = -1;

    while (getline(fin, line))
    {

        row.clear();
        stringstream s(line);


        while (getline(s, word, ','))
        {
            if (word.size() > 0)
            {
                word = word.substr(1, word.size() - 2);
            }
            else
            {
                word = "1NA";
            }
            row.push_back(word);
        }
        total++;

        if(!row[3].compare("Meses"))//setea los menores a 1 año en 0
            { row[2]="0";

            }
        if(total>=0 && !row[2].compare(age)){//toma solo los datos de la edad necesario y los guarda en una clase
            a.setid(row[0]);
            a.setage(row[2]);
            a.setCI(row[12]);
            a.setdateCI(row[13]);
            a.setdead(row[14]);
            a.setidprov(row[17]);
            a.setconfirmed(row[20]);
            Order[a.getidprov()].encolar(a);
            ;}


    };

    for (int i = 0; i < 100; ++i) {
        while (!Order[i].esVacia()){
            Order[i].desencolar().Print();
        }
    }
};