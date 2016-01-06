#include <iostream>

int main()
{
    unsigned u = 11;
    while (u > 0) {
        --u;
        std::cout << u << std::endl;
    }
    return 0;
}