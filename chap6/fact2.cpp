#include <iostream>

int fact(int);

int fact2(void)
{
    std::cout << "Please a number :";
    int n;
    std::cin >> n;
    std::cout << "factorial of " << n << " is " << fact(n) << std::endl;
    return 0;
}