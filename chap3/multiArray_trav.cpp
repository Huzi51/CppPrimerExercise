#include <iostream>

int main()
{
    int ma[2][4] = {};
    size_t cnt = 0;
    for (auto &row : ma) {
        for (auto &col : row) {
            col = cnt++;
        }
    }

    for (auto &row : ma) { // don't miss &
        for (auto col : row) {
            std::cout << col << " ";
        }
    }
    std::cout << std::endl;
}