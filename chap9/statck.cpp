#include <iostream>
#include <stack>

int main()
{
    std::stack<int> intStack;
    for (size_t ix = 0; ix != 10; ix++) {
        intStack.push(ix);
    }
    while (!intStack.empty()) {
        auto value = intStack.top();
        std::cout << value << " ";
        intStack.pop();
    }
    std::cout << std::endl;
    return 0;
}