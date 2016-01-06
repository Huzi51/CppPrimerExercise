#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    auto p1 = array, p2 = &array[3];
    p1 += p2 - p1;
    cout << *p1 << endl;
    return 0;
}