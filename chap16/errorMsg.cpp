#include <iostream>
#include <string>
#include "Debug_rep.hpp"

// nonVaradic template to end Varadic function recursion
template <typename T>
std::ostream&
print(std::ostream&, const T &t);

// Varadic template print
template <typename T, typename... Args>
std::ostream&
print(std::ostream&, const T &t, const Args&... rest);

// pack expantion pattern
template <typename... Args>
std::ostream&
errorMsg(std::ostream &os, const Args&... rest)
{
    return print(os, debug_rep(rest)...);
}

int main()
{
    errorMsg(std::cout, std::string("error"), std::string("error2"), std::string("error3"));
    std::cout << std::endl;
}

template <typename T, typename... Args>
std::ostream&
print(std::ostream &os, const T &t, const Args& ... rest)
{
    os << t << ", ";
    print(os, rest...);
    return os;
}

// functin to end recursion
template <typename T>
std::ostream&
print(std::ostream &os, const T &t)
{
    os << t;
    return os;
}