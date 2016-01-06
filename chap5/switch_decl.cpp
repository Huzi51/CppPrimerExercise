#include <iostream>
#include <vector>
using std::vector;

int main()
{
    unsigned index = 0;
    vector<int> ivec{1, 2, 3};
    switch (index) {
    case 1:
        int ix = 2;
        ivec[ix] = index;
        break;
    default:
        ix = ivec.size() - 1;
        ivec[ix] = index;
    }
}