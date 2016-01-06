#include <vector>
#include <string>
#include <iostream>

int main()
{
    std::vector<int> ivec;
    std::cout << *ivec.begin() << " "
              << ivec.front() << " "
              << ivec[0] << " "
              << ivec.at(0) << " " << std::endl;
    return 0;
}