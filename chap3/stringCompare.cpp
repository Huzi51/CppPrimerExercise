#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

int main()
{
    string line, line2;
    getline(cin, line);
    getline(cin, line2);

    if (line == line2) {
        cout << "Equal" << endl;
    } else {
        if (line > line2) {
            cout << "line longer than line2" << endl;
        } else {
            cout << "line2 longer than line" << endl;
        }
    }
    return 0;
}