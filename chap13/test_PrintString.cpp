#include <string>
#include <iostream>
#include "PrintString.hpp"

int main()
{
    PrintString ps(std::cout, '*');
    std::string s;
    while (std::cin >> s) {
        ps(s);
    }
    std::cout << std::endl;
}