#include <iostream>
#include <string>

using std::cin;
using std::endl;
using std::cout;
using std::string;

int main()
{
    string line;

    cout << "Input a line: " << endl;
    while(getline(cin, line)) {
        if (!line.empty()) {
            cout << line << endl;
        }
    }
   return 0;
}