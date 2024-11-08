#include "stud.h"
#include "lib.h"

void measureTimeLst2str(const string filename, int stud_num, int pasirinkimas, string konteineris) {
    list<stud> lst1, vargsiukai;

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
    skirstymasLst2str(lst1, vargsiukai);
    auto end_sort = high_resolution_clock::now();
    auto duration_sort = duration_cast<microseconds>(end_sort - start_sort);
    double seconds_sort = duration_sort.count() / 1e6; // konvertuojam i sekundes
    cout << konteineris << " " << stud_num << " Studentu rusiavimas uztruko: " << fixed << setprecision(6) << seconds_sort << " s" << endl;

    //paruosimas isvedimui
    string kietiakai_filename = "kietiakai_" + to_string(stud_num) + ".txt"; //pridetas skaicius prie skirstymo failo
    string vargsiukai_filename = "vargsiukai_" + to_string(stud_num) + ".txt";

    // duomenu isvedimas i failus laikas
    auto start_write = high_resolution_clock::now();
    isvedimasLst(kietiakai_filename, lst1);
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
    vargsiukai.clear();

}

void skirstymasLst2str(list<stud>& lst1, list<stud>& vargsiukai) {
    for (auto it = lst1.begin(); it != lst1.end(); ) {
        if (it->vid < 5.0) {
            vargsiukai.push_back(*it);
            it = lst1.erase(it);
        } else {
            ++it;
        }
    }
}

void measureTimeVec2str(const string filename, int stud_num, int pasirinkimas, string konteineris) {
    vector<stud> vec1, vargsiukai;

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
    readFromFile(filename, vec1);
    auto end_read = high_resolution_clock::now();
    auto duration_read = duration_cast<microseconds>(end_read - start_read);
    double seconds_read = duration_read.count() / 1e6; // konvertuojam i sekundes
    cout << konteineris << " " << stud_num << " Duomenu nuskaitymas uztruko: " << fixed << setprecision(6) << seconds_read << " s" << endl;

    // rusiavimas pagal varda arba pavarde
    if (pasirinkimas == 1) {
        auto start_1 = high_resolution_clock::now();
        // rusiavimas pagal varda
        sort(vec1.begin(), vec1.end(), [](const stud& a, const stud& b) {
            return a.vardas < b.vardas;
        });
        auto end_1 = high_resolution_clock::now();
        auto duration_1 = duration_cast<microseconds>(end_gen - start_gen);
        auto seconds_1 = duration_gen.count() / 1e6; // konvertuojam i sekundes
        cout << konteineris << " " << stud_num << " Studentai surusiuoti pagal vardus per " << fixed << setprecision(6) << seconds_1 << " s" << endl;

    } else if (pasirinkimas == 2) {
        auto start_2 = high_resolution_clock::now();
        // rusiavimas pagal pavarde
        sort(vec1.begin(), vec1.end(), [](const stud& a, const stud& b) {
            return a.pavarde < b.pavarde;
        });
        auto end_2 = high_resolution_clock::now();
        auto duration_2 = duration_cast<microseconds>(end_gen - start_gen);
        auto seconds_2 = duration_gen.count() / 1e6; // konvertuojam i sekundes
        cout << konteineris << " " << stud_num << " Studentai surusiuoti pagal pavardes per " << fixed << setprecision(6) << seconds_2 << " s" << endl;

    }

    // studentu rusiavimo i dvi grupes laikas
    auto start_sort = high_resolution_clock::now();
    skirstymas2str(vec1, vargsiukai);
    auto end_sort = high_resolution_clock::now();
    auto duration_sort = duration_cast<microseconds>(end_sort - start_sort);
    double seconds_sort = duration_sort.count() / 1e6; // konvertuojam i sekundes
    cout << konteineris << " " << stud_num << " Studentu rusiavimas uztruko: " << fixed << setprecision(6) << seconds_sort << " s" << endl;

    //paruosimas isvedimui
    string kietiakai_filename = "kietiakai_" + to_string(stud_num) + ".txt"; //pridetas skaicius prie skirstymo failo
    string vargsiukai_filename = "vargsiukai_" + to_string(stud_num) + ".txt";

    // duomenu isvedimas i failus laikas
    auto start_write = high_resolution_clock::now();
    isvedimas(kietiakai_filename, vec1);
    isvedimas(vargsiukai_filename, vargsiukai);
    auto end_write = high_resolution_clock::now();
    auto duration_write = duration_cast<microseconds>(end_write - start_write);
    double seconds_write = duration_write.count() / 1e6; // konvertuojam i sekundes
    cout << konteineris << " " << stud_num << " Duomenu isvedimas uztruko: " << fixed << setprecision(6) << seconds_write << " s" << endl;

    auto overall_end = high_resolution_clock::now();
    auto overall_duration = duration_cast<microseconds>(overall_end - overall_start);
    double overall_seconds = overall_duration.count() / 1e6; // konvertuojam i sekundes
    cout << konteineris << " " << stud_num << " isviso uztruko " << fixed << setprecision(6) << overall_seconds << " s" << endl;
    cout << endl;

    val(vec1); //isvalomi vektoriai
    val(vargsiukai);

}

void skirstymas2str(vector<stud>& vec1, vector<stud>& vargsiukai) {
    for (size_t i = 0; i < vec1.size(); ) {
        if (vec1[i].vid < 5.0) {
            vargsiukai.push_back(vec1[i]);
            // vec1.begin yra kaip iteratorius kuris pointina i pirma elementa ir pridejus i prideda prie indexo ta i tai prie 0 + i bet gaunam reiksme to indekso vietoje
            vec1.erase(vec1.begin() + i);
        } else {
            i++;
        }
    }
}

