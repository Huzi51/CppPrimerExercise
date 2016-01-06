#include <iostream>
#include "Sales_data2.hpp"

int main()
{
    Sales_data item;
    Sales_data item1("1-2-3");
    Sales_data item2("1-2-3", 2, 30);
    Sales_data item3(std::cin);
    print (std::cout, item) << std::endl;
    print (std::cout, item1) << std::endl;
    print (std::cout, item2) << std::endl;
    print (std::cout, item3) << std::endl;
    return 0;
}