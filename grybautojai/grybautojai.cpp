#include <bits/stdc++.h>

using namespace std;

struct grybautojai{
    string vardas;
    int B = 0;
    int R = 0;
    int L = 0;
    int suma = 0;
};

int main()
{
    ifstream fin("U2.txt");
    ofstream fout("U2rez.txt");

    int grybautojuSkaicius;
    fin >> grybautojuSkaicius;
    fin.ignore();

    vector<grybautojai> V(grybautojuSkaicius);
    int kartai;
    int baravykai, raudonikiai, lepsiai;
    string line;

    for (int i = 0; i < grybautojuSkaicius; i++){
        getline(fin, line);
        if (line.length() < 15){
            getline(fin, line);
        }
        V[i].vardas = line.substr(0, 15);
        line.erase(0, 15);

        kartai = stoi(line);

        for (int j = 0; j < kartai; j++){
            fin >> baravykai >> raudonikiai >> lepsiai;
            fin.ignore();
            V[i].B += baravykai;
            V[i].R += raudonikiai;
            V[i].L += lepsiai;
            V[i].suma = V[i].suma + baravykai + raudonikiai + lepsiai;
        }
    }
    int maxsuma = 0;
    string maxvardas;

    for (int i = 0; i < V.size(); i++){
        fout << setw(15) << left << V[i].vardas << setw(5) << right << V[i].B << setw(5) << V[i].R << setw(5) << V[i].L << endl;
        if (V[i].suma > maxsuma){
            maxsuma = V[i].suma;
            maxvardas = V[i].vardas;
        }
    }
    if (maxsuma == 0){
        maxvardas = V[0].vardas;
    }
    fout << setw(15) << left << maxvardas << maxsuma;

    return 0;
}