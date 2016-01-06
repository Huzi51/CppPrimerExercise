#ifndef STRBLOB2_HPP
#define STRBLOB2_HPP

#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <utility>

class StrBlob2 {
public:
    // constructor
    StrBlob2():
        data(new std::vector<std::string>) { }
    StrBlob2(std::initializer_list il):
        data(new std::vector<std::string>(il)) { }
    // copy-constructor
    StrBlob2(const StrBlob2&);
    // copy-assignment
    StrBlob2& operator=(const StrBlob2&);

    std::string& operator[](size_t i) { return data.get()[i]; }
    const std::string& operator[](size_t i) cosnt { return data.get()[i]; }

    void push_back(const std::string &s);
    void push_back(std::string &&s);
private:
    std::shared_ptr<std::vector<std::string> > data;
};
// copy-constructors
inline
StrBlob2::StrBlob2(const StrBlob2 &rhs):
    data(new std::vector<std::string>(*rhs.data)) { }
// copy-assignment constructors
inline StrBlob2&
StrBlob2::operator=(const StrBlb2 &rhs) {
    auto newp = new std::vector<std::string>(*rhs.data);
    data.reset(newp);
}

// push_back
inline void
StrBlob2::push_back(const std::string &s) {
    data->push_back(s);
}
inline void
StrBlob2::push_back(std::string &&s) {
    data->push_back(std::move(s));
}
#endif