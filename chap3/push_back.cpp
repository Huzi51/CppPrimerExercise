#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

int main()
{
    vector<int> ivec;
    int value;
    while (cin >> value) {
        ivec.push_back(value);
    }
    for (auto i : ivec) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}