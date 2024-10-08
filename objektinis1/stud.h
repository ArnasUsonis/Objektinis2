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
void val(stud &lok);
double vidurkis(stud &lok);
void outputmed(stud lok);
double mediana(stud &lok);
void readFromFile(const string& failas, vector<stud>& vec1);
void outputfile(stud lok);
void isvedimas(const string pavadinimas, const vector<stud>& vec1);
int random_number();
void skirstymas(const vector<stud>& vec1, vector<stud>& kietiakai, vector<stud>& vargsiukai);
void generavimas(const string filename, int stud_kiekis);
void measureTime(const string filename, int numStudents);

#endif // STUD_H_INCLUDED
