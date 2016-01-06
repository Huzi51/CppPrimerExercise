#include <iostream>
#include <vector>
#include "chap6.hpp"
using std::vector;

typedef int (*Fun)(int, int);

int main()
{
    vector<Fun> Fvec{add, subtract, multiply, divide};
    for (auto fun : Fvec) {
        std::cout << fun(4, 2) << " ";
    }
    std::cout << std::endl;
    return 0;
}
