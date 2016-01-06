#include "TextQuery.hpp"
#include <iostream>
#include <fstream>
#include <string>

void runQuery(std::ifstream&);
int main(int argc, char *argv[])
{
    std::ifstream input(argv[1]);
    runQuery(input);
}

void runQuery (std::ifstream &input)
{
    TextQuery tq(input);
    while (true) {
        std::cout << "Please Enter word you want query: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") {
            break;
        }
        print (std::cout, tq.query(s));
    }
}