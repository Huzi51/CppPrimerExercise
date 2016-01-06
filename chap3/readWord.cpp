#include <iostream>
#include <string>

using std::cin;
using std::endl;
using std::cout;
using std::string;

int main()
{
    string word;
    cout << "Read Word" << endl;
    while(cin >> word) {
        cout << word;
    }
    cout << endl;
    return 0;
}