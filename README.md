# Objektinis1
Projektas objektinio v0.1

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

## Instaliavimas bei paleidimas:
Atsisiunciat V0.1 release, kadangi naudojama cmake paleidimui reikes ne mazesnes kaip 3.31 versijos cmake windows sistemai, o kompiliavimui uzteks tiesiog du kartus paspausti ant run.bat faila.
