#include <iostream>
#include <fstream>
#include <string>
#include "StrBlob.hpp"


int main(int argc, char *argv[])
{
    std::ifstream in(argv[1]);
    StrBlob b;
    std::string line;
    while (getline(in, line)) {
        b.push_back(line);
    }
    for (StrBlobPtr p = b.begin(); !eq(p, b.end()); p.incr()) {
        std::cout << p.deref() << " ";
    }
    std::cout << std::endl;
}