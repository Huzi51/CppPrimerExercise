#include <iostream>

int count_calls()
{
    static int cnt = 0;
    cnt++;
    return cnt;
}

int main()
{
    for (size_t i = 0; i != 10; i++) {
        std::cout << count_calls() << std::endl;
    }
    return 0;
}