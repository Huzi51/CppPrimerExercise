#include "String.hpp"
#include <vector>

int main()
{
    std::vector<String> Svec;
    Svec.push_back(String("hello", 6));
    Svec.push_back(String("world", 6));
}