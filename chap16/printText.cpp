#include <vector>
#include <iostream>
#include "print.hpp"

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    print(a);

    std::vector<int> ivec = {1, 2, 3, 4, 5};
    printVec2(std::cout, ivec);
}