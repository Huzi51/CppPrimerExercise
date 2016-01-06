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

    for (int (*p)[4] = ma; p != ma + 3; p++) { // ma is pointer to array(type) of int of size 4
        for (int *q = *p; q != *p + 4; q++) {
            cout << *q << " ";
        }
        cout << endl;
    }
    return 0;
}