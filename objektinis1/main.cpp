#include "lib.h"
#include "stud.h"

int main() {
    vector<stud> vec1, kietiakai, vargsiukai;
    stud temp;
    srand(time(0)); // padeda taisyklingai ivykdyti random funkcija
    int pasirinkimas;

    int studentu_skaicius[] = {1000, 10000, 100000, 1000000, 10000000};

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


    for (int numeris : studentu_skaicius) {
        string filename = "studentai_" + to_string(numeris) + ".txt";
        measureTime(filename, numeris, pasirinkimas);
    }


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
