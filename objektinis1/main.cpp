#include "lib.h"
#include "stud.h"

int main()
{
    vector<stud> vec1;
    stud temp;
    cout<<"how many student do you have?";
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
    cout <<"Please input user data: "<< endl;
    ived(temp);
    vidurkis(temp);
    vec1.push_back(temp);
    val(temp);
    }

    cout<<setw(15) <<left<<"student Name"<< setw(10)<<left<<"surname:"<<setw(3) << left <<"Final (avg.):"<<endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    for (int i=0; i<n; i++)
        output(vec1.at(i));

    system("pause");

    return 0;
}
