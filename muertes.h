//
// Created by joaqu on 1/11/2021.
//

#include "string"

using namespace std;

void quicksort ( vector< pair<int,int> >& v ) {
    if(v.size() > 1) {
        vector< pair<int,int> > a,b;
        pair<int,int> pivot = v[0];
        for(int i=1; i<v.size(); i++)
            if(v[i].first >= pivot.first)
                a.push_back(v[i]);
            else if(v[i].first < pivot.first)
                b.push_back(v[i]);
        if(a.size() > 0)
            quicksort(a);
        if(b.size() > 0)
            quicksort(b);
        for(int i=0; i<a.size(); i++) v[i] = a[i];
        v[a.size()] = pivot;
        for(int i=0; i<b.size(); i++)
            v[i+a.size()+1] = b[i];
    }
}

void muertes(const string& fileName){

    cout<<endl<<"Muertes por provincias: "<<endl<<endl;

    vector<pair<int,int>> order(100);
    pair<int,int> data;

    fstream fin;
    fin.open("./" + fileName, ios::in);

    vector<string> row;
    string line, word;
    unsigned int confirmed = 0;
    unsigned int total = -1;

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
                if (row[14][0] == 'S'){
                    int id = stoi(row[17]);
                    mapC.put(id,mapC.get(id)+1);
                }
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
                <<" muertes."<<endl;
    }

    cout<<endl<<"La ejecucion tomo: "<< elapsed_secs<<endl;

}




void muertes(const string& fileName, unsigned int firstProv){

    cout<<endl<<"Las primeras "<<firstProv
        <<" provincias con mas muertes: "<<endl<<endl;

    vector<pair<int,int>> order(100);
    pair<int,int> data;

    fstream fin;
    fin.open("./" + fileName, ios::in);

    vector<string> row;
    string line, word;
    unsigned int confirmed = 0;
    unsigned int total = -1;
    unsigned int death= 0;

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
                if (row[14][0] == 'S'){
                    death++;
                    int id = stoi(row[17]);
                    mapC.put(id,mapC.get(id)+1);
                }
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
                <<" muertes."<<endl;
    }

    cout<<endl<<"La ejecucion tomo: "<< elapsed_secs<<endl;

}