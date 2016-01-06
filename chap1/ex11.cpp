#include <iostream>

int main()
{
    std::cout << "Enter two numbers: " << std::endl;
    int begin = 0, end = 0;
    std::cin >> begin >> end;
    if (begin > end) {
        int temp = begin;
        begin = end;
        end = temp;
    }
    while (begin <= end) {
        std::cout << begin << " ";
        begin++;
    }
    std::cout << std::endl;
    return 0;
}