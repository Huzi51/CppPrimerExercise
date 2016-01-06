#include <iostream>
#include "chap6.hpp"

int main()
{
    int val = 0, val2 = 0;
    std::cin >> val >> val2;
    swap(&val, &val2);
    std::cout << val << " "
              << val2 << std::endl;
    return 0;
}