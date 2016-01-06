#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 7};
    auto e = &arr[10];
    for (auto beg = arr; beg != e; beg++) {
        cout << *beg << " ";
    }
    cout << endl;
    return 0;
}