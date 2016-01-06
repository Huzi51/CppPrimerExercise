#ifndef BLOB_HPP
#define BLOB_HPP

#include <memory>
#include <vector>
#include <string>
#include <stdexcept>
#include <utility>
#include <cstddef>
#include <iostream>

template<typename T> class BlobPtr;
template<typename T> class Blob;

template<typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template<typename T>
bool operator!=(const Blob<T>&, const Blob<T>&);

template<typename T>
class Blob {
    friend class BlobPtr<T>;
    friend bool operator==<T> (const Blob<T>&, const Blob<T>&);
    friend bool operator!=<T> (const Blob<T>&, const Blob<T>&);
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    // constructor
    Blob():
        data(std::make_shared<std::vector<T> >()) { }
    Blob(std::initializer_list<T> il):
        data(std::make_shared<std::vector<T> >(il)) { }
    template<typename It> Blob(It b, It e);

    size_type size() { return data->size(); }
    size_type size() const { return data->size(); }
    bool empty() { return data->empty(); }
    bool empty() const { return data->empty(); }

    T& operator[](size_type);
    const T& operator[](size_type) const;

    T& front();
    const T& front() const;

    T& back();
    const T& back() const;

    void push_back(const T&);
    void push_back(T&&);

    void pop_back();

    BlobPtr<T> begin();
    BlobPtr<T> end();

private:
    std::shared_ptr<std::vector<T> > data;
    void check(size_type i, const std::string &msg) const;
};

// Blob(It, It)
template <typename T>
template <typename It>
Blob<T>::Blob(It b, It e):
    data(std::make_shared<std::vector<T> >(b, e)) { }
// check
template<typename T>
inline void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= size()) {
        throw std::out_of_range(msg);
    }
}
// subscript
template<typename T>
inline T& Blob<T>::operator[](size_type i) {
    check(i, "subscript out of range");
    return (*data)[i];
}
template<typename T>
inline const T& Blob<T>::operator[](size_type i) const {
    check(i, "subscript out of range");
    return (*data)[i];
}
// front
template<typename T>
inline T& Blob<T>::front() {
    check(0, "front on empty Blob");
    return data->front();
}
template<typename T>
inline const T& Blob<T>::front() const {
    check(0, "front on empty Blob");
    return data->front();
}
// back
template<typename T>
inline T& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}
template<typename T>
inline const T& Blob<T>::back() const {
    check(0, "back on empty Blob");
    return data->back();
}

// push_back
template<typename T>
inline void Blob<T>::push_back(const T& elem) {
    data->push_back(elem);
}
template<typename T>
inline void Blob<T>::push_back(T&& elem) {
    data->push_back(std::move(elem));
}

// pop_back
template<typename T>
inline void Blob<T>::pop_back() {
    check(0, "pop_back on the empty Blob");
    data->pop_back();
}
// operator==
template<typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
{
    if (lhs.size() != rhs.size()) {
        return false;
    }
    for (std::size_t i = 0; i != rhs.size(); i++) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}
template<typename T>
bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return !(rhs == lhs);
}
// operator<<
template<typename T>
std::ostream&
operator<<(std::ostream &os, const Blob<T> &blob)
{
    os << "< ";
    for (std::size_t i = 0; i != blob.size(); ++i) {
        os << blob[i] << " ";
    }
    os << " >";

    return os;
}

//class template BlobPtr
template<typename T>
class BlobPtr {
public:
    BlobPtr();
    BlobPtr(Blob<T> &a, std::size_t sz = 0):
        wptr(a.data), curr(sz) { }

    T& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    BlobPtr<T>& operator++();
    BlobPtr<T>& operator--();

    BlobPtr<T> operator++(int);
    BlobPtr<T> operator--(int);

private:
    std::shared_ptr<std::vector<T> > check(std::size_t i, const std::string &msg) const;
    std::weak_ptr<std::vector<T> > wptr;
    std::size_t curr = 0;
};
// check
template<typename T>
inline std::shared_ptr<std::vector<T> >
BlobPtr<T>::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound BlobPtr");
    }
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
}
// prefix ++
template<typename T>
inline BlobPtr<T>& BlobPtr<T>::operator++() {
    check(curr, "increment past the end of BlobPtr");
    ++curr;
    return *this;
}
// postfix ++
template<typename T>
inline BlobPtr<T> BlobPtr<T>::operator++(int) {
    auto ret = *this;
    ++*this;
    return ret;
}

// prefix --
template<typename T>
inline BlobPtr<T>& BlobPtr<T>::operator--() {
    --curr;
    check(-1, "decrement past begin of BlobPtr");
    return *this;
}
// postfix --
template<typename T>
inline BlobPtr<T> BlobPtr<T>::operator--(int) {
    auto ret = *this;
    --*this;
    return ret;
}

// Blob<T>::begin()
template<typename T>
inline BlobPtr<T> Blob<T>::begin() {
    return BlobPtr<T>(data, 0);
}
// Blob<T>::end()
template<typename T>
inline BlobPtr<T> Blob<T>::end() {
    return BlobPtr<T>(data, size());
}
#endif