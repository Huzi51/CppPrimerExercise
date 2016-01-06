#ifndef MOVE_HPP
#define MOVE_HPP

#include <type_traits>

template <typaname T>
typename std::remove_reference<T>::type&&
move(T&& t)
{
    return static_cast<typename std::remove_reference<T>::type&&>(t);
}

#endif