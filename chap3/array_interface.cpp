#include <iostream>
#include <string>

int main()
{
    std::string s("c-style-string");
    const char *cs = s.c_str();
    for (size_t i = 0; i < s.size(); i++) {
        std::cout << cs[i];
    }
    std::cout << std::endl;
}