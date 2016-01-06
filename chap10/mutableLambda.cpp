#include <iostream>

int main()
{
    int val = 6;
    auto f = [&val] () -> bool {
        if (!val) return val == 0;
        while (val) --val;
        return val == 0;
    };
    std::cout << f() << std::endl;
    std::cout << val << std::endl;
}