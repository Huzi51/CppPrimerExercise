#include <vector>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

using std::vector;
using std::string;
using std::ifstream;
using std::map;
using std::set;
using std::istringstream;

void readFile(vector<string>&, ifstream &);
void separateFile(vector<string>&, map<string, set<int> >&);
void query(string &, vector<string>&, map<string, set<int> >&);

int main(int argc, char *argv[])
{
    vector<string> file;
    ifstream input(argv[1]);
    readFile(file, input);

    map<string, set<int> > word_line;

    separateFile(file, word_line);

    std::cout << "Please input word that you query: ";
    string word;
    std::cin >> word;
    query(word, file, word_line);
}

// readFile
void readFile(vector<string> &f, ifstream &in)
{
    string line;
    while (getline(in, line)) {
        f.push_back(line);
    }
}

// separateFile
void separateFile(vector<string> &content, map<string, set<int> > &word_lnum)
{
    for (decltype(content.size()) lnum = 0; lnum != content.size(); ++lnum) {
        istringstream line(content[lnum]);
        string word;
        while (line >> word) {
            word_lnum[word].insert(lnum);
        }
    }
}

// query
void query(string &word, vector<string> &sv, map<string, set<int> > &m)
{
    auto p = m.find(word);
    if (p != m.end()) {
        std::cout << p->first << " occurs " << p->second.size()
                  << " times" << std::endl;
        for (auto beg = p->second.begin();
             beg != p->second.end(); beg++) {
            std::cout << "(" << *beg << ")" << sv[*beg] << std::endl;
        }
    }
}
