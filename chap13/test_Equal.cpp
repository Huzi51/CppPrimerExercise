#include <iostream>
#include <algorithm>
#include <vector>
#include "PrintString.hpp"
#include "Equal.hpp"

int main()
{
    std::vector<int> ivec{1, 2, 3, 6, 2, 2, 2};
    replace_if(ivec.begin(), ivec.end(), Equal(2), 3);
    for_each(ivec.begin(), ivec.end(),
             [](int i)
             { std::cout << i << " "; });
    std::cout << std::endl;
}