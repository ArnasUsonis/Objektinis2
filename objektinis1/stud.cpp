#include "stud.h"
#include "lib.h"

void ived(stud &lok)
{
    cout<<"input name, surname and egzam score:";
    cin>>lok.vardas>>lok.pavarde>>lok.egz;

    cout << "enter homework grades (enter -1 to end it):"<<endl;
    double balas;
    while(true){
        cin >> balas;
        if(balas == -1){
            break;
        }
        lok.nd.push_back(balas);
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

double mediana(stud &lok)
{
    sort(lok.nd.begin(), lok.nd.end());

    if (lok.nd.size() % 2 == 0){
            int middleIndex = (lok.nd.size()/2 + lok.nd.size()/2 - 1)/2;
            int vid = lok.nd[middleIndex];
        lok.med = 0.4*vid+0.6*lok.egz;

        return lok.med;
    }else{
        int middleIndex = lok.nd.size() / 2;
            int vid = lok.nd[middleIndex];
            lok.med = 0.4*vid+0.6*lok.egz;

            return lok.med;
    }
}
