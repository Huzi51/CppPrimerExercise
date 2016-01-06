#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

int main()
{
    vector<unsigned> grade_clut(11, 0);
    unsigned grade;
    while (cin >> grade) {
        if (grade <= 100) {
            ++grade_clut[grade / 10];
        }
    }
    for (const auto cnt : grade_clut) {
        cout << cnt << " ";
    }
    cout << endl;
    return 0;
}