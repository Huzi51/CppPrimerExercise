#ifndef FIND_HPP
#define FIND_HPP

template<typename InputIt, typename T>
InputIt find(InputIt first, InputIt last, T value)
{
    while (first != last && *first != value) {
        ++first;
    }
    return first;
}
#endif