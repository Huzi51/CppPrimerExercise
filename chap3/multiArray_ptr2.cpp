#include <iostream>

int main()
{
    int ma[3][4] = { // array of size 3, each elements is an array  of ints of size 4
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}

    };
    for (auto p = ma; p != ma + 3; p++) { // p is pointer to an array of ints of size 4
        for (auto q = *p; q != *p + 4; q++) {
            std::cout << *q << " ";
        }
        std::cout << std::endl;
    }
}