void kokiastrategija(int strat, int kont,const int studentu_skaicius[], int pasirinkimas, const string& konteineris, size_t studskaic) {
    for (size_t i = 0; i < studskaic; ++i) {
        int numeris = studentu_skaicius[i];
        if (strat == 1) {
            if (kont == 1) {
                string filename = "studentai_" + to_string(numeris) + ".txt";
                measureTimeVec(filename, numeris, pasirinkimas, konteineris);
            } else if (kont == 2) {
                string filename = "studentai_" + to_string(numeris) + ".txt";
                measureTimeLst(filename, numeris, pasirinkimas, konteineris);
            }
        } else if (strat == 2) {
            if (kont == 1) {
                string filename = "studentai_" + to_string(numeris) + ".txt";
                measureTimeVec2str(filename, numeris, pasirinkimas, konteineris);
            } else if (kont == 2) {
                string filename = "studentai_" + to_string(numeris) + ".txt";
                measureTimeLst2str(filename, numeris, pasirinkimas, konteineris);
            }
        } else if (strat == 3) {
                string filename = "studentai_" + to_string(numeris) + ".txt";
                measureTimeVec3str(filename, numeris, pasirinkimas, konteineris);
        }
    }
}

void measureTimeVec3str(const string filename, int stud_num, int pasirinkimas, string konteineris) {
    vector<stud> vec1, vargsiukai;

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
    readFromFile(filename, vec1);
    auto end_read = high_resolution_clock::now();
    auto duration_read = duration_cast<microseconds>(end_read - start_read);
    double seconds_read = duration_read.count() / 1e6; // konvertuojam i sekundes
    cout << konteineris << " " << stud_num << " Duomenu nuskaitymas uztruko: " << fixed << setprecision(6) << seconds_read << " s" << endl;

    // rusiavimas pagal varda arba pavarde
    if (pasirinkimas == 1) {
        auto start_1 = high_resolution_clock::now();
        // rusiavimas pagal varda
        sort(vec1.begin(), vec1.end(), [](const stud& a, const stud& b) {
            return a.vardas < b.vardas;
        });
        auto end_1 = high_resolution_clock::now();
        auto duration_1 = duration_cast<microseconds>(end_gen - start_gen);
        auto seconds_1 = duration_gen.count() / 1e6; // konvertuojam i sekundes
        cout << konteineris << " " << stud_num << " Studentai surusiuoti pagal vardus per " << fixed << setprecision(6) << seconds_1 << " s" << endl;

    } else if (pasirinkimas == 2) {
        auto start_2 = high_resolution_clock::now();
        // rusiavimas pagal pavarde
        sort(vec1.begin(), vec1.end(), [](const stud& a, const stud& b) {
            return a.pavarde < b.pavarde;
        });
        auto end_2 = high_resolution_clock::now();
        auto duration_2 = duration_cast<microseconds>(end_gen - start_gen);
        auto seconds_2 = duration_gen.count() / 1e6; // konvertuojam i sekundes
        cout << konteineris << " " << stud_num << " Studentai surusiuoti pagal pavardes per " << fixed << setprecision(6) << seconds_2 << " s" << endl;

    }

    // studentu rusiavimo i dvi grupes laikas
    auto start_sort = high_resolution_clock::now();
    skirstymas3str(vec1, vargsiukai);
    auto end_sort = high_resolution_clock::now();
    auto duration_sort = duration_cast<microseconds>(end_sort - start_sort);
    double seconds_sort = duration_sort.count() / 1e6; // konvertuojam i sekundes
    cout << konteineris << " " << stud_num << " Studentu rusiavimas uztruko: " << fixed << setprecision(6) << seconds_sort << " s" << endl;

    //paruosimas isvedimui
    string kietiakai_filename = "kietiakai_" + to_string(stud_num) + ".txt"; //pridetas skaicius prie skirstymo failo
    string vargsiukai_filename = "vargsiukai_" + to_string(stud_num) + ".txt";

    // duomenu isvedimas i failus laikas
    auto start_write = high_resolution_clock::now();
    isvedimas(kietiakai_filename, vec1);
    isvedimas(vargsiukai_filename, vargsiukai);
    auto end_write = high_resolution_clock::now();
    auto duration_write = duration_cast<microseconds>(end_write - start_write);
    double seconds_write = duration_write.count() / 1e6; // konvertuojam i sekundes
    cout << konteineris << " " << stud_num << " Duomenu isvedimas uztruko: " << fixed << setprecision(6) << seconds_write << " s" << endl;

    auto overall_end = high_resolution_clock::now();
    auto overall_duration = duration_cast<microseconds>(overall_end - overall_start);
    double overall_seconds = overall_duration.count() / 1e6; // konvertuojam i sekundes
    cout << konteineris << " " << stud_num << " isviso uztruko " << fixed << setprecision(6) << overall_seconds << " s" << endl;
    cout << endl;

    val(vec1); //isvalomi vektoriai
    val(vargsiukai);

}

bool arvargsiukas(const stud& s) {
    return s.vid < 5.0;
}

void skirstymas3str(vector<stud>& vec1, vector<stud>& vargsiukai) {
    auto it = remove_if(vec1.begin(), vec1.end(), arvargsiukas);
    copy(vec1.begin(), it, back_inserter(vargsiukai));
    vec1.erase(it, vec1.end());
}

