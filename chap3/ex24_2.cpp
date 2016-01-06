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

    auto beg = ivec.begin(), last = ivec.end() - 1;
    for ( ;beg != last; ++beg, --last) {
        cout << *beg + *last << " ";
    }
    if (beg == last) {
        cout << *beg << " ";
    }
    cout << endl;
    return 0;
}