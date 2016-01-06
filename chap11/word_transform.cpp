#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using std::ifstream;
using std::cout;
using std::endl;
using std::istringstream;
using std::string;
using std::map;

map<string, string> buildMap(ifstream &);
const string transform(const map<string, string>&, const string&);

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);
    string text;
    while (getline(input, text)) {
        istringstream line(text);
        string word;

        while (line >> word) {
            cout << transform(trans_map, word) << " ";
        }
        cout << endl;
    }
}