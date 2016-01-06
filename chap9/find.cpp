#include <vector>

bool find (std::vector<int>::iterator beg,
           std::vector<int>::iterator end, int n)
{
    while (beg != end && *beg++ == n) {
        ;
    }
    if (beg != end) {
        return true;
    }
    return false;
}