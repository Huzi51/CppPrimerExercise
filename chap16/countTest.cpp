#include <vector>
#include <iostream>
#include "countTemp.hpp"

int main()
{
    std::vector<int> ivec = {1, 2, 3, 3, 3, 4, 5};
    std::cout << count(ivec, 3) << std::endl;

    char *p1 = "fuck";
    char *p2 = "gfw";
    const char *p3 = "gfw";

    std::vector<const char*> cvec = {p1, p2, p3};
    std::cout << count(cvec, p3) << std::endl;
}