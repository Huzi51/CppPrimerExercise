#ifndef X_HPP
#define X_HPP

#include <iostream>
using std::cout;
using std::endl;

struct X {
    X() { cout << "X()" << endl;}
    X(const X &rhs): i(rhs.i) { cout << "X(const X&)" << endl;}
    X& operator=(const X &rhs) {
        i = rhs.i;
        cout << "operator=" << endl;
        return *this;
    }
    ~X() { cout << "~X()" << endl;}
    int i = 2;
};
#endif