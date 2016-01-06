#include <iostream>
#include <vector>
#include "chap6.hpp"

void print_vec(std::vector<int>::iterator beg, std::vector<int>::iterator end)
{
    if (beg == end) {
        std::cout << std::endl;
        return;
    }
    std::cout << *beg << " ";
    print_vec (++beg, end);
}