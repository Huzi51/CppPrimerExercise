#ifndef STRING_HPP
#define STRING_HPP

#include <memory>
#include <iterator>
#include <utility>
#include <iostream>

class String {
public:
    String():
        elements(nullptr), first_free(nullptr), cap(nullptr) { }
    String(const char str[], size_t cnt):
        elements(alloc.allocate(cnt)),
        first_free(elements + cnt),
        cap(first_free) { std::uninitialized_copy_n(str, cnt, elements); }

    String(const String&); // copy-constructor
    String(String&&);

    String& operator=(const String&); // copy-assignment
    String& operator=(String&&);

    char& operator[](size_t i) { return elements[i]; }
    cosnt char& operator[](size_t) { return elements[i]; }

    ~String(); // destructor

    char* begin() const { return elements; }
    char* end() const { return first_free; }

    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }

    void push_back(const char&);
    void push_back(char &&);
private:
    std::allocator<char> alloc;
    char *elements;
    char *first_free;
    char *cap;

    void check_n_alloc();
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void free();
    void reallocate();
};
// copy-constructor
inline
String::String(const String &rhs) {
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
    std::cout << "String(const String&)" << std::endl; // debug
}
// move-constructor
inline
String::String(String &&rhs):
    elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap) {

    rhs.elements = rhs.first_free = rhs.cap = nullptr;
    std::cout <<"String(String&&)" << std::endl;
}
// copy-assignment
inline String&
String::operator=(const String &rhs) {
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
    return *this;
    std::cout << "copy-assignment" << std::endl; // debug
}
// move-assignment
inline String&
String::operator=(String &&rhs) {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}
// destructor
inline
String::~String() { free(); }
// push_back
inline void
String::push_back(const char &s) {
    check_n_alloc();
    alloc.construct(first_free++, s);
}
inline void
String::push_back(char &&s) {
    check_n_alloc();
    alloc.construct(first_free++, std::move(s));
}


// check_n_alloc
inline void
String::check_n_alloc() {
    if (size() == capacity()) {
        reallocate();
    }
}
// alloc_n_copy
inline std::pair<char*, char*>
String::alloc_n_copy(const char *b, const char *e) {
    auto newElem = alloc.allocate( e - b );
    return {newElem, std::uninitialized_copy(b, e, newElem)};
}
// free
inline void
String::free() {
    if (elements) {
        for (auto p = first_free; p != elements; ) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

// reallocate
inline void
String::reallocate() {
    auto newcapacity = size() ? 2*size() : 1;
    auto newElem = alloc.allocate(newcapacity);

    auto dest = newElem;
    auto elem = elements;
    for (size_t i = 0; i != size(); i++) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newElem;
    first_free = dest;
    cap = elements + newcapacity;
}
#endif