#include <bits/stdc++.h>

using namespace std;

struct fig{
    int pestininkai = 0;
    int bokstai = 0;
    int zirgai = 0;
    int rikiai = 0;
    int karaliai = 0;
    int valdoves = 0;
};

int main()
{
    ifstream fin("U1.txt");
    ofstream fout("U1rez.txt");

    int mokiniuSkaicius;
    fin >> mokiniuSkaicius;

    int pest, bokst, zirg, rik, karal, vald;
    fig figuros;

    for (int i = 0; i < mokiniuSkaicius; i++){
        fin >> pest >> bokst >> zirg >> rik >> karal >> vald;
        figuros.pestininkai += pest;
        figuros.bokstai += bokst;
        figuros.zirgai += zirg;
        figuros.rikiai += rik;
        figuros.karaliai += karal;
        figuros.valdoves += vald;
    }
    figuros.pestininkai /= 8;
    figuros.bokstai /= 2;
    figuros.zirgai /= 2;
    figuros.rikiai /= 2;

    fout << min(figuros.pestininkai, min(figuros.bokstai, min(figuros.zirgai, min(figuros.rikiai, min(figuros.karaliai, figuros.valdoves)))));
    return 0;
}