#include "stud.h"
#include "lib.h"

void ived(stud &lok)
{
    cout<<"input name, surname and egzam score:";
    cin>>lok.vardas>>lok.pavarde>>lok.egz;

    int numhw;
    cout << "How many homework scores? ";
    cin >> numhw;
    double balas;

    for (int i = 1; i <= numhw; i++) {
        cout << "Input"<< i << "homework score: ";
        cin >> balas;
        lok.nd.push_back(balas);
    }
}

void output(stud lok)
{
    cout<< setw(15) <<left<< lok.vardas << setw(10)<<left<< lok.pavarde << setw(3) <<right<< fixed << setprecision(2) << lok.vid <<endl;
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
