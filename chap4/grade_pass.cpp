#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

int main()
{
    unsigned grade = 0;
    string finalgrade;

    cout << "Input your grade: " << endl;
    cin >> grade;

    finalgrade = (grade > 90) ? "high pass"
        : (grade >= 60 && grade <= 75) ? "low pass"
        : (grade < 60) ? "fail pass" : "pass";
    cout << finalgrade << endl;
}