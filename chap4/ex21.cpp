#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> ivec{1,2,3,4,5,6,7};

    for (auto & i : ivec) {
        (i % 2 == 1) ? (i *= i) : i;
    }
    for (const auto i : ivec) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}