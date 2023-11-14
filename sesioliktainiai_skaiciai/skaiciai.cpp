#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("U1.txt");
    ofstream fout("U1rez.txt");
    int ilgis, plotis;

    fin >> ilgis >> plotis;

    int value;
    int digit1, digit2;
    char digit161, digit162;

    for (int i = 1; i <= ilgis * plotis; i++){
        for (int j = 0; j < 3; j++){
            fin >> value;
            digit1 = value / 16;
            digit2 = value % 16;
            if (digit1 >= 10){
                digit161 = char('A' + digit1 - 10);
            } else{
                digit161 = char('0' + digit1);
            }
            if (digit2 >= 10){
                digit162 = char('A' + digit2 - 10);
            } else{
                digit162 = char('0' + digit2);
            }
            fout << digit161 << digit162;
        }
        if (i % plotis == 0){
            fout << endl;
        } else {
            fout << ";";
        }
    }

    return 0;
}