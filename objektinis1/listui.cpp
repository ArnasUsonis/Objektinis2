#include "stud.h"
#include "lib.h"

void pasirinkti(int &pasirinkimas)
{
    while(true){
        cout << "pasirinkite rusiavimo buda:" << endl;
        cout << "1 - pagal vardus" << endl;
        cout << "2 - pagal pavardes" <<endl;
        cin >> pasirinkimas;

        if (pasirinkimas != 1 && pasirinkimas != 2){
            continue;
        }else{
            break;
        }
    }
}

void pasirinktikont(int &kont)
{
    while(true){
        cout << "pasirinkite konteineri:" << endl;
        cout << "1 - vector" << endl;
        cout << "2 - list" <<endl;
        cin >> kont;

        if (kont != 1 && kont != 2){
            continue;
        }else{
            break;
        }
    }
}

void kontNustatymas(string &konteineris, int &kont)
{
    if(kont == 1){
        konteineris = "vector";
    }else{
        konteineris = "list";
    }
}


void readFromFileLst(const string &failas, list<stud>& lst1) {
    ifstream file(failas);

    if (!file) {
        throw runtime_error("unable to open file: " + failas);
    }

    string line;

    getline(file, line);


    while (getline(file, line)) {
        istringstream iss(line);
        stud temp;
        double grade;

        iss >> temp.vardas >> temp.pavarde;

        temp.nd.clear();
        while (iss >> grade) {
            temp.nd.push_back(grade);
        }

        if (temp.nd.empty()) {
            cerr << "No grades found for student: " << temp.vardas << " " << temp.pavarde << endl;
            continue;
        }


        temp.egz = temp.nd.back();
        temp.nd.pop_back();


        vidurkis(temp);
        mediana(temp);

        lst1.push_back(temp);
    }

    file.close();
}

void skirstymasLst(const list<stud>& lst1, list<stud>& kietiakai, list<stud>& vargsiukai) {
    for (const stud& studentas : lst1) {
        if (studentas.vid >= 5.0) {
            kietiakai.push_back(studentas);
        } else {
            vargsiukai.push_back(studentas);
        }
    }
}

void isvedimasLst(const string pavadinimas, const list<stud>& lst1) {
     ofstream out(pavadinimas);
    out << left << setw(15) << "Vardas" << setw(15) << "Pavarde"
        << setw(10) << "Galutinis" << setw(20) << "Adresas" << endl;
    out << "-------------------------------------------------------------" << endl;

    for (const auto& studentas : lst1) {
        out << left << setw(15) << studentas.vardas
            << setw(15) << studentas.pavarde
            << setw(10) << fixed << setprecision(2)
            << studentas.vid
            << setw(20) << &studentas << endl;
    }
}

void measureTimeLst(const string filename, int stud_num, int pasirinkimas, string konteineris) {
    list<stud> lst1, kietiakai, vargsiukai;//vec1

    // viso vykdymo laikas
    auto overall_start = high_resolution_clock::now();

    // failo kurimo laikas
    auto start_gen = high_resolution_clock::now();
    generavimas(filename, stud_num);
    auto end_gen = high_resolution_clock::now();
    auto duration_gen = duration_cast<microseconds>(end_gen - start_gen);
    double seconds_gen = duration_gen.count() / 1e6; // konvertuojam i sekundes
    cout << stud_num << " Failo kurimas uztruko: " << fixed << setprecision(6) << seconds_gen << " s" << endl;

    // duomenu nuskaitymo laikas
    auto start_read = high_resolution_clock::now();
    readFromFileLst(filename, lst1);
    auto end_read = high_resolution_clock::now();
    auto duration_read = duration_cast<microseconds>(end_read - start_read);
    double seconds_read = duration_read.count() / 1e6; // konvertuojam i sekundes
    cout << konteineris << " " << stud_num << " Duomenu nuskaitymas uztruko: " << fixed << setprecision(6) << seconds_read << " s" << endl;

    // rusiavimas pagal varda arba pavarde
    if (pasirinkimas == 1) {

        auto start_1 = high_resolution_clock::now();

        lst1.sort([](const stud& a, const stud& b) {
            return a.vardas < b.vardas;
        });

        auto end_1 = high_resolution_clock::now();
        auto duration_1 = duration_cast<microseconds>(end_1 - start_1);
        auto seconds_1 = duration_1.count() / 1e6;

        cout << konteineris << " " << stud_num << " studentai surusiuoti pagal vardus per " << fixed << setprecision(6) << seconds_1 << " s" << endl;

    } else if (pasirinkimas == 2) {

        auto start_2 = high_resolution_clock::now();

        lst1.sort([](const stud& a, const stud& b) {
            return a.pavarde < b.pavarde;
        });

        auto end_2 = high_resolution_clock::now();
        auto duration_2 = duration_cast<microseconds>(end_2 - start_2);
        auto seconds_2 = duration_2.count() / 1e6;

        cout << konteineris << " " << stud_num << " studentai surusiuoti pagal pavardes per " << fixed << setprecision(6) << seconds_2 << " s" << endl;
    }


    // studentu rusiavimo i dvi grupes laikas
    auto start_sort = high_resolution_clock::now();
    skirstymasLst(lst1, kietiakai, vargsiukai);
    auto end_sort = high_resolution_clock::now();
    auto duration_sort = duration_cast<microseconds>(end_sort - start_sort);
    double seconds_sort = duration_sort.count() / 1e6; // konvertuojam i sekundes
    cout << konteineris << " " << stud_num << " Studentu rusiavimas uztruko: " << fixed << setprecision(6) << seconds_sort << " s" << endl;

    //paruosimas isvedimui
    string kietiakai_filename = "kietiakai_" + to_string(stud_num) + ".txt"; //pridetas skaicius prie skirstymo failo
    string vargsiukai_filename = "vargsiukai_" + to_string(stud_num) + ".txt";

    // duomenu isvedimas i failus laikas
    auto start_write = high_resolution_clock::now();
    isvedimasLst(kietiakai_filename, kietiakai);
    isvedimasLst(vargsiukai_filename, vargsiukai);
    auto end_write = high_resolution_clock::now();
    auto duration_write = duration_cast<microseconds>(end_write - start_write);
    double seconds_write = duration_write.count() / 1e6; // konvertuojam i sekundes
    cout << konteineris << " " << stud_num << " Duomenu isvedimas uztruko: " << fixed << setprecision(6) << seconds_write << " s" << endl;

    auto overall_end = high_resolution_clock::now();
    auto overall_duration = duration_cast<microseconds>(overall_end - overall_start);
    double overall_seconds = overall_duration.count() / 1e6; // konvertuojam i sekundes
    cout << konteineris << " " << stud_num << " isviso uztruko " << fixed << setprecision(6) << overall_seconds << " s" << endl;
    cout << endl;

    lst1.clear(); //isvalomi listai
    kietiakai.clear();
    vargsiukai.clear();

}
