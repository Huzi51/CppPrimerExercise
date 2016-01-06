#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

int main()
{
    vector<int> ivec{0, 1, 3};
    auto it = ivec.begin() + 10;
    auto distance = it - ivec.begin();
    if (it == ivec.end()) {
        cout << " it at end of ivec." << endl;
    }
    cout << distance << endl;
    return 0;
}