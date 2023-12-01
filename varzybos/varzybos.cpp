#include <bits/stdc++.h>
using namespace std;

struct begikas {
    string vardas;
    int laikas;
};

vector<begikas> leaveBest(vector<begikas> V, int kiekis, vector<begikas> results){
    int laikmena = 0;
    for (int i = 0; i < kiekis; i++){
        int highest = 100000;
        for (int j = 0; j < V.size(); j++){
            if (V[j].laikas < highest){
                highest = V[j].laikas;
                laikmena = j;
            }
        }
        begikas pirmas = {V[laikmena].vardas, V[laikmena].laikas};
        results.push_back(pirmas);
        V[laikmena].laikas = 100000;
    }
    return results;
}

int main()
{
    ifstream fin("U2.txt");
    ofstream fout("U2rez.txt");

    int grupiuSkaicius;
    fin >> grupiuSkaicius;

    vector<begikas> V;
    vector<begikas> results;

    int nariuSkaicius, minutes, sekundes;
    string vardasPavarde;
    for (int i = 0; i < grupiuSkaicius; i++){
        fin >> nariuSkaicius;
        for (int j = 0; j < nariuSkaicius; j++){
            fin >> ws;

            char buff[21];
            fin.get(buff, 21);
            vardasPavarde = buff;

            fin >> minutes >> sekundes;

            begikas pirmas = {vardasPavarde, minutes * 60 + sekundes};
            V.push_back(pirmas);
        }
        int kiekis = nariuSkaicius / 2;
        results = leaveBest(V, kiekis, results);
        V.clear();
    }

    int laikmena;
    for (int i = 0; i < results.size(); i++){
        int mini = 100000;
        for (int j = 0; j < results.size(); j++){
            if (results[j].laikas < mini){
                laikmena = j;
                mini = results[j].laikas;
            }
        }
        fout << results[laikmena].vardas << results[laikmena].laikas / 60 << " " << results[laikmena].laikas % 60 << endl;
        results[laikmena].laikas = 100000;
    }

    return 0;
}