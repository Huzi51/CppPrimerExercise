#include <iostream>
#include "shared_ptr.hpp"
#include "DebugDelete.hpp"

int main()
{
    shared_ptr<int> sp(new int(10), DebugDelete());
    std::cout << *sp << std::endl;
}