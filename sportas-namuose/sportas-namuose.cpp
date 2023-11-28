#include <bits/stdc++.h>

using namespace std;

struct sportas {
    int dienuKiekis = 0;
    int minuciuKiekis = 0;
    int rytas = 0;
    int diena = 0;
    int vakaras = 0;
    string pavadinimas;
};

int main()
{
    ifstream fin("U2.txt");
    ofstream fout("U2rez.txt");

    int dienuSkaicius;
    fin >> dienuSkaicius;

    int sportoSkaicius;
    string pratimoPavadinimas, dienosDalis;
    int pratimoKiekis;

    map<string, sportas> M;
    set<string> S;

    bool dienu;

    for (int i = 0; i < dienuSkaicius; i++){
        fin >> sportoSkaicius;
        set<string> L;
        for (int j = 0; j < sportoSkaicius; j++){
            fin >> ws;

            char buf[15];
            fin.get(buf, 15);
            pratimoPavadinimas = buf;

            fin >> dienosDalis >> pratimoKiekis;
            S.insert(pratimoPavadinimas);

            if (L.find(pratimoPavadinimas) == L.end()){
                M[pratimoPavadinimas].dienuKiekis++;
                L.insert(pratimoPavadinimas);
            }

            M[pratimoPavadinimas].pavadinimas = pratimoPavadinimas;
            M[pratimoPavadinimas].minuciuKiekis += pratimoKiekis;

            if (dienosDalis == "Rytas"){
                M[pratimoPavadinimas].rytas++;
            } else if (dienosDalis == "Diena"){
                M[pratimoPavadinimas].diena++;
            } else {
                M[pratimoPavadinimas].vakaras++;
            }

        }
    }
    while (!S.empty()){
        string first = *(S.begin());
        S.erase(S.begin());
        fout << setw(14) << left << M[first].pavadinimas << " " << M[first].dienuKiekis << " " << M[first].minuciuKiekis << endl;
        if (M[first].rytas != 0){
            fout << setw(7) << left << "Rytas" << " " << M[first].rytas << endl;
        }
        if (M[first].diena != 0){
            fout << setw(7) << left << "Diena" << " " << M[first].diena << endl;
        }
        if (M[first].vakaras != 0){
            fout << setw(7) << left << "Vakaras" << " " << M[first].vakaras << endl;
        }
    }

    return 0;
}