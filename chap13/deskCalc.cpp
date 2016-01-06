#include <function>
using std::minus;
#include <map>
using std::map;
#include <string>
using std::string;

int add(int i, int j) { return i + j; }
auto mod = [](int i, int j) { return i % j; };
struct div {
    int operator()(int denominator, int divisor) {
        return denominator / divisor;
    }
};

int main()
{
    map<string, std::function<int(int, int)> > binops = {
        {"+", add},
        {"-", minus()},
        {"*", [](int i, int j) { return i * j; } },
        {"/", div()},
        {"%", mod}
    }
}