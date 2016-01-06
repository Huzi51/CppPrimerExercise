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

    for (size_t row_i = 0; row_i < 3; row_i++) {
        for (size_t col_i = 0; col_i < 4; col_i++) {
            cout << ma[row_i][col_i] << " ";
        }
        cout << endl;
    }
}