#ifndef PRINTSTRING2_HPP
#define PRINTSTRING2_HPP

#include <string>
#include <iostream>

class PrintString2 {
public:
    PrintString2(std::istream &i = std::cin):
        in(i) { }
    std::string operator()() const {

        std::string s;
        if (getline(in, s)) {
            return s;
        } else {
            return std::string();
        }
    }
private:
    std::istream &in;
};
#endif