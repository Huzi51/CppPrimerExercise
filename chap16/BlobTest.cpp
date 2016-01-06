#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "Blob.hpp"

int main()
{
    Blob<int> ib = {1, 2, 3, 4, 5, 6};
    std::cout << ib << std::endl;

    Blob<std::string> ib2 = {"Fuck", "GFW"};
    std::cout << ib2 << std::endl;

    std::string array[] = {"Fuck", "GFWGFW"};
    Blob<std::string> ib3(std::begin(array), std::end(array));
    std::cout << ib3 << std::endl;
}