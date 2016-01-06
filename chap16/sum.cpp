#include <iostream>

template <typename T>
auto sum(T a, T b) -> decltype(a+b) // guarant that the return type is large enough to hold the sum;
{
    return a + b;
}

int main()
{
    std::cout << sum(1, 2) << std::endl;
}