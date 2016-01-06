#include <iostream>
#include <list>

int main()
{
    std::list<int> ilst = {1,2,3,4,5};

    ilst.erase(ilst.end(), ilst.end());
    for (const auto &elem : ilst) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}