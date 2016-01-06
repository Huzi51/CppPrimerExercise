#ifndef EQUAL_HPP
#define EQUAL_HPP

class Equal {
public:
    Equal(int value = 0):
        criterion(value) { }
    bool operator()(int i) const {
        return i == criterion;
    }
private:
    int criterion;
};
#endif