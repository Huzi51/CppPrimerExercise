#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;

using std::runtime_error;

int main()
{
    int a, c;
    cin >> a >> c;
    if (c == 0) {
        throw runtime_error("divide zero!!");
    }
    cout << a / c << endl;
    return 0;
}