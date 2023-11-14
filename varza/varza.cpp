#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("Duom1.txt");
    ofstream fout("Rez1.txt");

    int N, T;
    fin >> N;

    float a, partial, sum = 0;

    for (int i = 0; i < N; i++){
        fin >> T;
        partial = 0;
        for (int j = 0; j < T; j++){
            fin >> a;
            partial += 1.0 / a;
        }
        sum += 1.0 / partial;
    }
    fout << fixed << setprecision(2) << sum;
    return 0;
}