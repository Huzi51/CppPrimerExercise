#include <iostream>

int main()
{
    unsigned u = 10, u2 = 42;
    std::cout << "u - u2 = ";
    std::cout << u - u2 << std::endl;

    std::cout << "u2 - u = ";
    std::cout << u2 -u << std::endl;

    int i = 10, i2 = 42;
    std::cout << "i - i2 = ";
    std::cout << i - i2 << std::endl;

    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;
    return 0;
}