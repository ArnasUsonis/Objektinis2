#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED
#include "lib.h"

struct stud{
    std::string vardas,pavarde;
    std::vector<double>nd;
    double vid, med, egz, rez;

};

void ived(stud &lok);
void outputvid(stud lok);
void val(vector<stud>& vec);
double vidurkis(stud &lok);
void outputmed(stud lok);
double mediana(stud &lok);
void readFromFile(const string& failas, vector<stud>& vec1);
void outputfile(stud lok);
void isvedimas(const string pavadinimas, const vector<stud>& vec1);
int random_number();
void skirstymas(const vector<stud>& vec1, vector<stud>& kietiakai, vector<stud>& vargsiukai);
void generavimas(const string filename, int stud_kiekis);
void measureTimeVec(const string filename, int stud_num, int pasirinkimas, string konteineris);
void measureTimeLst(const string filename, int stud_num, int pasirinkimas, string konteineris);
void pasirinkti(int &pasirinkimas);
void pasirinktikont(int &kont);
void kontNustatymas(string &konteineris, int &kont);
void readFromFileLst(const string &failas, list<stud>& lst1);
void skirstymasLst(const list<stud>& lst1, list<stud>& kietiakai, list<stud>& vargsiukai);
void isvedimasLst(const string pavadinimas, const list<stud>& lst1);
void skirstymas2str(vector<stud>& vec, vector<stud>& vargsiukai);
void measureTimeVec2str(const string filename, int stud_num, int pasirinkimas, string konteineris);
void skirstymasLst2str(list<stud>& lst1, list<stud>& vargsiukai);
void measureTimeLst2str(const string filename, int stud_num, int pasirinkimas, string konteineris);
void strategija(int &strat);
void kokiastrategija(int strat, int kont,const int studentu_skaicius[], int pasirinkimas, const string& konteineris, size_t studskaic);
bool arvargsiukas(const stud& s);
void skirstymas3str(vector<stud>& vec1, vector<stud>& vargsiukai);
void measureTimeVec3str(const string filename, int stud_num, int pasirinkimas, string konteineris);
#endif // STUD_H_INCLUDED
