#include <string>
#include <iostream>
#include "Sales_data.hpp"

int main()
{
    std::string s = "1-2-5";
    //Sales_data item = s;
    //Sales_data item2 = std::cin;
    Sales_data item3;
    item3.combine(s);
    return 0;
}