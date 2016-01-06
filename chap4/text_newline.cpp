#include <iostream>
#include <vector>
#include <string>


int main()
{
    std::vector<std::string> text;

    for (const auto &s : text) {
        if (s.empty() || s[s.size() - 1] == ".") {
            std::cout << std::endl;
        } else {
            cout << " ";
        }
    }
    return 0;
}