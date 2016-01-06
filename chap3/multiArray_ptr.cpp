#include <iostream>

int main()
{
    int ma[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    /* don't miss &, ma[2] is a array of int of size 4*/
    int (*p)[4] = &ma[2];
    /* don't miss * before p, p is a pointer to array of int of size 4 */
    for (auto beg = *p; beg != std::end(*p); ++beg) {
        std::cout << *beg << " ";
    }
    std::cout << std::endl;
    return 0;
}