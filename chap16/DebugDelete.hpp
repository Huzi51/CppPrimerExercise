#ifndef DEBUG_DELETE_HPP
#define DEBUG_DELETE_HPP

#include <iostream>

class DebugDelete {
public:
    // constructor
    DebugDelete(std::ostream &s = std::cerr): os(s) { }

    template <typename T>
    void operator()(T *p) {
        os << "deleting ptr" << std::endl;
        delete p; }
private:
    std::ostream &os;
};
#endif