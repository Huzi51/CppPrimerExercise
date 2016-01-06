#include <iostream>

int main()
{
    int sum = 0;
    for (int value = 0; value <= 10; value ++) {
        sum += value;
    }
    std::cout << "The sum of 1 to 10 inclusive is " << sum
              << std::endl;
    return 0;
}