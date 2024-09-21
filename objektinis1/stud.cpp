#include "stud.h"
#include "lib.h"

void ived(stud &lok)
{
    cout<<"input name and surname:";
    cin>>lok.vardas>>lok.pavarde;

    cout << "do you want to randomize exam and homework grades?(y/n)"<<endl;
    char r;
    cin>>r;

    if(r=='y' || r=='Y'){
        int kiekisNd = rand() % 5 + 1; // nd kiekis (1-5)
        for (int i = 0; i < kiekisNd; i++) {
            double namuDarbas = rand() % 10 + 1; // nd pazymys (1-10)
            lok.nd.push_back(namuDarbas);
        }
        lok.egz = rand() % 10 + 1; // egz (1-10)

    }else if(r=='n'|| r=='N'){
        cout << "enter homework grades (enter -1 to end it):"<<endl;
    double balas;
    while(true){
        cin >> balas;
        if(balas == -1){
            break;
        }
        lok.nd.push_back(balas);
    }

    cout << "enter exam score: ";
    cin >> lok.egz;
    }
}

void outputvid(stud lok)
{
    cout<< setw(15) <<left<< lok.vardas << setw(10)<<left<< lok.pavarde << setw(3) <<right<< fixed << setprecision(2) << lok.vid <<endl;
}

void outputmed(stud lok)
{
    cout<< setw(15) <<left<< lok.vardas << setw(10)<<left<< lok.pavarde << setw(3) <<right<< fixed << setprecision(2) << lok.med <<endl;
}

void val(stud &lok){
    lok.vardas.clear();
    lok.pavarde.clear();
    lok.nd.clear();

}

double vidurkis(stud &lok){
    double sum = 0.0;

    for (int i = 0; i < lok.nd.size(); i++) {
        sum += lok.nd[i];
    }

    double avghomework = sum / lok.nd.size();

    lok.vid = 0.4 * avghomework + 0.6 * lok.egz;

    return lok.vid;
}

double mediana(stud &lok){
    sort(lok.nd.begin(), lok.nd.end());

    if (lok.nd.size() % 2 == 0){
            int middleIndex1 = lok.nd.size() / 2 - 1;
            int middleIndex2 = lok.nd.size() / 2;
            double medianValue = (lok.nd[middleIndex1] + lok.nd[middleIndex2]) / 2.0;
        lok.med = 0.4*medianValue+0.6*lok.egz;

        return lok.med;
    }else{
        int middleIndex = lok.nd.size() / 2;
            int vid = lok.nd[middleIndex];
            lok.med = 0.4*vid+0.6*lok.egz;

            return lok.med;
    }
}


