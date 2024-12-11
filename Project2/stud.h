#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED
#include "lib.h"

class stud{
    private:
        string vardas,pavarde;
        vector<double>nd;
        double vid, med, egz, rez;

    public:
    //getteriai
    string getVardas() const { return vardas; }
    string getPavarde() const { return pavarde; }
    vector<double> getNd() const { return nd; }
    double getEgz() const { return egz; }
    double getVid() const { return vid; }
    double getMed() const { return med; }

    //seteriai
    void setVardas(string vardas) { this->vardas = vardas; }
    void setPavarde(string pavarde) { this->pavarde = pavarde; }
    void setNd(vector<double> nd) { this->nd = nd; }
    void setEgz(double egz) { this->egz = egz; }
    void setVid(double vid) { this->vid = vid; }
    void setMed(double med) { this->med = med; }
    void setRez(double rez) { this->rez = rez; }

    void addNd(double grade) {
        nd.push_back(grade);
    }
    //kopijavimo operatorius
    stud& operator=(const stud& a) {
        if (this == &a) return *this;
        this->vardas = a.vardas;
        this->pavarde = a.pavarde;
        this->nd = a.nd;
        this->egz = a.egz;
        this->vid = a.vid;
        this->med = a.med;
        this->rez = a.rez;
        return *this;
    }

    void setEgzFromLastNd() {
        if (!nd.empty()) {
            egz = nd.back();
            nd.pop_back();
        } else {
            std::cerr << "Error: No grades in nd to assign to egz." << std::endl;
        }
    }
    ~stud(){} // destruktorius


    friend std::istream& operator>>(std::istream& in, stud& student) {
        std::cout << "Iveskite varda: ";
        in >> student.vardas;
        std::cout << "Iveskite pavarde: ";
        in >> student.pavarde;

        std::cout << "Iveskite pazymius (baigus ivedima, spauskite bet kokį simbolį): ";
        double grade;
        student.nd.clear();  // Išvalyti senus pažymius prieš įvedant naujus
        while (in >> grade) {  // Nuskaityti pažymius, kol yra duomenų
            student.nd.push_back(grade);
        }
        return in;
    }

    void clearData() {
        vardas.clear();
        pavarde.clear();
        nd.clear();
        egz = 0.0;
    }


  friend std::ostream& operator<<(std::ostream& out, const stud& student) {
        out << std::left << std::setw(15) << student.vardas
            << std::left << std::setw(15) << student.pavarde
            << std::left << std::setw(15) << std::fixed << std::setprecision(2) << student.vid
            << std::left << std::setw(15) << std::fixed << std::setprecision(2) << student.med
            << std::left << std::setw(15) << std::fixed << std::setprecision(2) << student.rez
            << std::left << std::setw(15) << std::fixed << std::setprecision(2) << student.egz
            << std::endl;
        return out;
    }
};

void ived(stud &lok);
void outputvid(stud lok);
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
void kokiastrategija(string filename,int strat, int kont, int pasirinkimas, const string& konteineris, int numeris);
bool arvargsiukas(const stud& s);
void skirstymas3str(vector<stud>& vec1, vector<stud>& vargsiukai);
void measureTimeVec3str(const string filename, int stud_num, int pasirinkimas, string konteineris);
void val(vector<stud>& vec);
void val(stud& student);
#endif // STUD_H_INCLUDED
