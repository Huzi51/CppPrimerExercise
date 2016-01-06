#ifndef HASPTR_HPP
#define HASPTR_HPP

#include <string>
using std::string;

// valuelike
class HasPtr {
    HasPtr(const string &s = string()):
        ps(new string(s)), i(0) { }
    HasPtr(HasPtr&);
    HasPtr& operator=(const HasPtr&);
    ~HasPtr() { delete ps; }
private:
    string *ps;
    int i;
};
// copy constructors
inline
HasPtr::HasPtr(const HasPtr &rhs) :
    ps(new string(*rhs.ps)), i(rhs.i) { }
// copy-assignment operator
inline
HasPtr& HasPtr::operator=(const HasPtr&rhs) {
    auto newp = new string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
}

#enfif