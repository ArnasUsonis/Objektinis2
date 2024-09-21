#include "lib.h"
#include "stud.h"

int main() {
    vector<stud> vec1;
    stud temp;

    cout << "How many students do you have? ";
    int n;
    cin >> n;


    for (int i = 0; i < n; i++) {
        cout << "Please input user data: " << endl;
        ived(temp);
        vidurkis(temp);
        mediana(temp);
        vec1.push_back(temp);
        val(temp);
    }

    // Prompt for using median or not
    cout << "Do you want to use median for the final grades? (y/n): ";
    char ats;
    cin >> ats;

    if (ats == 'n' || ats == 'N') {
        cout << setw(15) << left << "Student Name" << setw(10) << left << "Surname" << setw(3) << left << "Final (avg.):" << endl;
        cout << "-----------------------------------------------------------" << endl;

        for (int i = 0; i < n; i++)
            outputvid(vec1.at(i));
    }
    else if (ats == 'y' || ats == 'Y') {
        cout << setw(15) << left << "Student Name" << setw(10) << left << "Surname" << setw(3) << left << "Final (med.):" << endl;
        cout << "-----------------------------------------------------------" << endl;

        for (int i = 0; i < n; i++)
            outputmed(vec1.at(i));
    }

    system("pause");

    return 0;
}
