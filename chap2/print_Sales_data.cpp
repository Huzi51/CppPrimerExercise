#include <iostream>
#include <string>
#include "Sales_data.hpp"

int main()
{
    Sales_data book;
    double price;
    std::cin >> book.bookNo >> book.units_sold >> price;
    book.revenue = book.units_sold * price;

    std::cout << book.bookNo << " "
              << book.units_sold << " "
              << book.revenue << " "
              << book.revenue / book.units_sold << std::endl;

    return 0;
}