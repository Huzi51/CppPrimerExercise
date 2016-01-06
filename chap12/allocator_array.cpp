#include <iostream>
#include <string>
#include <memory>

int main()
{
    std::string s = "Fuck";
    std::string s2 = "GFW";
    std::allocator<char> ac;
    auto p = ac.allocate(s.size() + s2.size());

    char *s_end = uninitialized_copy(s.begin(), s.end(), p);
    char *p_end = uninitialized_copy(s2.begin(), s2.end(), s_end);

    char *beg = p;
    while (beg != p_end) {
        std::cout << *beg++;
    }
    std::cout << std::endl;

    // destruction
    for (auto b = p; b != p_end; b++) {
        ac.destroy(b);
    }
    // deallocation
    ac.deallocate(p, s.size() + s2.size());
}