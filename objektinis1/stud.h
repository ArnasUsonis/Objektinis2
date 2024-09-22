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
void readFromFile(vector<stud>& vec1);
void outputfile(stud lok);

#endif // STUD_H_INCLUDED
