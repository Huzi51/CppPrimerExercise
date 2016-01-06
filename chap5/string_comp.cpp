#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string rsp;
    do {
        string s1, s2;
        cout << "Please enter two string: ";
        cin >> s1 >> s2;
        cout << (s1.size() > s2.size() ? s1 : s2) << " is longer." << "\n\n"
             << "More? Enter yes/no: ";
        cin >> rsp;
    } while (rsp != "no");
    return 0;
}