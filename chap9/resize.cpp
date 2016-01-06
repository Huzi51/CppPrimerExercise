#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec(25);
    std::cout << ivec.size() << std::endl;
    ivec.resize(100);
    std::cout << ivec.size() << std::endl;
    ivec.resize(10);
    std::cout << ivec.size() << std::endl;
    return 0;
}