#include <iostream>

int main()
{
    double dval = 3.14;
    const int &ri = dval;

    int &ri2 = dval; // error

    // cosnt int temp = dval;
    // const int &ri = temp;
}