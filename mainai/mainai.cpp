#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("U1.txt");
    ofstream fout("U1rez.txt");

    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int gilijosMonetos, eglijosMonetos;
    fin >> gilijosMonetos;

    vector<int> gilijosNominalai;
    vector<int> eglijosNominalai;

    int nominalas, suma;
    int gilijosSuma = 0, eglijosSuma = 0;
    for (int i = 0; i < gilijosMonetos; i++){
        fin >> nominalas;
        gilijosNominalai.push_back(nominalas);
    }
    for (int i = 0; i < gilijosNominalai.size(); i++){
        fin >> suma;
        gilijosSuma = gilijosSuma + suma * gilijosNominalai[i];
    }

    fin >> eglijosMonetos;
    for (int i = 0; i < eglijosMonetos; i++){
        fin >> nominalas;
        eglijosNominalai.push_back(nominalas);
    }
    for (int i = 0; i < eglijosNominalai.size(); i++){
        fin >> suma;
        eglijosSuma = eglijosSuma + suma * eglijosNominalai[i];
    }

    int monetuSuma = 0;
    int kiekis = 0;

    for (int i = 0; i < eglijosNominalai.size(); i++){
        fout << eglijosNominalai[i] << " ";
        kiekis = gilijosSuma / eglijosNominalai[i];
        fout << kiekis << endl;
        monetuSuma += kiekis;
        gilijosSuma = gilijosSuma % eglijosNominalai[i];
    }
    fout << monetuSuma << endl;
    monetuSuma = 0;

    for (int i = 0; i < gilijosNominalai.size(); i++){
        fout << gilijosNominalai[i] << " ";
        kiekis = eglijosSuma / gilijosNominalai[i];
        fout << kiekis << endl;
        monetuSuma += kiekis;
        eglijosSuma = eglijosSuma % gilijosNominalai[i];
    }
    fout << monetuSuma << endl;
    return 0;
}