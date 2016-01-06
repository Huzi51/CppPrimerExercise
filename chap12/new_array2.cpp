#include <iostream>
#include <string>
#include <new>
#include <memory>

int main()
{
    std::string s;
    std::cin >> s;
    char *p = new char[s.size()];
    // std::unique_ptr<char[]> up(p);
    // for (std::size_t i = 0; i != s.size(); i++) {
    //     up[i] = s[i];
    // }
    // for (std::size_t i = 0; i != s.size(); i++) {
    //     std::cout << up[i];
    // }

    char *q = p;
    for (std::size_t i = 0; i != s.size(); i++) {
        *q++ = s[i];
    }
    q = p;
    while (q != p + s.size()) {
        std::cout << *q++;
    }
    std::cout << std::endl;
    delete [] p;
}