#include "stud.h"
#include "lib.h"

void ived(stud &lok)
{
    cout<<"input name, surname and egzam score:";
    cin>>lok.vardas>>lok.pavarde>>lok.egz;
}

void output(stud lok)
{
    cout<< setw(15) <<left<< lok.vardas << setw(10)<<left<< lok.pavarde << setw(3) <<right<< lok.egz <<endl;
}

void val(stud &lok){
    lok.vardas.clear();
    lok.pavarde.clear();
    lok.nd.clear();

}
