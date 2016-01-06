#include <iostream>

int main()
{
    unsigned u1 = 42, u2 = 10, test = -32;
    std::cout << "u1 - u2 = ";
    std::cout << u1 - u2 << std::endl;
    std::cout << "u2 - u1 = ";
    std::cout << u2 - u1 << std::endl;

    std::cout << test << std::endl;

    unsigned u3 = 10;
    int i = -1;
    std::cout << i + u3 << std::endl; // Why print 0?
    return 0;
}