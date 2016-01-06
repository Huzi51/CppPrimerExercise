#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

using std::string;

int main()
{
    const string s = "keep out";
    for (auto &c : s) { // c's type is (const char)
        c = 'x';
    }
    return 0;
}