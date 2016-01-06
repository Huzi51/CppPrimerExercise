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
    vector<string> text;
    for (auto it = text.begin();
         it != text.end() && !isspace(*it); ++it) {
        for (auto letter_it = it->begin();
             letter_it != it->end(); letter_it++) {
            *letter_it = toupper(*letter_it);
        }
    }
}