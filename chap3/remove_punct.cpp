#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

using std::string;

int main()
{
    string s("hello, wrold!!");
    string s2;
    for (auto c : s) {
        if (!ispunct(c)) {
            s2 += c;
        }
    }
    cout << s2 << endl;
    return 0;
}