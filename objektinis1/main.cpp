#include "lib.h"
#include "stud.h"

int main() {
    vector<stud> vec1, kietiakai, vargsiukai;
    stud temp;
    srand(time(0)); // padeda taisyklingai ivykdyti random funkcija

    // 1. failo kurimo laikas
    auto start_gen = high_resolution_clock::now();
    generavimas("studentai_1000.txt", 1000);
    auto end_gen = high_resolution_clock::now();
    auto duration_gen = duration_cast<microseconds>(end_gen - start_gen);
    double seconds_gen = duration_gen.count() / 1e6; // konvertuojam i sekundes
    cout << "Failo kurimas uztruko: " << fixed << setprecision(6) << seconds_gen << " s" << endl;

    // 2. duomenu nuskaitymo laikas
    auto start_read = high_resolution_clock::now();
    readFromFile("studentai_1000.txt", vec1);
    auto end_read = high_resolution_clock::now();
    auto duration_read = duration_cast<microseconds>(end_read - start_read);
    double seconds_read = duration_read.count() / 1e6;
    cout << "Duomenu nuskaitymas uztruko: " << fixed << setprecision(6) << seconds_read << " s" << endl;

    // 3. studentu rusiavimo i dvi grupes laikas
    auto start_sort = high_resolution_clock::now();
    skirstymas(vec1, kietiakai, vargsiukai);
    auto end_sort = high_resolution_clock::now();
    auto duration_sort = duration_cast<microseconds>(end_sort - start_sort);
    double seconds_sort = duration_sort.count() / 1e6;
    cout << "Studentu rusiavimas uztruko: " << fixed << setprecision(6) << seconds_sort << " s" << endl;

    // 4. duomenu isvedimas i failus laikas
    auto start_write = high_resolution_clock::now();
    isvedimas("kietiakai.txt", kietiakai);
    isvedimas("vargsiukai.txt", vargsiukai);
    auto end_write = high_resolution_clock::now();
    auto duration_write = duration_cast<microseconds>(end_write - start_write);
    double seconds_write = duration_write.count() / 1e6;
    cout << "Duomenu isvedimas uztruko: " << fixed << setprecision(6) << seconds_write << " s" << endl;


    /*while(true){
        cout << "choose which testing file you want to open: "<<endl;
        cout << "studentai10000.txt - (press 1 and enter)"<<endl;
        cout << "studentai100000.txt - (press 2 and enter)"<<endl;
        cout << "studentai1000000.txt - (press 3 and enter)"<<endl;
        cout << "type any other number to not read these files"<<endl;

        int pasir;
        cin >> pasir;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << std::endl;
            continue;  // paklausia vel
        }

        if(pasir == 1){
            try {
                readFromFile("studentai10000.txt", vec1); // bandom atidaryti faila
            } catch (const runtime_error& e) {
                cerr << "Error: " << e.what() << endl; // printinam erora
                return 0; // iseinam
            }
            cout << setw(20) << left << "Student Name"
                 << setw(20) << left << "Surname"
                 << setw(10) << right << "Final (avg.)"
                 << setw(10) << right << "Final (med.):" << endl;
            cout << "-----------------------------------------------------------------" << endl;

            for (size_t i = 0; i < vec1.size(); ++i) {
                outputfile(vec1.at(i)); // spauzdinam rezultatus
            }
            return 0; // iseinam is loop perskaicius faila
        }else if(pasir == 2){
            try {
                readFromFile("studentai100000.txt", vec1); // bandom atidaryti faila
            } catch (const runtime_error& e) {
                cerr << "Error: " << e.what() << endl; // printinam erora
                return 0; // iseinam
            }
            cout << setw(20) << left << "Student Name"
                 << setw(20) << left << "Surname"
                 << setw(10) << right << "Final (avg.)"
                 << setw(10) << right << "Final (med.):" << endl;
            cout << "-----------------------------------------------------------------" << endl;

            for (size_t i = 0; i < vec1.size(); ++i) {
                outputfile(vec1.at(i)); // spauzdinam rezultatus
            }
            return 0; // iseinam is loop perskaicius faila
        }else if(pasir == 3){
            try {
                readFromFile("studentai1000000.txt", vec1); // bandom atidaryti faila
            } catch (const runtime_error& e) {
                cerr << "Error: " << e.what() << endl; // printinam erora
                return 0; // iseinam
            }
            cout << setw(20) << left << "Student Name"
                 << setw(20) << left << "Surname"
                 << setw(10) << right << "Final (avg.)"
                 << setw(10) << right << "Final (med.):" << endl;
            cout << "-----------------------------------------------------------------" << endl;

            for (size_t i = 0; i < vec1.size(); ++i) {
                outputfile(vec1.at(i)); // spauzdinam rezultatus
            }
            return 0; // iseinam is loop perskaicius faila
        }else{
            break;
        }
    }

    cout << "Do you want to read the file kursiokai.txt? (y/n): ";
    char t;
    cin >> t;

    int n;
    while (true) {
        if (t == 'y' || t == 'Y') {
            try {
                readFromFile("kursiokai.txt", vec1); // bandom atidaryti faila
            } catch (const runtime_error& e) {
                cerr << "Error: " << e.what() << endl; // printinam erora
                return 0; // iseinam
            }

            // rusiavimas pagal varda
            sort(vec1.begin(), vec1.end(), [](const stud& a, const stud& b) {
                return a.vardas < b.vardas;
            });

            // Išvedimas
            cout << setw(20) << left << "Student Name"
                 << setw(20) << left << "Surname"
                 << setw(10) << right << "Final (avg.)"
                 << setw(10) << right << "Final (med.):" << endl;
            cout << "-----------------------------------------------------------------" << endl;

            for (size_t i = 0; i < vec1.size(); ++i) {
                outputfile(vec1.at(i)); // spauzdinam rezultatus
            }
            break; // iseinam is loop perskaicius faila
        }
        else if (t == 'n' || t == 'N') {
            while (true) {
                cout << "How many students do you have? ";
                cin >> n;

                // Tikrinam vartotojo ivestus duomenis
                if (cin.fail() || n < 0) {
                    cin.clear(); // istrinam klaida
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignoruojam neteisingą inputa
                    cout << "Invalid input. Please enter a positive integer." << endl;
                } else {
                    break; // jei įvestis teisinga, nutraukiam ciklą
                }
            }

            for (int i = 0; i < n; ++i) {
                cout << "Please input user data: " << endl;
                ived(temp);
                vidurkis(temp);
                mediana(temp);
                vec1.push_back(temp);
                val(temp);
            }


            sort(vec1.begin(), vec1.end(), [](const stud& a, const stud& b) {
                return a.vardas < b.vardas;
            });

            cout << "Do you want to use median for the final grades? (y/n): ";
            char ats;
            cin >> ats;

            while (true) {
                if (ats == 'n' || ats == 'N') {
                    cout << setw(15) << left << "Student Name"
                         << setw(10) << left << "Surname"
                         << setw(3) << left << "Final (avg.):" << endl;
                    cout << "-----------------------------------------------------------" << endl;

                    for (int i = 0; i < n; ++i) {
                        outputvid(vec1.at(i));
                    }
                    break;
                }
                else if (ats == 'y' || ats == 'Y') {
                    cout << setw(15) << left << "Student Name"
                         << setw(10) << left << "Surname"
                         << setw(3) << left << "Final (med.):" << endl;
                    cout << "-----------------------------------------------------------" << endl;

                    for (int i = 0; i < n; ++i) {
                        outputmed(vec1.at(i));
                    }
                    break;
                }
                else {
                    cout << "Please choose an appropriate answer (y/n): ";
                    cin >> ats; // kartojam, jei įvesta neteisingai
                }
            }
            break;
        }
        else {
            cout << "Please choose an appropriate answer (y/n): ";
            cin >> t; // kartojam, jei įvesta neteisingai
        }
    }*/

    system("pause");
    return 0;
}
