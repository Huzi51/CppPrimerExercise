#include <iostream>
#include <vector>
#include <iterator>

int main()
{
    int ia[] = {1, 2, 3, 4, 5};
    std::vector<int> ivec(std::begin(ia), std::end(ia));
    for (auto i : ivec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    int ia2[5] = {};
    // copy ivec to ia2
    for (decltype(ivec.size()) index = 0;
         index < 5; index++) {
        ia2[index] = ivec[index];
    }

    // print ia2[6]
    for (auto i : ia2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}