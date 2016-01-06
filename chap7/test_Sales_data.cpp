#include "Sales_data.hpp"
#include <string>
#include <unordered_set>
#include <iostream>

int main()
{
    std::unordered_multiset<Sales_data> S;
    Sales_data item;
    while (std::cin >> item) {
        S.insert(item);
    }

    for (auto &s : S) {
        std::cout << s << std::endl;
    }
    std::cout << std::endl;
}