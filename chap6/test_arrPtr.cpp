#include <iostream>

int main()
{
    int ia[] = {1, 2, 3, 4};
    int (*p)[4] = &ia; // here ia is a array of size 4, not a pointer to first elements.
    for (auto elem : *p) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}