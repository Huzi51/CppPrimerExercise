#include <iostream>

int abs(int);
int main()
{
    int n;
    std::cin >> n;
    std::cout << "absolute of " << n << " is " << abs(n) << std::endl;
}