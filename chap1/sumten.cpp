#include <iostream>

int main()
{
    int value = 0, sum = 0;
    while (value <= 10) {
        sum += value;
        value++;
    }
    std::cout << "The sum of one to ten inclusive is " << sum << std::endl;
    return 0;
}