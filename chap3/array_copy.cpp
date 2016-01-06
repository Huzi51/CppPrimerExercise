#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int main()
{
    char s1[] = "hello, ";
    char s2[] = "world!";
    char s3[14];
    char s4[14];
    strcat(s3, s1);
    strcat(s3, s2);

    strcpy(s4, s3);
    for (auto c : s3) {
        cout << c;
    }
    cout << endl;

    for (auto c : s4) {
        cout << c;
    }
    cout << endl;

}