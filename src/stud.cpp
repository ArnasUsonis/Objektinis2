#include "stud.h"
#include "lib.h"

void ived(stud &lok) {
    cout << "Input name and surname: ";
    string vardas, pavarde;
    cin >> vardas >> pavarde;
    lok.setVardas(vardas);
    lok.setPavarde(pavarde);

    char r;
    bool validInput = false; // check if user chooses one of the valid options

    while (!validInput) {
        cout << "Do you want to randomize exam and homework grades? (y/n)" << endl;
        cin >> r;

        if (r == 'y' || r == 'Y') {
            validInput = true;

            int kiekisNd = rand() % 5 + 1; // number of homework assignments (1-5)
            for (int i = 0; i < kiekisNd; i++) {
                double namuDarbas = rand() % 10 + 1; // homework grade (1-10)
                lok.addNd(namuDarbas);
            }
            lok.setEgz(rand() % 10 + 1); // exam grade (1-10)

        } else if (r == 'n' || r == 'N') {
            validInput = true;

            cout << "Enter a homework grade and press enter (enter -1 to end it):" << endl;
            double balas;
            while (true) {
                cin >> balas;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Invalid input. Please enter homework grade and press enter: ";
                    continue;
                }

                if (balas <= 0 && balas != -1) {
                    cout << "Invalid input. Please enter a non-negative number or -1 to finish: ";
                    continue;
                }

                if (balas == -1) {
                    break; // end the loop
                }
                lok.addNd(balas);
            }

            while (true) {
                cout << "Enter exam score: ";
                double score;
                cin >> score;

                if (cin.fail() || score <= 0) {
                    cin.clear();
                    cin.ignore();
                    cout << "Invalid input for exam score." << endl;
                    continue;
                } else {
                    lok.setEgz(score); // properly set the exam score
                    break; // exit the loop after valid input
                }
            }
        } else {
            cout << "Please choose an appropriate answer (y/n)" << endl;
        }
    }
}


void outputvid(stud lok)
{
    cout<< setw(15) <<left<< lok.getVardas() << setw(10)<<left<< lok.getPavarde() << setw(3) <<right<< fixed << setprecision(2) << lok.getVid() <<endl;
}

void outputmed(stud lok)
{
    cout<< setw(15) <<left<< lok.getVardas() << setw(10)<<left<< lok.getPavarde() << setw(3) <<right<< fixed << setprecision(2) << lok.getMed() <<endl;
}

void outputfile(stud lok)
{
    cout << setw(20) << left << lok.getVardas() << setw(20) << left << lok.getPavarde() << setw(10) << right << fixed << setprecision(2) << lok.getVid() << setw(10) << right << fixed << setprecision(2) << lok.getMed() << endl;
}
//pakeista
void val(vector<stud>& vec){
    vec.clear();
}

double vidurkis(stud &lok) {
    if (lok.getNd().empty()) {
        cout << "Error: No homework grades provided for average!" << endl;
        lok.setVid(0.0);
        return 0.0;
    }

    double sum = 0.0;
    const std::vector<double>& homeworkGrades = lok.getNd();

    for (size_t i = 0; i < homeworkGrades.size(); i++) {
        sum += homeworkGrades[i];
    }

    double avghomework = sum / homeworkGrades.size();
    double weightedAverage = 0.4 * avghomework + 0.6 * lok.getEgz();

    lok.setVid(weightedAverage);
    return weightedAverage;
}

double mediana(stud &lok) {
    if (lok.getNd().empty()) {
        cout << "Error: No homework grades provided for mediana!" << endl;
        lok.setMed(0.0);
        return 0.0;
    }

    std::vector<double> homeworkGrades = lok.getNd();
    std::sort(homeworkGrades.begin(), homeworkGrades.end());

    double medianValue;
    size_t size = homeworkGrades.size();
    if (size % 2 == 0) {

        medianValue = (homeworkGrades[size / 2 - 1] + homeworkGrades[size / 2]) / 2.0;
    } else {

        medianValue = homeworkGrades[size / 2];
    }

    double weightedMedian = 0.4 * medianValue + 0.6 * lok.getEgz();
    lok.setMed(weightedMedian);
    return weightedMedian;
}

void readFromFile(const string &failas, vector<stud>& vec1) {
    ifstream file(failas);

    if (!file) {
        throw runtime_error("Unable to open file: " + failas);
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        istringstream iss(line);
        stud temp;
        string vardas, pavarde;
        double grade;

        iss >> vardas >> pavarde;
        temp.setVardas(vardas);
        temp.setPavarde(pavarde);

        vector<double> homeworkGrades;
        while (iss >> grade) {
            homeworkGrades.push_back(grade);
        }

        if (homeworkGrades.empty()) {
            cerr << "No grades found for student: " << vardas << " " << pavarde << endl;
            continue;
        }

        temp.setEgz(homeworkGrades.back());
        homeworkGrades.pop_back();
        temp.setNd(homeworkGrades);

        vidurkis(temp);
        mediana(temp);

        vec1.push_back(temp);
    }

    file.close();
}

