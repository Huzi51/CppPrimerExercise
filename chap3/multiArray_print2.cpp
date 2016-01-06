#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int ma[3][4] = { // array of size 3, each elements is an array  of ints of size 4
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    for (auto &row : ma) {
        for (auto col : row) {
            cout << col << ' ';
        }
        cout << endl;
    }
    return 0;
}