#include <iostream>
#include <string>

std::string make_plural (size_t ctr, const std::string &word,
                         const std::string &endng = "s");

int main()
{
    std::string str = "ni hao";
    std::cout << make_plural (2, str) << std::endl;
    return 0;
}