#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

using std::string;

int main()
{
    string s("hello world");
    for (decltype(s.size()) index = 0; index != s.size(); index++) {
        s[index] = 'X';
    }
    cout << s << endl;
    return 0;
}