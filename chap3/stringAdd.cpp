#include <iostream>
#include <string>

using std::string;

int main()
{
    string s1 = "hello", s2 = "world";

    string s4 = s1 + " ,";
    string s5 = "hello" + ", ";
    string s6 = s1 + ", " + "hello";
    string s7 = "hello" + ", ", + s1;
}