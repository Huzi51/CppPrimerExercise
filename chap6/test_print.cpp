#include "chap6.hpp"
#include <iterator>

int main()
{
    int s[] = {1,2,3,4,5};
    print (std::begin(s), std::end(s));
    return 0;
}