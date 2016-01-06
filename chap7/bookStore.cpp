#include <iostream>
#include <string>
#include "Sales_data.hpp"
using std::cerr;

int main()
{
    Sales_data total;
    if (std::cin >> total) {
        Sales_data trans;
        while (std::cin >> trans) {
            if (trans.isbn() == total.isbn()) {
                total += trans;
            } else {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    } else {
        cerr << "No data!?" << std::endl;
    }
    return 0;
}