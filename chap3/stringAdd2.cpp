#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

int main()
{
    string total, s;
    while(cin >> s) {
        total += s;
    }
    cout << total << endl;
    return 0;
}