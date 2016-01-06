#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(int argc, char *argv[])
{
    std::ifstream in;
    in.open(argv[1]);
    std::vector<std::string> svec;
    std::string line;
    if (!in.is_open()) {
        std::cout << "open file fail" << std::endl;
    }
    while (getline(in, line)) {
        svec.push_back(line);
    }
    for (const auto &s : svec) {
        std::cout << s << std::endl;
    }
    return 0;
}