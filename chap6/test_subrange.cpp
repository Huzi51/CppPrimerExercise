#include <iostream>
#include "chap6.hpp"
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string s1 = "hello";
    string s2 = "hello, world";

    if (str_subrange(s1, s2)) {
        cout << "subrange" << endl;
    }
    return 0;
}