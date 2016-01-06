#include <iostream>

int main()
{
    int errNumb = 0;
    int *const curerr = &errNumb;
    const double pi = 3.14159;
    const double *const pip = &pi;

    double d = 4.555;
    const double *p = &d;
}