#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


int main()
{
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto beg = ivec.begin(), end = ivec.end();
    auto mid = ivec.begin() + (end - beg) / 2;
    int sought = 9;
    while (beg != end && (*mid) != sought) {
        if (sought > *mid) {
            beg = mid + 1;
        } else {
            end = mid; // not end = mid - 1;
        }
        mid = beg + (end - beg) / 2;
    }
    if (*mid == sought) {
        cout << sought << " is in " << "ivec" << endl;
    }
    return 0;
}