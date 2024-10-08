#include "stud.h"
#include "lib.h"

void ived(stud &lok) {
    cout << "Input name and surname: ";
    cin >> lok.vardas >> lok.pavarde;

    char r;
    bool validInput = false; // tikrinimas ar naudotojas pasirinko viena is galimu ats


    while (!validInput) {
        cout << "Do you want to randomize exam and homework grades? (y/n)" << endl;
        cin >> r;

        if (r == 'y' || r == 'Y') {
            validInput = true;

            int kiekisNd = rand() % 5 + 1; // nd kiekis (1-5)
            for (int i = 0; i < kiekisNd; i++) {
                double namuDarbas = rand() % 10 + 1; // nd pazymys (1-10)
                lok.nd.push_back(namuDarbas);
            }
            lok.egz = rand() % 10 + 1; // egz (1-10)

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
                    break; //nutraukiam cikla
                }
                lok.nd.push_back(balas);

            }

            while(true){
            cout << "Enter exam score: ";
            cin >> lok.egz;
            if (cin.fail() || lok.egz<=0) {
                cin.clear();
                cin.ignore();
                cout << "Invalid input for exam score."<<endl;
                continue;
            }break;

            }
        } else {
            cout << "Please choose an appropriate answer (y/n)" << endl;
        }
    }
}

void outputvid(stud lok)
{
    cout<< setw(15) <<left<< lok.vardas << setw(10)<<left<< lok.pavarde << setw(3) <<right<< fixed << setprecision(2) << lok.vid <<endl;
}

void outputmed(stud lok)
{
    cout<< setw(15) <<left<< lok.vardas << setw(10)<<left<< lok.pavarde << setw(3) <<right<< fixed << setprecision(2) << lok.med <<endl;
}

void outputfile(stud lok)
{
    cout << setw(20) << left << lok.vardas << setw(20) << left << lok.pavarde << setw(10) << right << fixed << setprecision(2) << lok.vid << setw(10) << right << fixed << setprecision(2) << lok.med << endl;
}

void val(stud &lok){
    lok.vardas.clear();
    lok.pavarde.clear();
    lok.nd.clear();

}

double vidurkis(stud &lok){
    if (lok.nd.empty()) {
        cout<< "Error: No homework grades provided for average!" << endl;
        lok.vid = 0.0; // Nustatome vidurkį į 0, jei nėra pažymių
        return lok.vid;
    }

    double sum = 0.0;

    for (int i = 0; i < lok.nd.size(); i++) {
        sum += lok.nd[i];
    }

    double avghomework = sum / lok.nd.size();

    lok.vid = 0.4 * avghomework + 0.6 * lok.egz;

    return lok.vid;
}

double mediana(stud &lok){
    if (lok.nd.empty()) {
        cout<< "Error: No homework grades provided for mediana!" << endl;
        lok.med = 0.0; // Nustatome mediana i 0 jei nėra pažymių
        return lok.vid;
    }

    sort(lok.nd.begin(), lok.nd.end());

    if (lok.nd.size() % 2 == 0){
            int middleIndex1 = lok.nd.size() / 2 - 1;
            int middleIndex2 = lok.nd.size() / 2;
            double medianValue = (lok.nd[middleIndex1] + lok.nd[middleIndex2]) / 2.0;
        lok.med = 0.4*medianValue+0.6*lok.egz;

        return lok.med;
    }else{
        int middleIndex = lok.nd.size() / 2;
            int vid = lok.nd[middleIndex];
            lok.med = 0.4*vid+0.6*lok.egz;

            return lok.med;
    }
}

void readFromFile(const string &failas, vector<stud>& vec1) {
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
        if (studentas.vid >= 5.0) {
            kietiakai.push_back(studentas);
        } else {
            vargsiukai.push_back(studentas);
        }
    }
}

void isvedimas(const string pavadinimas, const vector<stud>& vec1) {
     ofstream out(pavadinimas);
    out << left << setw(15) << "Vardas" << setw(15) << "Pavarde"
        << setw(10) << "Galutinis" << endl;
    out << "----------------------------------------------" << endl;

    for (const auto& studentas : vec1) {
        out << left << setw(15) << studentas.vardas
            << setw(15) << studentas.pavarde
            << setw(10) << fixed << setprecision(2)
            << studentas.vid << endl;
    }
}

void measureTime(const string filename, int stud_num) {
    vector<stud> vec1, kietiakai, vargsiukai;

    // Overall timer
    auto overall_start = high_resolution_clock::now();

    // 1. failo kurimo laikas
    auto start_gen = high_resolution_clock::now();
    generavimas(filename, stud_num);
    auto end_gen = high_resolution_clock::now();
    auto duration_gen = duration_cast<microseconds>(end_gen - start_gen);
    double seconds_gen = duration_gen.count() / 1e6; // konvertuojam i sekundes
    cout << stud_num << " Failo kurimas uztruko: " << fixed << setprecision(6) << seconds_gen << " s" << endl;

    // 2. duomenu nuskaitymo laikas
    auto start_read = high_resolution_clock::now();
    readFromFile("studentai_1000.txt", vec1);
    auto end_read = high_resolution_clock::now();
    auto duration_read = duration_cast<microseconds>(end_read - start_read);
    double seconds_read = duration_read.count() / 1e6;
    cout << stud_num << " Duomenu nuskaitymas uztruko: " << fixed << setprecision(6) << seconds_read << " s" << endl;

    // 3. studentu rusiavimo i dvi grupes laikas
    auto start_sort = high_resolution_clock::now();
    skirstymas(vec1, kietiakai, vargsiukai);
    auto end_sort = high_resolution_clock::now();
    auto duration_sort = duration_cast<microseconds>(end_sort - start_sort);
    double seconds_sort = duration_sort.count() / 1e6;
    cout << stud_num << " Studentu rusiavimas uztruko: " << fixed << setprecision(6) << seconds_sort << " s" << endl;

    // 4. duomenu isvedimas i failus laikas
    auto start_write = high_resolution_clock::now();
    isvedimas("kietiakai.txt", kietiakai);
    isvedimas("vargsiukai.txt", vargsiukai);
    auto end_write = high_resolution_clock::now();
    auto duration_write = duration_cast<microseconds>(end_write - start_write);
    double seconds_write = duration_write.count() / 1e6;
    cout << stud_num << " Duomenu isvedimas uztruko: " << fixed << setprecision(6) << seconds_write << " s" << endl;

    auto overall_end = high_resolution_clock::now();
    auto overall_duration = duration_cast<microseconds>(overall_end - overall_start);
    double overall_seconds = overall_duration.count() / 1e6;
    cout << stud_num << " isviso uztruko " << fixed << setprecision(6) << overall_seconds << " s" << endl;
}
