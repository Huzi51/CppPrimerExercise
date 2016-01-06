#ifndef IF_ELSE_H
#define IF_ELSE_H

struct If_else {
    int operator()(int cond , int value1, int value2) {
        return cond ? value1 : value2;
    }
};
#endif