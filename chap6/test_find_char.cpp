#include <iostream>
#include <string>
#include "chap6.hpp"

int main()
{
    std::string s{"hello, kitty"};
    char c = 'l';
    decltype(s.size()) occurs = 0;
    decltype(s.size()) pos = find_char (s, c, occurs);
    std::cout << "The letter " << c
              << " occurs " << occurs
              << " times " << " at position "
              << pos << std::endl;
    return 0;
}