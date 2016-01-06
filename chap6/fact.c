#include "chap6.hpp"
int fact(int n)
{
    int value = 1;
    while (n > 1) {
        value *= n--;
    }
    return value;
}