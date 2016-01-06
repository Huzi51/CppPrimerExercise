#ifndef UNIQUE_PTR_HPP
#define UNIQUE_PTR_HPP

#include <memory>

template <typename T,
          typename Deleter = std::default_delete<T>
          > class unique_ptr
{
public:
    unique_ptr():
        uptr(nullptr) { }
    unique_ptr(Deleter d):
        uptr(nullptr), del(d) { }
    unique_ptr(T *p, Deleter d = std::default_delete<T>()):
        uptr(p), del(d) { }

    T* release() {
        auto ret = uptr;
        uptr = nullptr;
        return ret;
    }

    T* get() {
        return uptr;
    }
    ~unique_ptr() {
        del(uptr);
    }
private:
    T *uptr;
    Deleter del;
};
#endif