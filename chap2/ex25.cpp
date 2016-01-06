#include <iostream>

int main()
{
    int *ip, &r = ip; // error
    int i, *ip = 0;
}