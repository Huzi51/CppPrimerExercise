#include "unique_ptr.hpp"
#include "DebugDelete.hpp"

int main()
{
    unique_ptr<int> up;
    unique_ptr<int, DebugDelete> up2(new int(), DebugDelete());
}