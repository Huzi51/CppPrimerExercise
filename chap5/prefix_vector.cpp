#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

int main()
{
    vector<int> ivec{0,1,1,2};
    vector<int> ivec2{0,1,1,2,3,4,5};
    decltype(ivec.size()) end = ivec.size() > ivec2.size() ? ivec2.size() : ivec.size();
    decltype(ivec.size()) index = 0;
    for (; index < end && ivec[index] == ivec2[index]; index++) {
        ;
    }
    if (index == end) {
        cout << (ivec.size() > ivec2.size() ? "ivec2 " : "ivec ")
             << "is a prefix of another vector." << endl;
    }
}