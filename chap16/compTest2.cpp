#include <iostream>
#include <string>
#include "compare.hpp"

int main()
{
    // compare("fuck", "GFW");

    const char *p1 = "fuck", *p2 = "GFW";

    std::cout << compare(p1, p2) << std::endl;
    std::cout << compare("Fuck", "GFW") << std::endl;;
}