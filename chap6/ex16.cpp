#include <iostream>
#include <string>
#include "chap6.hpp"

int main()
{
    const std::string s = "hello";
    if (is_empty(s)) {
        std::cout << "Empty string" << std::endl;
    }
    return 0;
}