#include <random>
#include <iostream>

int main()
{
    std::default_random_engine e;
    std::uniform_int_distribution<int> u(0, 9);

    for (size_t i = 0; i != 10000; ++i)
    {
        std::cout << u(e) << " ";
    }
    std::cout << std::endl;
}