#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;

using std::runtime_error;

int main()
{
    int a, b;
    while (cin >> a >> b) {
        try {
            if (b == 0) {
                throw runtime_error("divide zeor");
            }
            cout << "a/b = " << a/b << endl;
        } catch (runtime_error err) {
            cout << err.what()
                 << "\nTry Again? Enter y/n :";
            char rsp;
            cin >> rsp;
            if (!cin && rsp == 'n') {
                break;
            }
        }
    }
    return 0;
}