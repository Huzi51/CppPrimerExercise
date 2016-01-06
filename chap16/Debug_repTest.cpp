#include <string>
#include <iostream>
#include "Debug_rep.hpp"

int main()
{
    std::string s("debug");
    std::cout << debug_rep(s) << std::endl;

    const std::string s2("Fuck");
    std::cout << debug_rep(s2) << std::endl;

    char p[] = "fuck gfw";
    std::cout << debug_rep(&p[0]) << std::endl;
}