void generavimas(const string filename, int stud_kiekis) {
    ofstream outfile(filename);

    if (!outfile.is_open()) {
        cerr << "Nepavyko atidaryti failo: " << filename << endl;
        return;
    }

    outfile << "Vardas Pavarde ND1 ND2 ND3 ND4 ND5 Egzaminas" << endl; //antraste

    for (int i = 1; i <= stud_kiekis; ++i) {
        outfile << "Vardas" << i << " Pavarde" << i << " ";

        for (int j = 0; j < 5; ++j) {
            outfile << random_number();
            if (j < 4) {
                outfile << " "; // tarpas tarp pazymiu
            }
        }

        outfile << " " << random_number() << endl; // egzamino rezultatas
    }

    outfile.close();
    cout << "Sugeneruotas failas: " << filename << " su " << stud_kiekis << " irasu." << endl;
}

int random_number() {
    return rand() % 10 + 1;// pazymys (1-10)
}

void skirstymas(const vector<stud>& vec1, vector<stud>& kietiakai, vector<stud>& vargsiukai) {
    for (const stud& studentas : vec1) {
        if (studentas.getVid() >= 5.0) {
            kietiakai.push_back(studentas);
        } else {
            vargsiukai.push_back(studentas);
        }
    }
}

void isvedimas(const string pavadinimas, const vector<stud>& vec1) {
     ofstream out(pavadinimas);
    out << left << setw(15) << "Vardas" << setw(15) << "Pavarde"
        << setw(10) << "Galutinis" << setw(20) << "Adresas" << endl;
    out << "-------------------------------------------------------------" << endl;

    for (const auto& studentas : vec1) {
        out << left << setw(15) << studentas.getVardas()
            << setw(15) << studentas.getPavarde()
            << setw(10) << fixed << setprecision(2) << studentas.getVid()
            << setw(20) << &studentas << endl;
    }
}

void measureTimeVec(const string filename, int stud_num, int pasirinkimas, string konteineris) {
    vector<stud> vec1, kietiakai, vargsiukai;

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
            return a.getVardas() < b.getVardas();
        });
        auto end_1 = high_resolution_clock::now();
        auto duration_1 = duration_cast<microseconds>(end_gen - start_gen);
        auto seconds_1 = duration_gen.count() / 1e6; // konvertuojam i sekundes
        cout << konteineris << " " << stud_num << " Studentai surusiuoti pagal vardus per " << fixed << setprecision(6) << seconds_1 << " s" << endl;

    } else if (pasirinkimas == 2) {
        auto start_2 = high_resolution_clock::now();
        // rusiavimas pagal pavarde
        sort(vec1.begin(), vec1.end(), [](const stud& a, const stud& b) {
            return a.getPavarde() < b.getPavarde();
        });
        auto end_2 = high_resolution_clock::now();
        auto duration_2 = duration_cast<microseconds>(end_gen - start_gen);
        auto seconds_2 = duration_gen.count() / 1e6; // konvertuojam i sekundes
        cout << konteineris << " " << stud_num << " Studentai surusiuoti pagal pavardes per " << fixed << setprecision(6) << seconds_2 << " s" << endl;

    }

    // studentu rusiavimo i dvi grupes laikas
    auto start_sort = high_resolution_clock::now();
    skirstymas(vec1, kietiakai, vargsiukai);
    auto end_sort = high_resolution_clock::now();
    auto duration_sort = duration_cast<microseconds>(end_sort - start_sort);
    double seconds_sort = duration_sort.count() / 1e6; // konvertuojam i sekundes
    cout << konteineris << " " << stud_num << " Studentu rusiavimas uztruko: " << fixed << setprecision(6) << seconds_sort << " s" << endl;

    //paruosimas isvedimui
    string kietiakai_filename = "kietiakai_" + to_string(stud_num) + ".txt"; //pridetas skaicius prie skirstymo failo
    string vargsiukai_filename = "vargsiukai_" + to_string(stud_num) + ".txt";

    // duomenu isvedimas i failus laikas
    auto start_write = high_resolution_clock::now();
    isvedimas(kietiakai_filename, kietiakai);
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
    val(kietiakai);
    val(vargsiukai);

}

void strategija(int &strat)
{
    while(true){
        cout << "pasirinkite strategija:" << endl;
        cout << "1 arba 2 arba 3" << endl;
        cin >> strat;

        if (strat != 1 && strat != 2 && strat != 3){
            continue;
        }else{
            break;
        }
    }
}

