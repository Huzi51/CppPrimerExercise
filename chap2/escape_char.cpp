#include <iostream>

int main()
{
    std::cout << "Hi \x4dO\115!\n";
    std::cout << '\115' << '\n';
    std::cout << "\12345" << '\n';
    std::cout << "\x1234" << '\n';

    return 0;
}