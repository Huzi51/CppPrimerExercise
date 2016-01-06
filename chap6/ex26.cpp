#include "chap6.hpp"

int main(int argc, char *argv[])
{
    for (size_t index = 1; index != argc; index++) {
        print_cstring (argv[index]);
    }
    return 0;
}