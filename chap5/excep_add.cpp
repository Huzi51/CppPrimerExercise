#include <iostream>
#include <stdexcept>
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Sales_item item1, item2;
    cin >> item1 >> item2;

    if (item1.isbn() != item2.isbn()) {
        throw std::runtime_error("Data must refer to same ISBN");
    }
    cout << item1 + item2 << endl;
    return 0;
}