#include <iostream>

template <typename T>
std::ostream&
print(std::ostream &os, const T &t);

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

int main()
{
    int i = 0; double d = 3.14; std::string s = "how now brown cow";
    print(std::cout, i, s, d) << std::endl;
}