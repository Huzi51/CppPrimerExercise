#include <iostream>

template <typename T> void f(T);
template <typename T> void f(const T*);

template <typename T> void g(T);
template <typename T> void g(T*);

int main()
{
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;

    g(42); g(p); g(ci); g(p2);
    f(42); f(p); f(ci); f(p2);
}

template <typename T> void f(T t)
{
    std::cout << "f(T)" << std::endl;
}

template <typename T> void f(const T* t)
{
    std::cout << "f(const T*)" << std::endl;
}

template <typename T> void g(T t)
{
    std::cout << "g(T)" << std::endl;
}

template <typename T> void g(T* t)
{
    std::cout << "g(T*)" << std::endl;
}