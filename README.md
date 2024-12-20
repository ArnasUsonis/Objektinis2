# Objektinis1
Projektas objektinio v0.1
# v3.0
Pridetas InstallSetup failas kuris pades vartotojui patogiai atsisiusti ir naudotis programa.
## Naudojimosi instrukcija(v3.0):
atsidarykite Setup aplanka ir paspauskite ant InstallSetup. Atsisiuntus turetu atsirasti start meniu ir darbalaukyje shortcut failas.

# v2.0
sukurta doxygen dokumentacija(latex ir html) 

# v1.5
Klase zmogus:

![image](https://github.com/user-attachments/assets/6de25422-cc79-4f5a-a078-70b64e1edc64)

Klase stud :
```markdown
```cpp

class stud : public zmogus{
    private:
        vector<double>nd;
        double vid, med, egz, rez;

    public:

        void skaiciuotiAmziu() override {
        cout << "skaiciuojama"<<endl;
    }

    // Numatytasis konstruktorius
    stud() : nd(), vid(0.0), med(0.0), egz(0.0), rez(0.0) {}

    //getteriai
    vector<double> getNd() const { return nd; }
    double getEgz() const { return egz; }
    double getVid() const { return vid; }
    double getMed() const { return med; }

    //seteriai
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

    // Kopijavimo konstruktorius
    stud(const stud& other) {
        vardas = other.vardas;
        pavarde = other.pavarde;
        nd = other.nd;
        egz = other.egz;
        vid = other.vid;
        med = other.med;
        rez = other.rez;
    }


    void setEgzFromLastNd() {
        if (!nd.empty()) {
            egz = nd.back();
            nd.pop_back();
        } else {
            std::cerr << "Error: No grades in nd to assign to egz." << std::endl;
        }
    }


    friend std::istream& operator>>(std::istream& in, stud& student) {
        std::cout << "enter name: ";
        in >> student.vardas;
        std::cout << "enter surname: ";
        in >> student.pavarde;
        return in;
    }

   // void clearData() {
   //     vardas.clear();
   //     pavarde.clear();
   //     nd.clear();
   //     egz = 0.0;
   //     vid = 0.0;
   //     med = 0.0;
   //     rez = 0.0;
   // }


  friend std::ostream& operator<<(std::ostream& out, const stud& student) {
        out << std::left << std::setw(15) << student.vardas
            << std::left << std::setw(15) << student.pavarde
            << std::left << std::setw(15) << std::fixed << std::setprecision(2) << student.vid;
        return out;
    }

    ~stud(){} // destruktorius
};
```
bandymas sukurti zmogaus objekta ismes klaida :
```markdown
error: cannot declare variable 'temp' to be of abstract type 'zmogus'because the following virtual functions are pure within 'zmogus':'virtual void zmogus::skaiciuotiAmziu()'|

```

![image](https://github.com/user-attachments/assets/2c3f3890-3627-484e-9959-81bb299e6804)

# v1.2
## Aprasymas:
Igyvendinta rule of three, isvesties ir ivesties operatoriai.
## destruktorius:
![image](https://github.com/user-attachments/assets/a4451a40-bd3f-4c26-a5d8-435c993e6914)
## kopijavimo operatorius:
Kopijavimo operatorius suveikia tada, kai jau egzistuojantis objektas priskiria kito objekto reiksmes. Objektas, kuris yra kairiajame lygybes zenklo (=) kraste, perima desiniajame kraste esancio objekto atributu reiksmes. Parametras Stud a yra const ir perduodamas kaip nuoroda (reference type). Taip daroma, kad parametras butu tik skaitomas ir nereiketu kurti nereikalingu kopiju, taupant atminties resursus.
![image](https://github.com/user-attachments/assets/a1f81cc1-dff1-458d-af35-643508db1a7b)
## kopijavimo konstruktorius:
Kopijavimo konstruktorius yra iskvieciamas, kai naujai sukuriamas objektas igyja jau egzistuojancio objekto reiksmes.
![image](https://github.com/user-attachments/assets/c5a1798c-10cf-4a7b-a857-d004756eaeef)
## << operatorius:
![image](https://github.com/user-attachments/assets/bb1616e4-d3a7-4f6c-a24e-56aeb22c122e)

padeda sutaupyti kodo eilutes:

![image](https://github.com/user-attachments/assets/fcbb9047-16f6-4719-b3ae-20fa4b67d139) ![image](https://github.com/user-attachments/assets/d3e9c02e-9c1d-4dc5-992d-149c568b2bde)


## >> operatorius:
![image](https://github.com/user-attachments/assets/2aa74e65-a3a6-4fc3-b6c5-4cf7cdec078b)

padeda sutaupyti kodo eilutes:

![image](https://github.com/user-attachments/assets/3a58c78c-98f0-45da-8772-673410d24dc4) ![image](https://github.com/user-attachments/assets/d54ebf6f-3133-4d49-bc91-1775e0bf515a)


# Spartos analize (v0.3)
## Vector:

1000 Failo kurimas uztruko: 0.008931 s <br>
vector 1000 Duomenu nuskaitymas uztruko: 0.020995 s <br>
vector 1000 Studentai surusiuoti pagal vardus per 0.008931 s <br>
vector 1000 Studentu rusiavimas uztruko: 0.000000 s <br>
vector 1000 Duomenu isvedimas uztruko: 0.008744 s <br>
vector 1000 isviso uztruko 0.044425 s <br>


10 000 Failo kurimas uztruko: 0.066196 s<br>
vector 10 000 Duomenu nuskaitymas uztruko: 0.196940 s<br>
vector 10 000 Studentai surusiuoti pagal vardus per 0.066196 s<br>
vector 10 000 Studentu rusiavimas uztruko: 0.004815 s<br>
vector 10 000 Duomenu isvedimas uztruko: 0.076159 s<br>
vector 10 000 isviso uztruko 0.364299 s<br>


100 000 Failo kurimas uztruko: 0.673784 s<br>
vector 100 000 Duomenu nuskaitymas uztruko: 2.038001 s<br>
vector 100 000 Studentai surusiuoti pagal vardus per 0.673784 s<br>
vector 100 000 Studentu rusiavimas uztruko: 0.034068 s<br>
vector 100 000 Duomenu isvedimas uztruko: 0.719583 s<br>
vector 100 000 isviso uztruko 3.662217 s<br>

1 000 000 Failo kurimas uztruko: 6.486274 s<br>
vector 1 000 000 Duomenu nuskaitymas uztruko: 20.344804 s<br>
vector 1 000 000 Studentai surusiuoti pagal vardus per 6.486274 s<br>
vector 1 000 000 Studentu rusiavimas uztruko: 0.399872 s<br>
vector 1 000 000 Duomenu isvedimas uztruko: 7.014264 s<br>
vector 1 000 000 isviso uztruko 36.670251 s

10 000 000 Failo kurimas uztruko: 65.061046 s<br>
vector 10 000 000 Duomenu nuskaitymas uztruko: 199.550376 s<br>
vector 10 000 000 Studentai surusiuoti pagal vardus per 65.061046 s<br>
vector 10 000 000 Studentu rusiavimas uztruko: 3.424919 s<br>
vector 10 000 000 Duomenu isvedimas uztruko: 69.298156 s<br>
vector 10 000 000 isviso uztruko 368.115694 s<br>

## List:

1000 Failo kurimas uztruko: 0.008738 s<br>
list 1000 Duomenu nuskaitymas uztruko: 0.019995 s<br>
list 1000 studentai surusiuoti pagal vardus per 0.000000 s<br>
list 1000 Studentu rusiavimas uztruko: 0.000000 s<br>
list 1000 Duomenu isvedimas uztruko: 0.008877 s<br>
list 1000 isviso uztruko 0.043050 s<br>

10 000 Failo kurimas uztruko: 0.063990 s<br>
list 10 000 Duomenu nuskaitymas uztruko: 0.192936 s<br>
list 10 000 studentai surusiuoti pagal vardus per 0.004001 s<br>
list 10 000 Studentu rusiavimas uztruko: 0.002995 s<br>
list 10 000 Duomenu isvedimas uztruko: 0.078867 s<br>
list 10 000 isviso uztruko 0.346756 s<br>

100 000 Failo kurimas uztruko: 0.642807 s<br>
list 100 000 Duomenu nuskaitymas uztruko: 1.988361 s<br>
list 100 000 studentai surusiuoti pagal vardus per 0.048984 s<br>
list 100 000 Studentu rusiavimas uztruko: 0.035992 s<br>
list 100 000 Duomenu isvedimas uztruko: 0.696766 s<br>
list 100 000 isviso uztruko 3.417449 s<br>

1 000 000 Failo kurimas uztruko: 6.341986 s<br>
list 1 000 000 Duomenu nuskaitymas uztruko: 19.773706 s<br>
list 1 000 000 studentai surusiuoti pagal vardus per 0.554823 s<br>
list 1 000 000 Studentu rusiavimas uztruko: 0.344901 s<br>
list 1 000 000 Duomenu isvedimas uztruko: 7.058292 s<br>
list 1 000 000 isviso uztruko 34.076979 s<br>

10 000 000 Failo kurimas uztruko: 64.174002 s<br>
list 10 000 000 Duomenu nuskaitymas uztruko: 203.791442 s<br>
list 10 000 000 studentai surusiuoti pagal vardus per 6.642581 s<br>
list 10 000 000 Studentu rusiavimas uztruko: 3.806869 s<br>
list 10 000 000 Duomenu isvedimas uztruko: 76.000803 s<br>
list 10 000 000 isviso uztruko 354.420880 s<br>

![image](https://github.com/user-attachments/assets/0c90d8e9-c3a9-4d69-a8f5-96da42d93618)


*CPU: i7-4790  RAM:16gb*
### Isvados:
Didziausi skirtumai matomi studentus rusiuojant pagal vardus arba pavardes, kas listuose daroma zymiai greiciau nei vektoriuose.

# Spartos analize (v1.0)
Testuojam studentu rusiavima i dvi grupes 3 strategijas:

### 1 STRATEGIJA:
vector 1000 Studentu rusiavimas uztruko: 0.000000 s<br>
vector 10 000 Studentu rusiavimas uztruko: 0.001998 s<br>
vector 100 000 Studentu rusiavimas uztruko: 0.019245 s<br>
vector 1 000 000 Studentu rusiavimas uztruko: 0.178742 s<br>
vector 10 000 000 Studentu rusiavimas uztruko: 1.799656 s<br>
Vidurkis: 0.3999282 s<br>

list 1000 Studentu rusiavimas uztruko: 0.000751 s<br>
list 10 000 Studentu rusiavimas uztruko: 0.001999 s<br>
list 100 000 Studentu rusiavimas uztruko: 0.032069 s<br>
list 1 000 000 Studentu rusiavimas uztruko: 0.203321 s<br>
list 10 000 000 Studentu rusiavimas uztruko: 2.324669 s<br>
Vidurkis: 0.5125618 s<br>

### 2 STRATEGIJA:
vector 1000 Studentu rusiavimas uztruko: 0.002998 s<br>
vector 10 000 Studentu rusiavimas uztruko: 0.296418 s<br>
vector 100 000 Studentu rusiavimas uztruko: 32.306840 s<br>
vector 1 000 000 Studentu rusiavimas uztruko: - (labai ilgai)<br>
vector 10 000 000 Studentu rusiavimas uztruko: -<br>
Vidurkis: -<br>

list 1000 Studentu rusiavimas uztruko: 0.000000 s<br>
list 10 000 Studentu rusiavimas uztruko: 0.000999 s<br>
list 100 000 Studentu rusiavimas uztruko: 0.009869 s<br>
list 1 000 000 Studentu rusiavimas uztruko: 0.094055 s<br>
list 10 000 000 Studentu rusiavimas uztruko: 0.987879 s<br>
Vidurkis: 0.2185604 s

### 3 STRATEGIJA:
vector 1000 Studentu rusiavimas uztruko: 0.001001 s<br>
vector 10 000 Studentu rusiavimas uztruko: 0.000997 s<br>
vector 100 000 Studentu rusiavimas uztruko: 0.016252 s<br>
vector 1 000 000 Studentu rusiavimas uztruko: 0.159152 s<br>
vector 10 000 000 Studentu rusiavimas uztruko: 1.508008 s<br>
Vidurkis: 0.337082 s

### Isvados:
2 strategija, listu atzvilgiu, yra zymiai geresne nei pirma, bet vektoriams tragiska, o pritaikius funkcijas is STL isprendzia sia problema vektoriams(zr. 3 strategijos rezultatus).

3 strategijos rezultatu foto:

![image](https://github.com/user-attachments/assets/5b001ae8-28de-4829-b18b-c39d470e70b5)


*CPU: i7-4790  RAM:16gb*
# Spartos analize (v1.1)

## class :
100000 Failo kurimas uztruko: 0.657203 s<br>
vector 100000 Duomenu nuskaitymas uztruko: 1.903391 s<br>
vector 100000 Studentai surusiuoti pagal vardus per 0.657203 s<br>
vector 100000 Studentu rusiavimas uztruko: 0.019994 s<br>
vector 100000 Duomenu isvedimas uztruko: 0.863130 s<br>
vector 100000 isviso uztruko 3.609665 s<br>

1000000 Failo kurimas uztruko: 6.477034 s<br>
vector 1000000 Duomenu nuskaitymas uztruko: 19.289833 s<br>
vector 1000000 Studentai surusiuoti pagal vardus per 6.477034 s<br>
vector 1000000 Studentu rusiavimas uztruko: 0.276924 s<br>
vector 1000000 Duomenu isvedimas uztruko: 8.619423 s<br>
vector 1000000 isviso uztruko 36.359636 s<br>

## struct :
100000 Failo kurimas uztruko: 0.653854 s<br>
vector 100000 Duomenu nuskaitymas uztruko: 1.860402 s<br>
vector 100000 Studentai surusiuoti pagal vardus per 0.653854 s<br>
vector 100000 Studentu rusiavimas uztruko: 0.014010 s<br>
vector 100000 Duomenu isvedimas uztruko: 0.860581 s<br>
vector 100000 isviso uztruko 3.442403 s<br>

1000000 Failo kurimas uztruko: 6.471268 s<br>
vector 1000000 Duomenu nuskaitymas uztruko: 19.039902 s<br>
vector 1000000 Studentai surusiuoti pagal vardus per 6.471268 s<br>
vector 1000000 Studentu rusiavimas uztruko: 0.175948 s<br>
vector 1000000 Duomenu isvedimas uztruko: 8.439341 s<br>
vector 1000000 isviso uztruko 34.759877 s<br>

### Isvada:
kazkokio labai akivaizdaus greitumo laiko prasme tarp abieju nepastebejau(labai nezymus).

##  Optimizavimo flagu analize :

## O1 :

![image](https://github.com/user-attachments/assets/13b9a82e-4488-4672-a18d-d5cbc2cecfb2)


## O2 :

![image](https://github.com/user-attachments/assets/b041f82a-7ad1-4fdf-9ea9-e543069abe48)


## O3 :

![image](https://github.com/user-attachments/assets/b4122f7a-0cc3-4d04-862c-2892c0f560c6)

### Isvada:
class exe failas maziau sveria nei struct,o kazkoks skirtumas pakeitus flagus nesimato kazkodel, kazkuriam turejo sumazeti exe failo dydis, bet nesumazejo (buvo daroma per codeblocks).

## Instaliavimas bei paleidimas:
Atsisiunciat V0.1 release, kadangi naudojama cmake paleidimui reikes ne mazesnes kaip 3.31 versijos cmake windows sistemai, o kompiliavimui uzteks tiesiog du kartus paspausti ant run.bat faila.
