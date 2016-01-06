#include <iostream>
#include <stdexcept>
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Sales_item item1, item2;
    while (cin >> item1 >> item2) {
        try {
            if (item1.isbn() != item2.isbn()) {
                throw std::runtime_error("Data must refer to be same ISBN.");
            }
            cout << item1 + item2 << endl;
        } catch (std::runtime_error err) {
            cout << err.what()
                 << "\nTry again? Enter y or n: ";
            char c;
            cin >> c;
            if (!cin || c == 'n') {
                break;
            }
        }
    }
    return 0;
}