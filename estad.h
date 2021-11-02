//
// Created by joaqu on 1/11/2021.
//
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void estad(const string& file){

    int colsOfInterest[] = {0, 2, 3, 12, 13, 14, 17, 20};
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);

    fstream fin;
    fin.open("./" + file, ios::in);

    vector<string> row;
    string line, word;
    int confirmed = 0;
    int death = 0;
    int total = -1;

    while (getline(fin, line))
    {
        int year;
        total++;
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
                word = "NA";
            }
            row.push_back(word);
        }


        if (row[20].compare("Confirmado") == 0 || total==-1)
        {
            if (row[3].compare("Meses") == 0){
                year = stoi(row[2]);
                cout<<year;
            }
            if (row[14].compare("SI") == 0){
                death++;
            }
            for (int i = 0; i < nColumns; i++)
            {
                cout << row[colsOfInterest[i]] << " ";
            }
            confirmed++;
            cout << endl;
        }
    }
    cout << endl;
    cout << "Casos confirmados: " << confirmed << " de " << total << " casos registrados." << endl;
    cout << "Fallecieron: "<< death;
}