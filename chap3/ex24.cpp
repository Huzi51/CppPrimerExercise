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

    for (auto first = ivec.begin(), second = ivec.begin() + 1;
         ivec.end() - first > 0; first = second + 1, second = first + 1) {
        if (second != ivec.end()) {
            cout << *first + *second << " ";
        } else {
            cout << *first << " ";
        }
    }
    cout << endl;
    return 0;
}