#include <memory>
#include "DebugDelete.hpp"

int main()
{
    std::unique_ptr<int, DebugDelete> ip(new int(), DebugDelete());

    DebugDelete del;
    int *p = new int(2);
    del(p);
}