#include <new>
#include <iostream>

int main()
{
    char s[] = "hello";
    char s2[] = "world";
    std::size_t n = sizeof(s)/sizeof(s[0]) + sizeof(s2)/sizeof(s2[0]);
    char *p = new char[n];
    char *q = p;
    for (std::size_t i = 0; s[i] != '\0'; i++) {
        *q++ = s[i];
    }
    *q++ = ' ';
    for (std::size_t i = 0; s2[i] != '\0'; i++) {
        *q++ = s2[i];
    }
    *q = '\0';
    q = p;
    while (q != p + n) {
        std::cout << *q++;
    }
    std::cout << std::endl;
    delete [] p;
}