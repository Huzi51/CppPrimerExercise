#include <iostream>
#include <cassert>
#include "flip.hpp"

void f(int v1, int &v2)
{
    std::cout << v1 << " " << ++v2 << std::endl;
}

void g(int &&v1, int &v2)
{
    std::cout << v1 << " " << ++v2 << std::endl;
}
int main()
{
    int i = 1;

    flip(f, i, 42);

    assert(i == 2);

    flip(g, i, 42);
}