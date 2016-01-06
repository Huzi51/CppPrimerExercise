#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int main()
{
    constexpr int size = 10;
    int arr[size] = {1, 2, 3, 5, 7};
    for (auto beg = begin(arr); beg != end(arr); beg++) {
        *beg = 0;
    }
    return 0;
}