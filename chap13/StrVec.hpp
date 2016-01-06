#ifndef STRVEC_HPP
#define STRVEC_HPP

#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
#include <algorithm>
#include <stdexcept>

class StrVec {
    friend bool operator==(const StrVec&, const StrVec&);
    friend bool operator!=(const StrVec&, const StrVec&);
    friend bool operator<(const StrVec&, const StrVec&);
public:
    StrVec(): // default constructor;
        elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(std::initializer_list<std::string> il):
        elements(alloc.allocate(il.size() ) ),
        first_free(elements + il.size()),
        cap(first_free) {

        std::uninitialized_copy(il.begin(), il.end(), elements);
    }

    StrVec(const StrVec&);
    StrVec(StrVec&&);

    StrVec& operator=(const StrVec&);
    StrVec& operator=(StrVec&&);
    StrVec& operator=(std::initializer_list<std::string> il);

    std::string& operator[](size_t);
    const std::string& operator[](size_t) const;

    ~StrVec();

    size_t size() const { return first_free - elements; }
    size_t capacity() const  { return cap - elements; }
    std::string* begin() const { return elements; }
    std::string* end() const { return first_free; }

    void push_back(const std::string&);
    void push_back(std::string&&);

    // chap16.4
    template <typename... Args>
    void emplace_back(Args&&... args);

    void reserve(size_t new_cap);

    void resize(size_t count);
private:
    std::allocator<std::string> alloc;
    std::string *elements;
    std::string *first_free;
    std::string *cap;

    std::pair<std::string*, std::string*> alloc_n_copy
        (const std::string*, const std::string*);
    void free();
    void check_n_alloc(){
        if ( size() == capacity()) reallocate();
    }
    void reallocate();
};
// alloc_n_copy
inline std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    auto lct = alloc.allocate( b - e );
    auto end = std::uninitialized_copy(b, e, lct);
    return {lct, end};
}

// free
void
StrVec::free() {
    if (elements) {
        for_each(begin(), end(),
                 [=](std::string p) { alloc.destroy(&p); });
        alloc.deallocate(elements, cap - elements);
    }
}
// copy-constructor
StrVec::StrVec(const StrVec &rhs) {
    auto sp = alloc_n_copy(rhs.begin(), rhs.end());
    elements = sp.first;
    first_free = cap = sp.second;
}
// move-constructor
StrVec::StrVec(StrVec &&rhs):
    elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap) {

    rhs.elements = rhs.first_free = rhs.cap = nullptr;
}
// move-assignment
StrVec&
StrVec::operator=(StrVec &&rhs) {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}
// copy-assignment
StrVec&
StrVec::operator=(const StrVec &rhs) {
    auto ps = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = ps.first;
    first_free = cap = ps.second;
    return *this;
}
// assignment
StrVec&
StrVec::operator=(std::initializer_list<std::string> il) {
    auto newElem = alloc_n_copy(il.begin(), il.end());
    free();
    elements = newElem.first;
    first_free = cap = newElem.second;
    return *this;
}
// destructor
StrVec::~StrVec() {
    free();
}

// push_back
inline void
StrVec::push_back(const std::string &s) {
    check_n_alloc();
    alloc.construct(first_free++, s);
}
inline void
StrVec::push_back(std::string &&s) {
    check_n_alloc();
    alloc.construct(first_free++, std::move(s));
}

// emplace_back chap16.4
template <typename... Args>
void StrVec::emplace_back(Args&&... args)
{
    check_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(args)...);
}
// reallocate
inline void
StrVec::reallocate() {
    size_t newcapacity = size() ? 2*size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); i++) {
        alloc.construct (dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}
// reserve
inline void
StrVec::reserve(size_t new_cap) {
    if ( new_cap > capacity() ) {
        reallocate();
    }
}
// resize
inline void
StrVec::resize(size_t count) {
    if ( count < size() ) {
        for ( auto p = elements + count; p != first_free; p++ ) {
            alloc.destroy(p);
        }
    }

    if ( count > size() ) {
        for (size_t i = 0; i != count - size(); i++) {
            push_back(" ");
        }
    }
}
// operator==
bool operator==(const StrVec &lhs, const StrVec &rhs) {
    if (lhs.size() == rhs.size()) {
        for (auto b1 = lhs.begin(), b2 = lhs.begin();
             b1 != lhs.end() && *b1 == *b2;
             ++b1, ++b2) { ; }
        if (b1 == lhs.end()) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}
// operator!=
bool operator!=(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs == rhs);
}
// operator<
bool operator<(const StrVec &lhs, const StrVec &rhs) {
    if (lhs == rhs) {
        return false;
    } else if(lhs.size() == rhs.size()) {
        auto lb = lhs.begin(), rb = rhs.begin();
        while (*lb++ == *rb++) {
            ;
        }
        return *lb < *rb;
    } else if(lhs.size() > rhs.size()) {
        auto lb = lhs.begin(), rb = rhs.begin();
        while (rb != rhs.end() && *lb == *rb) {
            ++lb; ++rb;
        }
        if (rb == rhs.end()) {
            return false;
        } else {
            return *lb < *rb;
        }
    } else if(lhs.size() < rhs.size()) {
        auto lb = lhs.begin(), rb = rhs.begin();
        while (lb != lhs.end() && *lb == *rb ) {
            ++lb; ++rb;
        }
        if (lb == lhs.end()) {
            return true;
        } else {
            return *lb < *rb;
        }
    }
}
// operator[]
inline std::string&
StrVec::operator[](size_t i) {
    return *(elements + i);
}
inline const std::string&
StrVec::operator[](size_t i) const {
    return *(elements + i);
}
#endif