#include <iostream>

int main()
{
    int sum = 0;
    for (int value = -100; value <= 100; ++value) {
        sum += value;
    }
    std::cout << "The sum of -100 to 100 is " << sum
              << std::endl;
    return 0;
}