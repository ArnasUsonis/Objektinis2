#include "lib.h"
#include "stud.h"

int main() {
    vector<stud> vec1;
    stud temp;
    srand(time(0)); // padeda taisyklingai ivykdyti random funkcija



    cout << "Do you want to read the file kursiokai.txt? (y/n): ";
    char t;
    cin >> t;

    int n;
    while (true) {
        if (t == 'y' || t == 'Y') {
            try {
                readFromFile(vec1); // bandom atidaryti faila
            } catch (const runtime_error& e) {
                cerr << "Error: " << e.what() << endl; // printinam erora
                break; // iseinam
            }


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
            int n;

            // Prompt user for the number of students
            while (true) {
                cout << "How many students do you have? ";
                cin >> n;

                // Input validation
                if (cin.fail() || n < 0) {
                    cin.clear(); // istrinam erora
                    cin.ignore(); // ignoruojam negalima inputa
                    cout << "Invalid input. Please enter a positive integer." << endl;
                } else {
                    break; // jei galimas input
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
                    cin >> ats; // kartojam uz negalima reiksme
                }
            }
            break;
        }
        else {
            cout << "Please choose an appropriate answer (y/n): ";
            cin >> t; // kartojam uz negalima reiksme
        }
    }

    system("pause");
    return 0;
}
