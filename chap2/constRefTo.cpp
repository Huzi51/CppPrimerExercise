#include <iostream>

int main()
{
    int i = 42;
    const int &r1 = i;
    const int &r2 = 42;  // ok
    const int &r3 = r1 * 2; // ok
    int &r4 = r * 2; // error
}