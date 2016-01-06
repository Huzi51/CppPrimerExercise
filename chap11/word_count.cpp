#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>

using std::map;
using std::string;
using std::set;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    map<string, size_t> word_count;
    set<string> exclude = {"the", "but", "And", "or"};
    string word;
    while (cin >> word) {
        for (auto &c: word) {
            if (isupper(c)) {
                c = tolower(c);
            }
        }
        remove_if(word.begin(), word.end(),
                  [](char &c){ return ispunct(c); });
        if (exclude.find(word) == exclude.end()) {
            ++word_count[word];
        }
    }
    for (const auto &w : word_count) {
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? "times" : "time") << endl;
    }
}