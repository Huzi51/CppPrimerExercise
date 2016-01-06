#include <iostream>
using std::cout;
using std::endl;

int main()
{
    constexpr size_t array_size = 10;
    size_t arr[array_size];
    size_t arr2[array_size];
    for (size_t i = 0; i < array_size; i++) {
        arr[i] = i;
    }

    for (size_t i = 0; i < array_size; i++) {
        arr2[i] = arr[i];
    }

    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}