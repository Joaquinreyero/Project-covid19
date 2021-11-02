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


using namespace std;

void estad(const string& fileName) {

    int colsOfInterest[] = {0, 2, 3, 12, 13, 14, 17, 20};
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);

    fstream fin;
    fin.open("./" + fileName, ios::in);

    vector<string> row;
    string line, word;
    int confirmed = 0;
    int total = -1;

    clock_t begin;
    begin = clock();
    while (getline(fin, line))
    {
        total++;
        row.clear();
        stringstream s(line);
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        if (row[20][1] == 'C' || total==-1)
        {
            confirmed++;
            cout << endl;
        }
    }
    clock_t end = clock();
    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
    cout << "Casos confirmados: " << confirmed << " de " << total << " casos registrados y demoro un total de: "<<elapsed_secs;
}