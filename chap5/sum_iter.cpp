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
        int val = 0, val2 = 0;
        cout << "please input two number: ";
        cin >> val >> val2;
        cout << "The sum of " << val
             << " and " << val2 << " is " << val + val2 << "\n\n";
        cout << "More? Enter yes of no: ";
        cin >> rsp;
    } while (!rsp.empty() && rsp != "no");
    return 0;
}