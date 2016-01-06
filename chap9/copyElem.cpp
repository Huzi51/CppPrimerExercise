#include <vector>
#include <iostream>
#include <list>
#include <iterator>

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    std::vector<int> ivec(std::begin(ia), std::end(ia));
    std::list<int> ilst;
    ilst.assign(ivec.begin(), ivec.end());

    auto it = ivec.begin();
    while (it != ivec.end()) {
        if (*it % 2) {
            it++;
        } else {
            it = ivec.erase(it);
        }
    }
    for (const auto &odd : ivec) {
        std::cout << odd << " ";
    }
    std::cout << std::endl;

    auto it2 = ilst.begin();
    while (it2 != ilst.end()) {
        if (*it2 % 2) {
            it2 = ilst.erase(it2);
        } else {
            it2++;
        }
    }

    for (const auto &even : ilst) {
        std::cout << even << " ";
    }
    std::cout << std::endl;
    return 0;
}