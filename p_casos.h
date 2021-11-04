//
// Created by joaqu on 1/11/2021.
//
#include "string"

using namespace std;

struct data{
    int id=-1;
    int col=0;
};

void p_casos(const string& fileName){
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
    cout<<confirmed<<endl;
    for (int i = 0; i < 100; ++i) {
        if (mapC.get(i) != 0) {
            cout << "Provincia " << i << " tiene " << mapC.get(i) << " casos confirmados" << endl;
            data data;
            data.id = i;
            data.col = mapC.get(i);
        }
    }

}




void p_casos(const string& file, int firstProv){

}