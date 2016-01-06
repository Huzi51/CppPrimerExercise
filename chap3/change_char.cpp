#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

using std::string;

int main()
{
    string s("hello, word");
    for (char &c : s) { // auto/char
        c = 'X';
    }
    cout << s << endl;
    return 0;
}