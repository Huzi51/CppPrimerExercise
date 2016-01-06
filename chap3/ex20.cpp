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

    for (decltype(ivec.size()) first = 0, second = 1;
         first < ivec.size(); first = second +1, second += 2) {
        if (second != ivec.size()) {
            cout << ivec[first] + ivec[second] << " ";
        } else {
            cout << ivec[first] << " ";
        }
    }
    return 0;
}