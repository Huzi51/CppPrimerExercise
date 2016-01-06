#include <iostream>
#include "arrayIter.hpp"

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    for (auto beg = begin(a); beg != end(a); ++beg) {
        std::cout << *beg << " ";
    }
    std::cout << std::endl;
}