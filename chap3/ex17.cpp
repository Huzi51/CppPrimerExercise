#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::string;

int main()
{
    vector<string> svec;
    string word;
    while (cin >> word) {
        svec.push_back(word);
    }
    for (auto &word : svec) {
        for (auto &c : word) {
            c = toupper(c);
        }
    }
    unsigned cnt = 0;
    for (auto &word : svec) {
        if (cnt % 8 == 0) {
            cout << endl;
            cnt = 0;
        }
        cout << word << " ";
        cnt ++;
    }
    cout << endl;
}