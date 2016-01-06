#ifndef MAKE_SHARED_HPP
#define MAKE_SHARED_HPP

#include <memory>
#include <utility>

template <typename T, typename... Args>
std::shared_ptr<T>
make_shared(Args&&... args)
{
    return new T(std::forward<Args>(args)...);
}
#endif
