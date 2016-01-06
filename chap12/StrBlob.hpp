#ifndef STRBLOB_HPP
#define STRBLOB_HPP

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <stdexcept>

class StrBlobPtr;
class StrBlob {
    friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
    // constructors
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);

    std::string front() const;
    std::string back() const;

    // modifier
    void push_back(const std::string&);
    void pop_back();
    // StrBlobPtr
    StrBlobPtr begin();
    StrBlobPtr end();

private:
    void check(size_type, const std::string&) const;
    std::shared_ptr<std::vector<std::string> > data;
};
// check
void StrBlob::check(size_type i, const std::string &msg) const {
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
}
// constructors
inline
StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string> >()) { }
inline
StrBlob::StrBlob(std::initializer_list<std::string> il) :
    data(std::make_shared<std::vector<std::string> >(il)) { }
// front , back
inline
std::string StrBlob::front() const {
    check(0, "front on the empty StrBlob");
    return data->front();
}
inline
std::string StrBlob::back() const {
    check(0, "back on the empty StrBlob");
    return data->back();
}
// modifer
inline
void StrBlob::push_back(const std::string &s) {
    data->push_back(s);
}
inline
void StrBlob::pop_back() {
    check(0, "pop_back on the empty StrBlob");
    data->pop_back();
}

// StrBlobPtr
class StrBlobPtr {
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
public:
    // constructors
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob &a, std::size_t sz = 0):
        wptr(a.data), curr(sz) { }

    // operator++
    StrBlobPtr& operator++(); // prefix
    StrBlobPtr operator++(int); // postfix
    // operator--
    StrBlobPtr& operator--(); // prefix
    StrBlobPtr operator--(int); // postfix

    // arithmetic
    StrBlobPtr operator+(size_t) const;
    StrBlobPtr operator-(size_t) const;
    int operator-(const StrBlobPtr&) const;
    // operator[]
    std::string& operator[](size_t i){
        check(i, "out of range");
        auto sp = wptr.lock();
        return sp.get()[i];
    }
    // dereference
    std::string& operator*() const {
        auto sp = check(curr, "dereference past end");
        return (*sp)[i];
    }
    // arrow
    std::string* operator->() const {
        return &this->operator*();
    }
    const std::string operator[](size_t) const {
        auto sp = check(i, "out of range");
        return (*sp)[i];
    }
private:
    std::shared_ptr<std::vector<std::string> > check(std::size_t i, const std::string &msg) const;
    std::weak_ptr<std::vector<std::string> > wptr;
    std::size_t curr;
};
// check
inline std::shared_ptr<std::vector<std::string> >
StrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}
// deref(*)
inline
std::string &StrBlobPtr::deref() {
    auto it = check(0, "deref on empty StrBlob");
    return (*it)[curr];
}
// incr(++)
inline
StrBlobPtr &StrBlobPtr::incr() {
    check(curr, "increment out of range");
    ++curr;
    return *this;
}

// StrBlob::begin()
inline
StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}
// StrBlob::end()
inline
StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}
// eq
inline
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto lp = lhs.wptr.lock(), rp = rhs.wptr.lock();
    if (lp == rp) {
        return (!lp || lhs.curr == rhs.curr);
    } else {
        return false;
    }
}
inline
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs==rhs);
}

// prefix ++
inline StrBlobPtr&
StrBlobPtr::operator++() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
// postfix ++
inline StrBlobPtr
StrBlobPtr::operator++(int) {
    auto ret = *this;
    ++*this;
    return ret;
}
// prefix --
inline StrBlobPtr&
StrBlobPtr::operator--() {
    --curr;
    check(-1, "decrement past begin of StrBlobPtr");
    return *this;
}
// postfix --
inline StrBlobPtr
StrBlobPtr::operator--(int) {
    auto ret = *this;
    --*this;
    return ret;
}
// arithmetic
StrBlobPtr
StrBlobPtr::operator+(size_t i) const {
    auto ret = *this;
    ret.curr += i;
    check(ret.curr, "out of range");
    return ret;
}
StrBlobPtr
StrBlobPtr::operator-(size_t i) const {
    auto ret = *this;
    ret.curr -= i;
    check(-1, "out of range");
    return ret;
}

int
StrBlobPtr::operator-(const StrBlobPtr &rhs) const {
    return this->curr - rhs.curr;
}
#endif