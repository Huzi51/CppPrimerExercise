#include <iostream>
int &get(int *arr, int index)
{
    return arr[index];
}

int main()
{
    int ia[10];
    for (int i = 0; i != 10; ++i) {
        get(ia, i) = i;
    }
    for (auto &elem : ia) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}