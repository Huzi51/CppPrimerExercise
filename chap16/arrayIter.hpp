#ifndef ARRAY_ITER_HPP
#define ARRAY_ITER_HPP

template<typename T, unsigned N>
T* begin(T (&a)[N])
{
    return &a[0];
}

template<typename T, unsigned N>
T* end(T (&a)[N])
{
    return &a[N];
}

template<typename T, unsigned N>
constexp unsigned size(T (&a)[N])
{
    return N;
}
#endif