//
// Created by joaqu on 1/11/2021.
//
#include "string"


using namespace std;


void p_casos(const string& fileName){

    cout<<endl<<"Casos por provincias: "<<endl<<endl;

    vector<pair<int,int>> order(100);
    pair<int,int> data;

    fstream fin;
    fin.open("./" + fileName, ios::in);

    vector<string> row;
    string line, word;
    int confirmed = 0;
    int total = -1;

    HashMap<int, int> mapC(100);

    for (unsigned int i = 0; i < 100; ++i) {
        mapC.put(i, 0);
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
                confirmed++;
                int id = stoi(row[17]);
                mapC.put(id,mapC.get(id)+1);
            }
        }
    }
    for (int i = 0; i < 100; ++i) {
        if (mapC.get(i) != 0) {
            data.second=i;
            data.first=mapC.get(i);
            order[i]=data;
        }
    }
    quicksort(order);

    clock_t end = clock();
    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;

    for (int i = 0; i < 100; ++i) {
        if (order[i].first != 0)
            cout<<"-La provincia "<<order[i].second<<", tiene "<<order[i].first
                <<" casos."<<endl;
    }
    cout<<endl<<"La ejecucion tomo: "<< elapsed_secs<<endl;
}




void p_casos(const string& fileName, int firstProv){

    cout<<endl<<"Las primeras "<<firstProv
        <<" provincias con mas casos: "<<endl<<endl;

    vector<pair<int,int>> order(100);
    pair<int,int> data;

    fstream fin;
    fin.open("./" + fileName, ios::in);

    vector<string> row;
    string line, word;
    int confirmed = 0;
    int total = -1;

    HashMap<int, int> mapC(100);

    for (unsigned int i = 0; i < 100; ++i) {
        mapC.put(i, 0);
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
                confirmed++;
                int id = stoi(row[17]);
                mapC.put(id,mapC.get(id)+1);
            }
        }
    }

    if (firstProv > total){
        cout<<"El numero ingresado es invalido"<<endl;
        return;
    }

    for (int i = 0; i < 100; ++i) {
        if (mapC.get(i) != 0) {
            data.second=i;
            data.first=mapC.get(i);
            order[i]=data;
        }
    }
    quicksort(order);

    clock_t end = clock();
    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;

    for (int i = 0; i < firstProv; ++i) {
        if (order[i].first != 0)
            cout<<"-La provincia "<<order[i].second<<", tiene "<<order[i].first
                <<" casos."<<endl;
    }
    cout<<endl<<"La ejecucion tomo: "<< elapsed_secs<<endl;
}