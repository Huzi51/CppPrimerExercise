#include <iostream>
#include <forward_list>
#include <algorithm>

int main()
{
    std::forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    auto it = stable_partition(flst.begin(), flst.end(),
                               [](int i) { return i % 2 == 0; });

    for_each(it, flst.end(),
             [](int i) { std::cout << i << " "; });
    std::cout << std::endl;
}