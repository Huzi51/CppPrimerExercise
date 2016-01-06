#ifndef DEBUG_REP_HPP
#define DEBUG_REP_HPP

#include <sstream>
#include <string>
// declare
template <typename T> std::string debug_rep(const T&);
template <typename T> std::string debug_rep(T*);
// std::string debug_rep(const std::string &);
// std::string debug_rep(char *p);
// std::string debug_rep(const char *p);


template <typename T>
std::string
debug_rep(const T &t)
{
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T>
std::string
debug_rep(T *p)
{
    std::ostringstream ret;
    ret << "pointer: " << p;
    if (p) {
        ret << " " << debug_rep(*p);
    } else {
        ret << "Null Pointer.";
    }
    return ret.str();
}

// specialization verson replace overloaded version for debug_rep(char *p)
template <>
std::string
debug_rep(char *p)
{
    return debug_rep(std::string(p));
}
template <>
std::string
debug_rep(const char *p)
{
    return debug_rep(std::string(p));
}


// // nontemplate debug_rep
// std::string
// debug_rep(const std::string &s)
// {
//     return '"' + s + '"';
// }

// // nontemplate handle character pointers as string
// std::string
// debug_rep(char *p)
// {
//     return debug_rep(std::string(p));
// }
// std::string
// debug_rep(const char *p)
// {
//     return debug_rep(std::string(p));
// }
#endif