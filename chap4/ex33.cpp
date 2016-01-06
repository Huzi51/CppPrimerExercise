#include <iostream>

int main()
{
    int x = 0, y = 0;
    int somevalue;
    std::cin >> somevalue;

    somevalue ? ++x, ++y : --x, --y;
    std::cout << x << " " << y << std::endl;
    return 0;
}