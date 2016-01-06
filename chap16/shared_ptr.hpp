#ifndef SHARED_PTR
#define SHARED_PTR

#include <cstddef>
#include <new>
#include <functional>
#include <stdexcept>

template<typename T>
class shared_ptr {
public:
    typedef std::function<void(T*)> Deleter;

    shared_ptr():
        ptr(nullptr), cnt(new std::size_t(1)) { }
    shared_ptr(T *p):
        ptr(p) ,cnt(new std::size_t(1)) { }
    shared_ptr(T *p, Deleter d):
        ptr(p), del(d), cnt(new std::size_t(1)) { }

    T& operator*();

    shared_ptr(const shared_ptr&);
    shared_ptr& operator=(const shared_ptr&);
    ~shared_ptr();
private:
    T *ptr;
    Deleter del;
    std::size_t *cnt;
};
// copy-constructor
template <typename T>
shared_ptr<T>::shared_ptr(const shared_ptr &rp):
    ptr(rp.ptr), del(rp.ptr), cnt(rp.cnt)
{
    ++*cnt;
}
// copy-assign
template <typename T>
shared_ptr<T>&
shared_ptr<T>::operator=(const shared_ptr &rp)
{
    if (ptr != rp.ptr) {
        if (--*cnt == 0) {
            del ? del(ptr) : delete ptr;
            delete cnt;
        }
        ++*rp.cnt;
        ptr = rp.ptr;
        del = rp.del;
        cnt = rp.cnt;
    }
}
// destructor
template <typename T>
shared_ptr<T>::~shared_ptr()
{
    if (--*cnt == 0) {
        del ? del(ptr) : delete ptr;
        delete cnt;
    }
}
// dereference
template <typename T>
T&
shared_ptr<T>::operator*()
{
    if (!ptr) {
        throw std::runtime_error("dereference on the empty pointer.");
    }
    return *ptr;
}
#endif