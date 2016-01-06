#include "chap6.hpp"

int main()
{
    int ia[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i = 0;
    print2 (&i, 1);
    print2 (ia, std::end(ia) - std::begin(ia));
    print3 (ia); // must pass a array of size 10
    return 0;
}