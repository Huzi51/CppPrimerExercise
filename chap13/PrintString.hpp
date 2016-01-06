#ifndef PRINTSTRING_HPP
#define PRINTSTRING_HPP

#include <string>
#include <iostream>
class PrintString {
public:
    PrintString(std::ostream &o = std::cout, const char &c = ' '):
        os(o), sep(c) { }
    void operator()(const std::string &s) const {
        os << s << sep;
    }
private:
    std::ostream &os;
    char sep;
};
#endif