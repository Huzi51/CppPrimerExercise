#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;
using std::size_t;

struct Serial {
    static size_t n;
    Serial(): sn(n++) { }
    Serial(const Serial &s): sn(n++) { }
   size_t sn;
};
size_t Serial::n = 0;

void f(constSerial s)
{
    cout << s.sn << endl;
}

int main()
{
    Serial a, b = a, c = b;
    f(a); f(b); f(c);
}