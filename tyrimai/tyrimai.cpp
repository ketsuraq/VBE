#include <bits/stdc++.h>

using namespace std;

struct duomuo {
    int numeris;
    int sumaKeleiviu = 0;
    int sumaIslipusiu = 0;
};

int main()
{
    ifstream fin("U1.txt");
    ofstream fout("U1rez.txt");

    int duomenuSkaicius;
    fin >> duomenuSkaicius;

    map<int, duomuo> duomenys;

    int marsrutas, keleiviai;

    for (int i = 0; i < duomenuSkaicius; i++){
        fin >> marsrutas >> keleiviai;
        duomenys[marsrutas].numeris = marsrutas;
        if (keleiviai > 0){
            duomenys[marsrutas].sumaKeleiviu += keleiviai;
        } else {
            duomenys[marsrutas].sumaIslipusiu += keleiviai;
        }
    }

    int maxKeleiviai = 0, maxMarsrutas = 0;

    for (int i = 0; i <= 100; i++){
        if (duomenys[i].numeris != 0){
            fout << setw(6) << duomenys[i].numeris;
        }
        if (duomenys[i].sumaKeleiviu > maxKeleiviai){
            maxKeleiviai = duomenys[i].sumaKeleiviu;
            maxMarsrutas = duomenys[i].numeris;
        }
    }
    fout << endl;
    for (int i = 0; i <= 100; i++){
        if (duomenys[i].numeris != 0){
            fout << setw(6) << duomenys[i].sumaKeleiviu;
        }
    }
    fout << endl;
    for (int i = 0; i <= 100; i++){
        if (duomenys[i].numeris != 0){
            fout << setw(6) << duomenys[i].sumaIslipusiu;
        }
    }
    fout << endl << setw(6) << maxMarsrutas;
    return 0;
}