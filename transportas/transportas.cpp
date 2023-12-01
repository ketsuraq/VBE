#include <bits/stdc++.h>

using namespace std;

struct mars{
    vector<string> V;
    int kiekis = 0;
    int marsr = 0;
};

int main()
{
    ifstream fin("U2.txt");
    ofstream fout("U2rez.txt");

    int stoteliuSkaicius;
    fin >> stoteliuSkaicius;

    map<int, mars> M;
    set<int> S;

    string stotelesPavadinimas;
    int autobusuSkaicius, marsrutas;
    for (int i = 0; i < stoteliuSkaicius; i++){
        fin >> ws;

        char buff[21];
        fin.get(buff, 21);
        stotelesPavadinimas = buff;

        fin >> autobusuSkaicius;

        for (int j = 0; j < autobusuSkaicius; j++){
            fin >> marsrutas;
            M[marsrutas].kiekis++;
            M[marsrutas].V.push_back(stotelesPavadinimas);
            M[marsrutas].marsr = marsrutas;
            S.insert(marsrutas);
        }
    }
    int highest = 0;
    int topper = 0;
    vector<string> result;
    while (!S.empty()){
        int pirmas = *S.begin();
        S.erase(pirmas);
        if (M[pirmas].kiekis > highest){
            highest = M[pirmas].kiekis;
            topper = M[pirmas].marsr;
            result.clear();
            for (int i = 0; i < M[pirmas].V.size(); i++){
                result.push_back(M[pirmas].V[i]);
            }
        }
    }

    fout << topper << endl;
    for (int i = 0; i < result.size(); i++){
        fout << result[i] << endl;
    }
    return 0;
}