#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

int main()
{
    vector<int> ivec;
    int n;
    while (cin >> n) {
        ivec.push_back(n);
    }
    for (decltype(ivec.size()) first = 0, last = ivec.size() - 1;
         first <= last; ++first, --last) {
        if (first == last) {
            cout << ivec[first] << " ";
        } else {
            cout << ivec[first] + ivec[last] << " ";
        }
    }
    cout << endl;
    return 0;
}