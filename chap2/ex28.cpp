#include <iostream>

int main()
{
    int i, *const cp;
    int *p1, *const p2;
    const int ic, &r = ic;
    const int *const p3;
    const int *p;

    p1 = p3;
    p1 = &ic;
}