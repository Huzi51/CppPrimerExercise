#include "X.hpp"
#include <memory>
#include <new>

X f(X x) { return x; }
X f2(X &x) { return x; }
X& f3(X &x) { return x; }
int main()
{
     X value;
    // X value2(value);
    // X value3 = value2;
    // std::shared_ptr<X> sp(new X);
    // X *xp = new X();
    // delete xp;
    //f(value);
    // f2(value);
     f3(value);
}