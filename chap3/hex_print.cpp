#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

using std::string;

int main()
{
    const string hexdigits = "123456789ABCDEF";
    string result;
    string::size_type n;
    while (cin >> n) {
        if (n < hexdigits.size()) {
            result += hexdigits[n];
        }
    }
    cout << result << endl;
    return 0;
}