#ifndef INBOUND_HPP
#define INBOUND_HPP

#include <cstddef>
class inBound {
public:
    inBound(std::size_t l, std::size_t u):
        lower(l), upper(u) { }
    bool operator()(std::string &s) const {
        return s.size() >= lower && s.size() < upper; // [lower, upper)
    }
private:
    std::size_t lower;
    std::size_t upper;
};
#endif