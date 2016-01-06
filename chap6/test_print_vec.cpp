#include <vector>
#include "chap6.hpp"

int main()
{
    std::vector<int> ivec{1, 2, 3, 4, 5};
    print_vec (ivec.begin(), ivec.end());
    return 0;
}