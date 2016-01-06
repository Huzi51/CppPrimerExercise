#ifndef HASPTR2_HPP
#define HASPTR2_HPP

#include <string>
#include <cstddef>

class HasPtr2 {
public:
    HasPtr2(const std::string &s = std::string()):
        ps(new std::string(s)), i(0), cnt(new std::size_t(1)) { }
    HasPtr2(const HasPtr2 &rhs):
        ps(rhs.ps), i(rhs.i), cnt(rhs.cnt) { ++*cnt; }
    HasPtr2& operator=(const HasPtr2 &rhs);
    ~HasPtr2();
private:
    std::string *ps;
    std::size_t i;
    std::size_t *cnt;
};

// copy-assignment constructors
inline HasPtr2&
HasPtr2::operator=(const HasPtr2 &rhs) {
    ++*rhs.cnt;
    if (--*cnt == 0) {
        delete ps;
        delete cnt;
    }
    ps = rhs.ps;
    i = rhs.i;
    cnt = rhs.cnt;

    return *this;
}

// destructor
inline
HasPtr2::~HasPtr2() {
    if (--*cnt == 0) {
        delete ps;
        delete cnt;
    }
}
#endif