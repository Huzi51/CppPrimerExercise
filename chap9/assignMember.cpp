#include <iostream>
#include <string>
#include <list>
#include <vector>

int main()
{
    std::list<char*> clst = {"hello", "this", "terrible", "world"};
    std::vector<std::string> svec;
    svec.assign(clst.cbegin(), clst.cend());
    for (const auto &s : svec) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    return 0;
}