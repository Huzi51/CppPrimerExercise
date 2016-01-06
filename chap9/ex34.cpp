#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec{2, 2, 2, 2, 2, 6};
    auto it = ivec.begin();
    while(it != ivec.end()) {
        if (*it % 2) {
            it = ivec.insert(it, *it);
        }
        ++it;
    }
    for (const auto &i : ivec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}