#include <iostream>
#include <vector>
#include "find.hpp"

int main()
{
    std::vector<int> ivec{1, 2, 3, 4, 5};
    auto it = find(ivec.begin(), ivec.end(), 5);
    if (it != ivec.end()) {
        std::cout << *it << std::endl;
    }
}