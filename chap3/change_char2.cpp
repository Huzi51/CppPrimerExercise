#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

using std::string;

int main()
{
    string s("hello word");
    decltype(s.size()) index = 0;
    while (index != s.size()) {
        s[index++] = 'X';
    }
    cout << s << endl;
    return 0;
}