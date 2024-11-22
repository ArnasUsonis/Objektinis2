#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED
#include "lib.h"

class stud{
    private:
        string vardas,pavarde;
        vector<double>nd;
        double vid, med, egz, rez;

    public:


    string getVardas() const { return vardas; }
    string getPavarde() const { return pavarde; }
    vector<double> getNd() const { return nd; }
    double getEgz() const { return egz; }
    double getVid() const { return vid; }
    double getMed() const { return med; }

    void setVardas(const string& v) { vardas = v; }
    void setPavarde(const string& p) { pavarde = p; }
    void setNd(const vector<double>& new_nd) { nd = new_nd; }
    void setEgz(double e) { egz = e; }
    void setVid(double v) { vid = v; }
    void setMed(double m) { med = m; }

    void addNd(double grade) {
        nd.push_back(grade);
    }

    void setEgzFromLastNd() {
        if (!nd.empty()) {
            egz = nd.back();
            nd.pop_back();
        } else {
            std::cerr << "Error: No grades in nd to assign to egz." << std::endl;
        }
    }


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
