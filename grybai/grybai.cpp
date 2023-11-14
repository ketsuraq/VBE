#include <bits/stdc++.h>

using namespace std;

struct grybai{
    int baravykai;
    int raudonikiai;
    int lepsiai;
    int suma;
    int numeris;
};

int main()
{
    ifstream fin("U1.txt");
    ofstream fout("U1rez.txt");

    int N;
    fin >> N;
    map<int, grybai> M;

    int B, R, L;
    int day;

    int suma = 0;
    int diena;
    int laikinas;

    for (int i = 0; i < N; i++){
        fin >> day;
        fin >> B >> R >> L;
        M[day].baravykai += B;
        M[day].raudonikiai += R;
        M[day].lepsiai += L;

        M[day].suma = M[day].suma + B + R + L;
        M[day].numeris = day;
    }
    for (int i = 0; i < M.size(); i++){
        laikinas = M[i].suma;
        if (laikinas > suma){
            suma = laikinas;
            diena = i;
        }
    }
    for (int i = 0; i < M.size(); i++){
        if (M[i].numeris != 0){
            if (M[i].baravykai != 0 || M[i].raudonikiai != 0 || M[i].lepsiai != 0){
                fout << M[i].numeris << " " << M[i].baravykai << " " << M[i].raudonikiai << " " << M[i].lepsiai << endl;
            }
        }
    }
    fout << diena << " " << suma;
    return 0;
}
