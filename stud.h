#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED
#include "lib.h"

struct stud{
    std::string vardas,pavarde;
    std::vector<double>nd;
    double vid, med, egz, rez;

};

void ived(stud &lok);
void output(stud lok);
void val(stud &lok);
#endif // STUD_H_INCLUDED
