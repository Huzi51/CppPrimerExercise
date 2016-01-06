#include <iostream>

using std::cout;
using std::endl;

// archLinux-i386
int main()
{
    cout << "char: " << sizeof(int) << endl;
    cout << "wchar_t: " << sizeof(wchar_t) << endl;
    cout << "char16_t: " << sizeof(char16_t) << endl;
    cout << "char32_t: " << sizeof(char32_t) << endl;
    cout << "unsigned char: " << sizeof(unsigned char) << endl;
    cout << "signed char: " << sizeof(signed char) << endl;
    cout << endl;

    cout << "bool: " << sizeof(bool) << endl;
    cout << "short: " << sizeof(short) << endl;
    cout << "int: " << sizeof(int) << endl;
    cout << "unsigned: " << sizeof(unsigned) << endl;
    cout << "long: " << sizeof(long) << endl;
    cout << "long long: " << sizeof(long long) << endl;
    cout << endl;

    cout << "float: " << sizeof(float) << endl;
    cout << "double: " << sizeof(double) << endl;
    cout << "long double: " << sizeof(long double) << endl;
    cout << endl;

    cout << "pointer: " << sizeof(nullptr) << endl;
    cout << endl;
}