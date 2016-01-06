#include <iostream>

int main()
{
    int sum = 0, value = 0;
    std::cout << "Please enter your numbers to add: " << std::endl;
    // read until end-of-file
    while(std::cin >> value) {
        sum += value;
    }
    std::cout << "The summation of above number is " << sum
              << std::endl;
}