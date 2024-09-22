#include "lib.h"
#include "stud.h"

int main() {
    vector<stud> vec1;
    stud temp;
    srand(time(0));

    cout << "Do you want to read the file kursiokai.txt?(y/n)";
    char t;
    cin >>t;

    if(t=='y' || t=='Y'){
        readFromFile(vec1);
        cout << setw(20) << left << "Student Name" << setw(20) << left << "Surname" << setw(10) << right << "Final (avg.)" << setw(10) << right << "Final (med.):" <<endl;
        cout << "-----------------------------------------------------------------" << endl;
        for (int i = 0; i < vec1.size(); i++) {
                outputfile(vec1.at(i));
    }
    }else if(t=='n' || t=='N'){
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
    }
    system("pause");

    return 0;
}
