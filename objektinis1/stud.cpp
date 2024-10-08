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

