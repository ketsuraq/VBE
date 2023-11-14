#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("Duom2.txt");
    ofstream fout("Rez2.txt");

    int stoteliuSkaicius;
    float isvykimoValanda, isvykimoMinute;
    float vidutinisGreitis;
    fin >> stoteliuSkaicius >> vidutinisGreitis >> isvykimoValanda >> isvykimoMinute;
    float laikas = isvykimoValanda * 60 + isvykimoMinute;
    fin.ignore();
    vector<string> stoteles;
    vector<float> laikasV;

    string pavadinimas, info;
    float atstumas;

    for (int i = 0; i < stoteliuSkaicius; i++){
        getline(fin, info);
        pavadinimas = info.substr(0, 15);
        info.erase(0, 15);
        atstumas = stof(info);
        stoteles.push_back(pavadinimas);
        laikas += atstumas / vidutinisGreitis * 60;
        laikasV.push_back(laikas);
    }
    for (int i = 0; i < stoteliuSkaicius; i++){
        fout << setw(15) << left << stoteles[i] << int(floor(laikasV[i])) / 60 << " val. " << int(floor(laikasV[i])) % 60 << " min." << endl;
    }
    return 0;
}
