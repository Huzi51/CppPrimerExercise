#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::string;

int main()
{
    vector<string> svec;
    string s;
    while (cin >> s) {
        svec.push_back(s);
    }
    return 0;
}