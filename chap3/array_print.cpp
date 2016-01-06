#include <iostream>

using std::cout;
using std::endl;

int main()
{
    const char arr[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    const char *cp = arr;
    while (*cp) {
        cout << *cp << endl;
        ++cp;
    }
}