#ifndef HASPTR3_HPP
#define HASPTR3_HPP

#include <iostream>
#include <string>
#include <algorithm>

// valuelike, swap
class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &rhs):
        ps(new std::string(*rhs.ps)), i(rhs.i) { }
    HasPtr(HasPtr &&rhs):
        ps(rhs.ps), i(rhs.i) { rhs.ps = nullptr; }

    //move- and copy-assignment
    HasPtr& operator=(HasPtr rhs); // rhs is not reference
    bool operator<(const HasPtr &rhs) const;
    ~HasPtr() { delete ps; }
private:
    std::string *ps;
    int i;
};
// swap
inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "swap" << std::endl;
}
// copy,move -assignment
inline HasPtr&
HasPtr::operator=(HasPtr rhs) {
    swap(*this, rhs);
    return *this;
}
// operator<
inline bool
HasPtr::operator<(const HasPtr &rhs) const {
    return *this->ps < *rhs.ps;
}
#endif