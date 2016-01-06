#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string s;
    for (size_t index = 1; index != argc; index++) {
        s += argv[index];
    }
    std::cout << s << std::endl;
    return 0;
}